// Tarjar's algorithm 的離線查詢(必須先把所有的Query紀錄起來，且不支援修改)
/* (0.3s/19.6MB) 主要是因為記憶體耗費在事先把查詢的要求存起來
 * 算法視覺教學：https://blog.csdn.net/jarjingx/article/details/8183240
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=30001;
vector<int> Link[MAXN];
struct PAIR{
  int u, v;
  PAIR(int a=0,int b=0):u(a),v(b){}
};
vector<PAIR> QA[MAXN];
vector<PAIR> ans;
int dp[MAXN]={};
int pa[MAXN]={};
int vis[MAXN]={};

inline int find_parent(int x){ return (pa[x]==x)?x:pa[x]=find_parent(pa[x]); }
inline void joint(int x, int y){ x=find_parent(x), y=find_parent(y), pa[x]=y; }
/* Tarjar's algorithm(注意執行的順序：詢問)
 * 運用 DFS 遍歷順序，配合 Disjoint-sets Forest，把已經拜訪過的點，
 * 依照層級聚合起來，方便找到 LCA( joint的執行順序放到最後 )。
 */
void Query_Offline(int now,int depth,int co_pa=0){
  // 標記深度(從根節點到該點的距離)/拜訪的狀態
  dp[now]=depth, vis[now]=1;
  // 根據目前的資訊更新查詢，唯有查詢的另個點也拜訪過
  for(int i=0;i<QA[now].size();i++){
    PAIR nowQ=QA[now][i];
    if(vis[nowQ.v]) //當另一個點已經展開過的時候才會找到 co_pa
      co_pa=find_parent(nowQ.v),
      ans[nowQ.u]=PAIR( co_pa,dp[now]+dp[nowQ.v]-(dp[co_pa]<<1) );
  }
  for(int i=0;i<Link[now].size();i++)
    Query_Offline(Link[now][i],depth+1),
    joint(Link[now][i],now);

}
int main(){
  int N, Q, u, v;
  scanf("%d %d",&N,&Q);
  ans.resize(Q,PAIR());
  for(u=1;u<=N;u++){
    pa[u]=u;
    while(scanf("%d",&v) and v)
      Link[u].push_back(v);
  }
  for(int i=0;i<Q;i++)
    scanf("%d %d",&u,&v),
    QA[u].push_back( PAIR(i,v) ),
    QA[v].push_back( PAIR(i,u) );
  // 輸入的人的編號必為１-Ｎ，而兒女編號必大於父母本身的編號 => No.１必定是根節點
  // 從 Root 出發，深度的計算方式指的是從 Root 到達該點的距離
  Query_Offline(1,0);
  puts("");
  for(int i=1;i<=N;i++)
    printf("%d %d\n",pa[i],dp[i]);
  //for(int i=0;i<Q;i++)
    //printf("%d %d\n",ans[i].u,ans[i].v);
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