// 題解：http://yp155136codingarea.blogspot.com/2016/11/zj-b903.html
/* DP+映射版本的SegmentTree，SegmentTree的使用方式類似a596，只是那題的數據結構是BIT
 * 解題方式類似a596，一樣先推導出DP規則(類似LCS)
 * DP[i][j]= max( max(DP[i-1][j],DP[i][j-1]), DP[i-1][j-1]+1 )
 * 問題是怎麼把DP公式轉成SegmentTree的形式：DP[b] = max( max(DP[1]...DP[b-1])+v, DP[b])
 * 且做之前要先把所有的edge排序：edge(a,b)=v，a由小到大而b則是大到小(方便於更新時不會出現『交叉』)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=3e5;
int qL, qR, IDmap[MAXN+1];
int segtr[MAXN<<2];
struct PAIR{
  int a,b,v;
  bool operator<(const PAIR &rhs)const{ return(a==rhs.a)?(b>rhs.b):(a<rhs.a);}
}edge[MAXN];
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
// ---建設映射表--- => 改成zkw式就不需要了
void BuildID(int nL,int nR,int pt){
  if(nL==nR){ IDmap[nL]=pt; return; }
  int mid=(nL+nR)>>1, Lson=pt<<1;
  BuildID(nL,mid,Lson);
  BuildID(mid+1,nR,Lson|1);
}
// ---單點更新---
void Update_node(int pos,int v){
  int leaf_pt=IDmap[pos];
  segtr[leaf_pt]=max(segtr[leaf_pt],v);
  for(int parent=leaf_pt>>1; parent; parent>>=1)
    segtr[parent]=max(segtr[parent<<1],segtr[parent<<1|1]);
}
// ---區間查詢---
int Query_part(int nL,int nR,int pt){
  if(qL<=nL and nR<=qR){ return segtr[pt]; }
  int mid=(nL+nR)>>1, Lson=pt<<1;
  if(qR<=mid) return Query_part(   nL,mid,  Lson);
  if(qL> mid) return Query_part(mid+1, nR,Lson|1);
  return max(Query_part(nL,mid,Lson),Query_part(mid+1,nR,Lson|1));
}
int main(){
  for(int N,M,K; scanInt(N); ){
    scanInt(M),
    scanInt(K);
    for(int i=0;i<K;i++)
      scanInt(edge[i].a),
      scanInt(edge[i].b),
      scanInt(edge[i].v);
    sort(edge,edge+K);
    BuildID(1,M,1);
    for(int i=0;i<K;i++){
      if(edge[i].b==1) continue;
      qL=1, qR=edge[i].b-1;
      Update_node(edge[i].b, Query_part(1,M,1)+edge[i].v);
    }
    printf("%d\n",segtr[1]);
  }
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