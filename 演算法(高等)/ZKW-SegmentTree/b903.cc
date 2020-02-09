/* DP+ZKW-SegmentTree，SegmentTree的使用方式類似a596，只是那題的數據結構是BIT
 * 解題方式類似a596，一樣先推導出DP規則(類似LCS)
 * DP[i][j]= max( max(DP[i-1][j],DP[i][j-1]), DP[i-1][j-1]+1 )
 * 問題是怎麼把DP公式轉成SegmentTree的形式：DP[b] = max( max(DP[1]...DP[b-1])+v, DP[b])
 * 且做之前要先把所有的edge排序：edge(a,b)=v，a由小到大而b則是大到小(方便於更新時不會出現『交叉』)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=3e5;
int zkwtr[3*MAXN]={};
struct PAIR{
  int a,b,v;
  bool operator<(const PAIR &rhs)const{ return(a==rhs.a)?(b>rhs.b):(a<rhs.a);}
}edge[MAXN];
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  int N, M, K;
  scanInt(N),
  scanInt(M),
  scanInt(K);
  for(int i=0;i<K;i++)
    scanInt(edge[i].a),
    scanInt(edge[i].b),
    scanInt(edge[i].v);
  sort(edge,edge+K);
  // --- 動態規劃 ---
  int B=1<<(__lg(M)+1);
  for(int i=0;i<K;i++)
    if(edge[i].b>1){
      // 區間查詢，(qL,qR)=(1,edge[i].b)
      int maxV=0;
      for(int qL=B,qR=edge[i].b+B; qL^qR^1; qL>>=1,qR>>=1){
        if(~qL&1) maxV=max(maxV,zkwtr[qL^1]);
        if( qR&1) maxV=max(maxV,zkwtr[qR^1]);
      }
      maxV+=edge[i].v;
      // 單點更新
      if(zkwtr[edge[i].b+B]<maxV){
        zkwtr[edge[i].b+B]=maxV;
        for(int pos=(edge[i].b+B)>>1; pos; pos>>=1)
          zkwtr[pos]=max(zkwtr[pos<<1],zkwtr[pos<<1|1]);
      }
    }
  printf("%d\n",zkwtr[1]);
}
/*
2 3 6
1 1 3
1 2 4
1 3 6
2 1 7
2 2 2
2 3 4

2 2 2
1 2 5
2 1 4
*/