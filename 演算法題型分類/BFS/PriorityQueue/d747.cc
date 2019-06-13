// A* algorithm = Heap(每次取出到達終點成本最低的)
/* 距離估計方式：
 * A* 演算法(每次取出到達終點成本最低的格子更新)
 * (1)曼哈頓距離：0.8s/20MB
 * 成本估計方式：從起點走到這格的步數＋這格到達終點的曼哈頓距離(無視障礙物)
 * (2) 加上斜率優化版本：0.1s/17MB
 * 斜率優化版本：將原本的估計成本乘以一個權重放大倍率後加上斜率乘積(與起點到終點的斜率差值越低越好)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1001;
const int MAXW=1000000; // <- 這個權重的設定是曼哈頓的比重較高，一樣時才會受到斜率影響
char mapss[MAXN][MAXN];
int CntMap[MAXN][MAXN];
struct NODE{
  short x, y;int DIS;
  NODE(short a=0,short b=0,int c=0):x(a),y(b),DIS(c){}
  bool operator<(const NODE &rhs)const{ return DIS>rhs.DIS; }
};
struct GRID{
  short x, y;
  GRID(short a=0,short b=0):x(a),y(b){}
}REC[MAXW];
int N, Ex, Ey, RecNum, dx2, dy2;
int mv[4]={1,-1,0,0};
/**/
inline int TaxicabDistance(int dx1,int dy1){ return abs(dx1*dy2-dx2*dy1)+(abs(dx1)+abs(dy1))*MAXW; }
inline void A_Star(int Sx,int Sy,int out=0){
  if(mapss[Sx][Sy]=='X' or mapss[Ex][Ey]=='X'){
    puts("ERROR"); return;
  }
  // init
  priority_queue<NODE,vector<NODE>> PQ;
  dx2=Sx-Ex,
  dy2=Sy-Ey;
  RecNum=0,
  PQ.push( NODE(Sx,Sy) );
  bool GetGoal=false;

  while(PQ.empty()==0){
    NODE nxt, now=PQ.top(); PQ.pop();
    REC[RecNum++]=GRID(now.x,now.y);
    if(now.x==Ex and now.y==Ey){ GetGoal=true; break; }
    for(int i=0;i<=3;i++){
      nxt.x=now.x+mv[ i ],
      nxt.y=now.y+mv[3-i];
      if(mapss[nxt.x][nxt.y]!='X' and (CntMap[nxt.x][nxt.y]>CntMap[now.x][now.y]+1 or CntMap[nxt.x][nxt.y]==0))
        CntMap[nxt.x][nxt.y]=CntMap[now.x][now.y]+1,
        nxt.DIS=CntMap[nxt.x][nxt.y]*MAXW+TaxicabDistance(nxt.x-Ex,nxt.y-Ey),
        PQ.push(nxt);
    }
  }
  // 根據有沒有走到終點輸出最短距離
  printf("%d\n",(GetGoal)?CntMap[Ex][Ey]:-1);
  // 清除使用過的格子，避免用 memset() 重新設定浪費時間
  for(int i=0;i<RecNum;i++)
    CntMap[REC[i].x][REC[i].y]=0;
  while(PQ.empty()==0)
    CntMap[PQ.top().x][PQ.top().y]=0,
    PQ.pop();
}
int main(){
  int Q, Sx, Sy;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++)
    scanf("%s",mapss[i]);
  for(int i=0;i<Q;i++)
    scanf("%d %d",&Sx,&Sy),
    scanf("%d %d",&Ex,&Ey),
    A_Star(Sx,Sy);
}
/*
12 2
XXXXXXXXXXXX
X..........X
X..........X
X..........X
X..........X
X..........X
X..........X
X..........X
X..........X
X..........X
X..........X
XXXXXXXXXXXX
6 6 3 3
2 1 10 10
*/