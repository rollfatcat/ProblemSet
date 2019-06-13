// 倍增法(0.3s/2.5MB)
// 教學文件：https://blog.csdn.net/txl199106/article/details/53998831
/* 本質是樹版本的RMQ，pa[i][j]表示從點i開始，往上2^j步的節點編號。
 * 假設 x=pa[i][j−1]，那麼 pa[i][j]=pa[x][j−1]。
 * 單次查詢时，先將兩個點提到同一高度，然後一同往上跳O(㏒N)的取答案，整體是O(N㏒N)的處理。
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=30001;
const int MAXH=__lg(MAXN)+1;
vector<int> Link[MAXN];
short nh[MAXN];
short pa[MAXN][MAXH]={}; // 值＝０代表點不存在

void DFS(int now,int depth){
  nh[now]=depth;
  for(int i=0;i<Link[now].size();i++)
    pa[ Link[now][i] ][0]=now,
    DFS(Link[now][i],depth+1);
}
int main(){
  int N, Q, u, v;
  scanf("%d %d",&N,&Q);
  for(u=1;u<=N;u++)
    for(pa[u][0]=u;scanf("%d",&v) and v;)
      Link[u].push_back(v);
  // 從根節點出發，找齊每個節點的高度和父節點
  DFS(1,0);
  // 倍增法的重點：建表，概念上類似 SparseTable
  for(int i=1;(1<<i)<N;i++) // 枚舉步數，N個點最多只有N-1步
    for(int x,j=1;j<=N;j++) // 枚舉每個點
      if(pa[j][i-1]) // pa[j][i] 代表j的第2^i祖先
        pa[j][i]=pa[ pa[j][i-1] ][i-1]; //j的第2^i祖先 就是 j的第2^(i-1)祖先的第2^(i-1)祖先
  // 根據查詢輸出共同祖先和血緣關係距離
  for(int Qu,Qv;Q--;){
    scanf("%d %d",&Qu,&Qv);
    if(nh[Qu]>nh[Qv]) swap(Qu,Qv);

    // 過程就是將原先org_v到org_u間的距離做二進位制跳位
    // 只是每次都走2^vh步(如果可以)，下次出發時就從上次走到的點出發
    u=Qu,
    v=Qv;
    for(int i=__lg(nh[v]);i>=0;i--)
      if(nh[v]-(1<<i)>=nh[u])
        v=pa[v][i];
    if(u==v){ printf("%d %d\n",Qu,nh[Qv]-nh[Qu]); continue; }
    // 代表 u,v 分屬不同子樹需要同時往上跳，但初始高度是相同
    for(int i=__lg(nh[u]);i>=0;i--)
      if(pa[u][i] and pa[u][i]!=pa[v][i])
        u=pa[u][i],
        v=pa[v][i];
    printf("%d %d\n",pa[u][0],nh[Qu]+nh[Qv]-(nh[pa[u][0]]<<1));
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