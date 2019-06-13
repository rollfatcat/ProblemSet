#include<bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;
const int MAXN=100;
int cost[MAXN][MAXN];
int from[MAXN], dis[MAXN];
int V, E, st;
struct EDGE{ int s,v; };
vector<EDGE> edge[MAXN];

struct compare{ bool operator()(EDGE &a,EDGE &b){ return a.v>b.v; } };

// Dijkstra(anti-minus edge)
void Dijkstra(){
  vector<bool> vis(V,0);
  priority_queue<EDGE,vector<EDGE>,compare> PQ;
  for(int i=0;i<V;i++)
    from[i]=-1, dis[i]=INF;
  int Vnum=V;
  dis[st]=0;
  PQ.push({st,0});
  while(!PQ.empty() and Vnum){
    EDGE now=PQ.top(); PQ.pop();
    if(vis[now.s]) continue;
    Vnum--;
    vis[now.s]=1;
    dis[now.s]=now.v;
    for(int i=0;i<edge[now.s].size();i++)
      if(!vis[edge[now.s][i].s] and edge[now.s][i].v+now.v<dis[edge[now.s][i].s]){
        from[ edge[now.s][i].s ]=now.s;
        PQ.push({edge[now.s][i].s,edge[now.s][i].v+now.v});
      }
  }
  // Output
  for(int i=0;i<V;i++)
    printf("%d ",dis[i]);
  puts("");
  for(int i=0;i<V;i++)
    printf("%d ",from[i]);
  puts("");
}

// Floyed-Warshall Main Function
void Floyed_Warshall(){
  memset(cost,0x3f,sizeof(cost));
  for(int i=0;i<V;i++)
    cost[i][i]=0;
  for(int a=0;a<V;a++)
    for(int i=0;i<edge[a].size();i++){
      int b=edge[a][i].s;
      int v=edge[a][i].v;
      cost[a][b]=min(cost[a][b],v);
    }
  // Floyed-Warshall Main Function
  for(int k=0;k<V;k++)
    for(int i=0;i<V;i++)
      for(int j=0;j<V;j++)
        cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
  // Output
  for(int i=0;i<V;i++)
    printf("%d ",cost[st][i]);
  puts("");
}
int main(){
  // 假設 N<=100
  while(cin>>V>>E>>st){
    for(int i=0;i<V;i++)
      edge[i].clear();
    // Adjancy List
    int a, b, v;
    for(int i=0;i<E;i++)
      cin>>a>>b>>v,
      edge[a].push_back({b,v});

    //Floyed_Warshall();
    Dijkstra();
  }
}