// DFS走祖譜樹(0.6s/1.7MB)
#include<bits/stdc++.h>
using namespace std;

const int MAXN=30001;
vector<int> Link[MAXN];
short nh[MAXN];
short pa[MAXN];

void DFS(int now,int depth){
  nh[now]=depth;
  for(int i=0;i<Link[now].size();i++)
    pa[ Link[now][i] ]=now,
    DFS(Link[now][i],depth+1);
}
int main(){
  int N, Q, u, v;
  scanf("%d %d",&N,&Q);
  for(u=1;u<=N;u++)
    for(pa[u]=u;scanf("%d",&v) and v;)
      Link[u].push_back(v);
  // 從根節點出發，找齊每個節點的高度和父節點
  DFS(1,0);
  while(Q--){
    scanf("%d %d",&u,&v);
    // 從高度較高的開始移動
    if(nh[u]>nh[v]) swap(u,v);

    // 沿著根節點走，走到和另一個點等高
    int path_u=0, path_v=0;
    while(nh[u]!=nh[v])
      path_v++,v=pa[v];
    // 沿著根節點走，走到和另一個點等高(假設他們在同一條路徑時，輸出後跳開)
    if(u==v){ printf("%d %d\n",u,path_v); continue; }
    // 兩個節點分散在不同的子樹，各自往根節點各走一步直到他們遇到時
    while(u!=v)
      u=pa[u], path_u++,
      v=pa[v], path_v++;
    printf("%d %d\n",u,path_u+path_v);
  }
}
/*
7 6
2 3 0
4 5 0
6 7 0
0
0
0
0
4 5
4 2
4 4
4 3
1 7
2 3
*/