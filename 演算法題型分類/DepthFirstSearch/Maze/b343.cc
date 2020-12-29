// 模板題：DFS + Adjacency lists 練習
#include<bits/stdc++.h>
using namespace std;

const int MAXN=10001;
bool vis[MAXN];
short sumN;
vector<short>edge[MAXN];
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
void DFS(int now){
  sumN++, vis[now]=1;
  for(int i=0;i<edge[now].size();i++)
    if(!vis[ edge[now][i] ])
      DFS(edge[now][i]);
}
int main(){
  int T, Nnode, Nedge, Nst;
  for(scanInt(T); T--;){
    scanInt(Nnode),
    scanInt(Nedge),
    scanInt(Nst);
    for(int i=1;i<=Nnode;i++)
      edge[i].clear();
    for(int i=0,u,v;i<Nedge;i++)
      scanInt(u),
      scanInt(v),
      edge[u].push_back(v);
    memset(vis,0,sizeof(vis));
    sumN=0;
    for(int i=0,x;i<Nst;i++){
      scanInt(x);
      if(!vis[x])
        DFS(x);
    }
    printf("%d\n",sumN);
  }
}
/*
1
3 2 1
1 2
2 3
2
*/