// 超難模擬題, 用Circular Queue模擬
// 用陣列把蛇的每一格座標、食物座標、指令以及要印出畫面的時間記錄起來，然後用迴圈一秒一秒計算它的變化即可
// 要注意的是吃到食物是下一秒才會增長。每一格座標可以用環狀佇列來記錄，這樣就不用一直複製它們的座標到下一格。

#include<iostream>
using namespace std;

struct Node{ int x, y; }food[400], nxt, head, tail;
int SSToDir(string ss){
  if(ss[0]=='u')  return 0;
  if(ss[0]=='l')  return 1;
  if(ss[0]=='d')  return 2;
  if(ss[0]=='r')  return 3;
}
int main(){
  int M, N, K;
  int actD[10001], actT[10001], T[1001];
  Node Q[1000];
  string ss;

  while(cin>>M>>N>>K and M){
    // 輸入
    for(int i=0;i<M;i++)
      cin>>food[i].x>>food[i].y;
    for(int i=0;i<N;i++)
      cin>>ss>>actT[i],  actD[i]=SSToDir(ss);
    for(int i=0;i<K;i++)
      cin>>T[i];
    food[M].x=food[M].y=actT[N]=T[K]=0x7fffffff;
    // 初始化狀態
    for(int i=0;i<5;i++)
      Q[i].x=i+1, Q[i].y=10;
    int nowD=3, nowT=0, score=0, head=4, tail=0;
    bool live=true, eat=false;
    for(int idxK=0, idxF=0, idxA=0; live==true; nowT++){
      if(nowT==T[idxK])
        idxK++, cout<<(head-tail+1001)%1000<<" "<<score<<" ("<<Q[head].x<<','<<Q[head].y<<") ("<<Q[tail].x<<','<<Q[tail].y<<")\n";
      if(nowT==actT[idxA]){
        if((nowD+actD[idxA])%2==1) // 改變方向屬於現在方向的有效情況
          nowD=actD[idxA];
        idxA++;
      }
      // 根據現在方向產生的新點判斷是不是合法：踩到邊界
      if(nowD==0){
        nxt.x=Q[head].x, nxt.y=Q[head].y+1;
        if(nxt.y>20){ live=false; break; }
      } else if(nowD==1){
        nxt.x=Q[head].x-1, nxt.y=Q[head].y;
        if(nxt.x<1){ live=false; break; }
      } else if(nowD==2){
        nxt.x=Q[head].x, nxt.y=Q[head].y-1;
        if(nxt.y<1){ live=false; break; }
      } else{
        nxt.x=Q[head].x+1, nxt.y=Q[head].y;
        if(nxt.x>40){ live=false; break; }
      }
      // 判斷蛇有沒有撞到身體=新點和Queue裡面的位置重疊
      for(int it=tail; it!=head; it=(it+1)%1000)
        if(nxt.x==Q[it].x and nxt.y==Q[it].y){  live=false; break;  }
      if(live==0) break;
      // 新點加到開頭的位置
      head=(head+1)%1000, Q[head]=nxt;
      // 如果有吃到食物, 把狀態改為沒吃, 且這一回合不需要做POP
      if(eat) eat=false;
      else  tail=(tail+1)%1000;
      // 判斷有沒有吃到食物? 有吃到食物到下一回才『長身體』,
      if(nxt.x==food[idxF].x and nxt.y==food[idxF].y)
        idxF++, score+=10, eat=true;
    }
    // nowT的時候出問題, 輸出時間要+1
    cout<<(nowT+1)<<' '<<(head-tail+1001)%1000<<' '<<score<<endl;
  }
}