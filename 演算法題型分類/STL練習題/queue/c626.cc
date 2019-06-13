// 貪食蛇遊戲模擬(不可穿牆)，類似於NPSC的g015，差異於吃到食物當下從尾端長出點(head保留)
// 用 CircularArr 模擬 Queue，不能直接用 Queue 是因為要比較點和『蛇的身體』所有的點座標有沒有重複
#include<bits/stdc++.h>
using namespace std;

string maze[15];
vector<int> DIR;
vector<int> step;

int Qx[350];
int Qy[350];
int mv[4]={1,-1,0,0};

inline int CharToDIR(char ch){
  if(ch=='S')  return 0;
  if(ch=='N')  return 1;
  if(ch=='W')  return 2;
  if(ch=='E')  return 3;
}
int main(){
  // 讀取輸入
  for(int i=0;i<15;i++)
    cin>>maze[i];
  char ch; int num;
  while(cin>>ch)
    DIR.push_back(CharToDIR(ch)),
    cin>>num, step.push_back(num);
  maze[0][0]='o';

  // 過程模擬
  bool live=true;
  int head=0, tail=0;
  Qy[head]=Qx[head]=0;
  for(int i=0;i<DIR.size() and live;i++){
    int nowD=DIR[i];
    for(int j=0;j<step[i];j++){
      // 根據方向計算測試點的座標
      int posx=Qx[tail]+mv[ nowD ],
          posy=Qy[tail]+mv[3-nowD];

      // 輸出現在的座標和對應的字元
      // printf("(%d %d) is %c\n",posx,posy,maze[posx][posy]);

      // 偵測有沒有超過邊界 或是 撞到障礙物
      if(0>posx or posx>=15 or 0>posy or posy>=21 or maze[posx][posy]=='x')
        live=0;
      // 偵測有沒有和身體發生碰撞
      for(int k=tail;k!=head;k=(k)?(k-1):349)
        if(posx==Qx[k] and posy==Qy[k])
          live=0;
      if(posx==Qx[head] and posy==Qy[head])
        live=0;
      // 以上碰撞偵測若成立時，生命狀態歸零就立刻跳出迴圈
      if(live==0) break;

      // 吃到食物時，食物消失(更改對應的字元)且保留尾端的點
      // 若格子是一般道路則把現在格子座標納入身體且尾端的座標丟掉(head++)
      if(maze[posx][posy]=='$')
        maze[posx][posy]='o';
      else
        head=(head+1)%350;

      tail=(tail+1)%350,
      Qx[tail]=posx,
      Qy[tail]=posy;
    }
  }
  // 輸出
  for(int i=tail;i!=head;i=(i)?(i-1):349)
    printf("%d %d\n",Qy[i],Qx[i]);
  printf("%d %d\n",Qy[head],Qx[head]);
}