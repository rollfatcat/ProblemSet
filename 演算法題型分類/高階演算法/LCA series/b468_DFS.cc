// 題解：https://blog.csdn.net/cww97/article/details/52258432
// 解法：Kruskal+LCA(一般DFS即可，遍歷過程無法使用tarjar算法)
#include<bits/stdc++.h>
using namespace std;

const int MAXN=10001;
const int MAXM=50001;
const int MAXQ=30001;
const int INF=1<<30;
struct EDGE{
  int u, v, w;
  bool operator<(const EDGE &rhs)const{ return w>rhs.w; }
} edge[MAXM];
struct PAIR{
  int u, w;
  PAIR(int a=0,int b=INF):u(a),w(b){}
}Route[MAXN];
int pa[MAXN];
int rt[MAXN];
int nh[MAXN];
bool vis[MAXN];
vector<PAIR> Link[MAXN];
vector<int> menu;

inline int find_parent(int x){ return (pa[x]==x)?x:pa[x]=find_parent(pa[x]); }
void DFS(int now,int depth){
  menu.push_back(now),
  nh[now]=depth,
  vis[now]=1;
  for(auto nowP:Link[now])
    if(vis[ nowP.u ]==0)
      Route[nowP.u]=PAIR(now,nowP.w),
      DFS(nowP.u,depth+1);
}
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int N, M, Q;
  scanInt(N);
  scanInt(M);
  for(int i=0;i<M;i++)
    scanInt(edge[i].u),
    scanInt(edge[i].v),
    scanInt(edge[i].w);
  // Kruskal
  sort(edge,edge+M);
  for(int i=1;i<=N;i++)
    pa[i]=i;
  int fu, fv, pick=1; // 只要構成『最大生成樹』的N-1條邊就可以跳開
  for(EDGE now:edge){
    int fu=find_parent(now.u),
        fv=find_parent(now.v);
    if(fu==fv) continue;
    (fu>fv)? pa[fu]=fv: pa[fu]=fv;// 指向號碼小的當父節點
    Link[now.u].push_back( PAIR(now.v,now.w) ),
    Link[now.v].push_back( PAIR(now.u,now.w) );
    if(++pick==N) break;
  }
  // DFS拜訪所有的樹群確定找到高度(題目不保證所有點都可以互聯)
  for(int i=1;i<=N;i++)
    if(vis[i]==0){
      menu.clear(),
      Route[i]=PAIR(i),
      DFS(i,0);
      for(auto x:menu)
        rt[x]=i;
    }
  // 查詢
  scanInt(Q);
  for(int u,v; Q--;){
    scanInt(u),
    scanInt(v);
    // 兩點分屬於不同的樹(無法互通)，輸出-1
    if(rt[u]!=rt[v]){ puts("-1"); continue; }
    // 從高度高的出發直到兩點的高度相同
    if(nh[u]>nh[v]) swap(u,v);

    int cap_u=INF, cap_v=INF;
    while(nh[u]!=nh[v])
      cap_v=min(cap_v,Route[v].w), v=Route[v].u;
    // 沿著根節點走，走到和另一個點等高(假設他們在同一條路徑時，輸出後跳開)
    if(u==v){ printf("%d\n",cap_v); continue; }
    // 兩個節點分散在不同的子樹，各自往根節點各走一步直到他們遇到...
    while(u!=v)
      cap_u=min(cap_u,Route[u].w), u=Route[u].u,
      cap_v=min(cap_v,Route[v].w), v=Route[v].u;
    printf("%d\n",min(cap_u,cap_v));
  }
}
/*
4 3
1 2 4
2 3 3
3 1 1
3
1 3
1 4
1 3
*/