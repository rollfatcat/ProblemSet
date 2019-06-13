// 題目：LUOGU-P1314 二分法估值+前綴和(價值和個數)
/* 原本以為是要樹狀數組累計數量，但是位置必須落在查詢區間才有效
 * 前綴和的目的是方便判斷區間內大於值的個數和價值總和 O(1)
 * 二分法收斂得很快(1<<20=1048576)，所以掃遍整個數列的次數並不多，最多20次
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 200001

struct ITEM{ int w,v; }item[MAXN];
struct QUERY{ int L,R; } query[MAXN];
int N, Q;
long ans=1e13, S;
long sum[MAXN];
int cnt[MAXN];

inline bool check(int bound){
  long ret=0;
  for(int i=1;i<=N;i++){
    if(item[i].w>=bound)
      sum[i]=sum[i-1]+item[i].v,
      cnt[i]=cnt[i-1]+1;
    else
      sum[i]=sum[i-1],
      cnt[i]=cnt[i-1];
  }
  for(int qL,qR,i=1;i<=Q;i++)
    qL=query[i].L,
    qR=query[i].R,
    ret+=(long)(cnt[qR]-cnt[qL-1])*(sum[qR]-sum[qL-1]);

  ans=min(ans,abs(ret-S));
  return ret>=S;
}
inline bool scanInt (int  &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
inline bool scanLong(long &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){

  scanInt(N),
  scanInt(Q),
  scanLong(S);
  for(int i=1;i<=N;i++)
    scanInt(item[i].w),
    scanInt(item[i].v);

  for(int i=1;i<=Q;i++)
    scanInt(query[i].L),
    scanInt(query[i].R);

  int nL=1, nR=1e6, nM;
  while(nL<=nR){
    nM=nL+nR>>1;
    (check(nM))? nL=nM+1: nR=nM-1;
  }
  printf("%ld",ans);
}