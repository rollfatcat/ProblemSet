// 將 LCA 轉為 RMQ 問題(0.3s/3.3MB)
// 說明文件：https://yzmduncan.iteye.com/blog/973032
/* 利用 DFS 遍歷整棵祖譜樹，把整個路徑上經過的點依序記錄起來(存到org[])
 * 路徑上所有的點當作 zkw 的葉節點建整棵樹
 * 查詢時需要先將兩個節點轉為路徑上的號碼(要注意查詢區間的左右邊界可能會相反)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=30001;
const int MAXM=1<<(__lg(MAXN)+1);
const int INF=1<<30;
vector<int> Link[MAXN];
struct NODE{
  int no, dp;
  NODE(int a=INF,int b=INF):no(a),dp(b){}
  bool operator<(const NODE &rhs)const{ return dp<rhs.dp; }
} zkw[MAXM<<2], org[MAXN<<1];
int PathNo[MAXN]; // PathNo[i]：將祖譜樹的號碼i轉為第一次出現在路徑上的節點編號
int node_OnPath, zkwM;

// 利用DFS遍歷整棵樹，把整條路徑上經過的點依序當作原始資料儲存
void DFS(int now,int depth){
  if(PathNo[now]==0)
    PathNo[now]=node_OnPath;
  org[node_OnPath++]=NODE(now,depth);
  for(int i=0;i<Link[now].size();i++)
    DFS(Link[now][i],depth+1),
    org[node_OnPath++]=NODE(now,depth);
}
inline void BuildTree(int n){
  zkwM=1<<(__lg(n)+1); // 算 ZkwTree 的分界點(葉節點的起始位置)
  for(int i=0;i<n;i++)
    zkw[zkwM+i]=org[i];
  for(int i=n;i<zkwM;i++)// 避免垃圾訊息所以放預設值
    zkw[zkwM+i]=NODE();
  for(int i=zkwM-1;i;i--)
    zkw[i]=min(zkw[i<<1],zkw[i<<1|1]);
}

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  int N, Q;
  scanInt(N);
  scanInt(Q);
  for(int v,u=1;u<=N;u++)
    while( scanInt(v) and v)
      Link[u].push_back(v);
  node_OnPath=0;
  DFS(1,0);
  BuildTree(node_OnPath);

  for(int i=1;i<=N;i++)
    printf("%d ",PathNo[i]);
  puts("");
  for(int i=0;i<node_OnPath;i++)
    printf("%d ",org[i].no);
  puts("");
  for(int i=0;i<node_OnPath;i++)
    printf("%d ",org[i].dp);
  puts("");


  int qL, qR;
  while(Q--){
    scanInt(qL),
    scanInt(qR);
    // 將祖譜樹上的號碼轉為路徑的節點號碼，但注意左右邊界可能會相反
    qL=PathNo[qL],
    qR=PathNo[qR];
    if(qL>qR) qL^=qR^=qL^=qR;
    // zkw的query();
    NODE ans=NODE();
    int nL=qL+zkwM-1, nR=qR+zkwM+1;
    for( ;nL^nR^1;nL>>=1,nR>>=1){
      if(~nL&1) ans=min(ans,zkw[nL^1]);
      if( nR&1) ans=min(ans,zkw[nR^1]);
    }
    //printf("%d %d %d\n",org[qL].dp,org[qR].dp,-(org[PathNo[ans.no]].dp<<1));
    printf("%d %d\n",ans.no,org[qL].dp+org[qR].dp-(org[PathNo[ans.no]].dp<<1));
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