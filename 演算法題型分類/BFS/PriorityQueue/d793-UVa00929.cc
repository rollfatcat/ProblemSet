// 練習如何寫 priotyQueue 裡面的compare函數和struct搭配
// 利用 Priorty Queue 做 lazy pop
#include<iostream>
#include<queue>
using namespace std;
#define MaxS 999
#define INF 0x7fffffff

short map[MaxS][MaxS];
int dis[MaxS][MaxS];
struct Node{ int x, y, d; } now, nxt;
struct compare{
  bool operator()(Node &a, Node &b){ return a.d>b.d; }
};
int main(){

  int T, N, M;
  int dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0};

  for(scanf("%d",&T); T--; ){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
      for(int j=0;j<M;j++)
        scanf("%hd",&map[i][j]), dis[i][j]=INF;

    priority_queue<Node,vector<Node>,compare> pq;
    now.x=now.y=0, now.d=map[0][0];
    pq.push(now);
    while(!pq.empty()){
      now=pq.top(), pq.pop();
      if(dis[now.x][now.y]<INF) continue;
      dis[now.x][now.y]=now.d; // 第一次更新的距離一定是最短距離
      if(now.x==N-1 and now.y==M-1) break;
      for(int i=0;i<4;i++){
        nxt.x=now.x+dx[i],  nxt.y=now.y+dy[i];
        if(0<=nxt.x and 0<=nxt.y and nxt.x<N and nxt.y<M and dis[nxt.x][nxt.y]==INF)
          nxt.d=now.d+map[nxt.x][nxt.y], pq.push(nxt);
      }
    }
    printf("%d\n",dis[N-1][M-1]);
  }
}