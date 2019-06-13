// 圖論-最短距離，PriorityQueue(暴力做法)
// 題目可能會給重複邊

#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+1; // 1 ≤ n,m ≤ 5e5
struct EDGE{
  int to, v;
  EDGE(int t=0,int v=0):to(t),v(v){}
  bool operator<(const EDGE &rhs)const{ return v>rhs.v; }
};
vector<EDGE> maze[MAXN];
bool vis[MAXN]={};
int main(){

  int from, to ,cost;
  int node_cnt, edge_cnt;
  scanf("%d %d",&node_cnt,&edge_cnt);
  while(edge_cnt--)
    scanf("%d %d %d",&from,&to,&cost),
    maze[from].push_back(EDGE(to,cost));
  priority_queue<EDGE,vector<EDGE>> PQ;
  PQ.push(EDGE(1,0));
  while(PQ.empty()==0){
    EDGE now=PQ.top(); PQ.pop();
    if(now.to==node_cnt){ printf("%d\n",now.v); break; }
    if(vis[now.to]) continue;
    for(EDGE to_node:maze[now.to])
      if(vis[to_node.to]==0)
        PQ.push(EDGE(to_node.to,now.v+to_node.v));
  }
}
/*
4 5
1 3 1
2 4 2
1 2 2
3 4 2
2 4 1
*/