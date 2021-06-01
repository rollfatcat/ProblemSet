// Priority_Queue版本(44ms/1.3ms)
#include<bits/stdc++.h>
using namespace std;

const int INF=0x7fffffff;
struct EDGE{
  int s,v;
  bool operator<(const EDGE &rhs)const{ return v>rhs.v; }
};

inline bool scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); return c!=EOF; }
int main(){
  int V, E, Q;
  while(scanInt(V) and scanInt(E) and scanInt(Q) and V){
    // 初始化
    vector<int> edge[V+1];
    int cost[V+1][V+1];
    for(int i=1;i<=V;i++)
      for(int j=1;j<=V;j++)
        cost[i][j]=INF;
    // 地圖給的邊是無方向性的
    int a, b, v;
    for(int i=0;i<E;i++){
      scanInt(a),
      scanInt(b),
      scanInt(v);
      // 題目要求保留最新的資訊
      if(cost[a][b]==INF)
        edge[a].push_back(b),
        edge[b].push_back(a);
      cost[a][b]=cost[b][a]=v;
    }
    //
    priority_queue<EDGE,vector<EDGE>> PQ;
    PQ.push({1,0});
    vector<int> vis(V+1,0);
    vector<int> load(V+1,INF);
    load[1]=0;
    while(!PQ.empty()){
      EDGE now=PQ.top(); PQ.pop();
      if(vis[now.s])  continue;
      vis[now.s]=1;
      load[now.s]=now.v;
      if(now.v>Q or now.s==V) break;
      for(int i=0;i<edge[now.s].size();i++){
        int to=edge[now.s][i];
        if(cost[now.s][to]<=Q and vis[to]==0 and max(now.v,cost[now.s][to])<=load[to])
          PQ.push({to,max(now.v,cost[now.s][to])});
      }
    }
    puts((vis[V])?"Save":"GG");
  }
}