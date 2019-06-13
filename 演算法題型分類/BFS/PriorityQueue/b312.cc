#include<bits/stdc++.h>
using namespace std;

const int MAXN=5001;
bool vis[MAXN];
int cost[MAXN];
struct ee{
  int n, v;
  bool operator<(const ee &rhs)const{ return v>rhs.v; }
};
vector<ee> edge[MAXN];
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int Nnode, Npath, st, ed;
  scanInt(Nnode),
  scanInt(Npath),
  scanInt(st), scanInt(ed);

  int a,b,v;
  for(int i=0;i<Npath;i++)
    scanInt(a),
    scanInt(b),
    scanInt(v),
    edge[a].push_back({b,v}),
    edge[b].push_back({a,v});
  // --- ---
  priority_queue<ee,vector<ee>> PQ;
  PQ.push({st,0});
  while(!PQ.empty()){
    ee now=PQ.top(); PQ.pop();
    if(vis[now.n])
      continue;
    vis[now.n]=1, cost[now.n]=now.v;
    if(now.n==ed)
      break;
    for(int i=0;i<edge[now.n].size();i++)
      if( !vis[ edge[now.n][i].n ] )
        PQ.push({edge[now.n][i].n, now.v+edge[now.n][i].v});
  }
  printf("%d\n",cost[ed]);
}
/*
7 9 1 7
1 2 2
1 4 3
2 5 2
2 3 3
3 4 4
3 6 1
5 6 3
4 7 5
6 7 1
*/