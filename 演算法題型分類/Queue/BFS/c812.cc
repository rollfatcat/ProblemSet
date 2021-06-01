// BFS往外擴展，剪枝：當目前的值低於題目的限制時就不推入Queue
// N 最多是5000個
#include<bits/stdc++.h>
using namespace std;

struct EDGE{int n,v;} now;
int main(){
  int N, st, bound;
  scanf("%d %d %d",&N,&st,&bound);

  vector<EDGE> edge[N+1];
  int cnt=0, a, b, v;
  for(int i=1;i<N;i++)
    scanf("%d %d %d",&a,&b,&v),
    edge[a].push_back({b,v}),
    edge[b].push_back({a,v});

  vector<bool> vis(N+1,0);
  queue<EDGE> Q;
  Q.push({st,1<<30});
  while(!Q.empty()){
    now=Q.front(); Q.pop();
    if(vis[now.n]) continue;
    vis[now.n]=1;
    cnt++;
    for(int i=0;i<edge[now.n].size();i++)
      if(vis[ edge[now.n][i].n ]==0){
        int tmpv=min(now.v,edge[now.n][i].v);
        if(tmpv>=bound)
          Q.push({edge[now.n][i].n,tmpv});
      }
  }
  printf("%d\n",cnt-1);
}