// 直接用 Priority Queue 來做 => 0.4s
// 題目規定移動方向只有向下和向右，這題可用 DP 解
#include<iostream>
#include<queue>
using namespace std;
#define MaxN 101
#define INF 0x7fffffff

struct Node{ int x, y, d; } now, nxt;
struct compare{ bool operator()(Node &a, Node &b){ return a.d>b.d; }  };
int main(){
  int r, c, map[MaxN][MaxN], dis[MaxN][MaxN];
  bool vis[MaxN][MaxN];

  for(int caseNum=1;cin>>r>>c;caseNum++){
    for(int i=0;i<r;i++)
      for(int j=0;j<c;j++)
        cin>>map[i][j], vis[i][j]=0, dis[i][j]=INF;
    priority_queue<Node,vector<Node>,compare> PQ;
    PQ.push({0,0,0});
    while(!PQ.empty()){
      now=PQ.top(), PQ.pop();
      if( now.x<0 or now.y<0 or now.x>=c or now.y>=r or vis[now.y][now.x] )
        continue;
      vis[now.y][now.x]=1;
      dis[now.y][now.x]=map[now.y][now.x]+now.d; // 第一次更新的距離一定是最短距離
      if(now.y==r and now.x==c) // 第一次更新的距離一定是最短距離, 只要找到終點就跳開
        break;
      PQ.push( {now.x+1,now.y,dis[now.y][now.x]} );
      PQ.push( {now.x,now.y+1,dis[now.y][now.x]} );
    }

    printf("Case #%d :\n%d\n",caseNum,dis[r-1][c-1]);
  }
}