// (離線處理=>莫隊) 89%(11% TLE，猜測是卡在當除數很小但是暴力法查詢倍數導致的TLE)
/* 根據theshold決定採用莫隊還是前綴和計算(1.5s/64.6MB)
 * 訂一個 threshold 來決定當除數小於時透過『前綴和』計算區間內可以被該除數整除的個數
 * ，因為前綴和的計算方式整體記憶體空間不能過大(√ＮxＮ太大，所以才把threshold調降為50)
 * ，若大於等於則採用莫隊算法處理，這時即便是暴力查詢倍數時間成本也是Ｋ√Ｎ，Ｋ＝√Ｎ/threshold。
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 300001

const int SQTN=51; // SQTN=threshold
int N, Bsz;
int org[MAXN];
int cnt[MAXN];
int ans[MAXN];
int pos[SQTN-2][MAXN]; // for prefixSum
struct QUERY{
  int L,R,v,o;
  QUERY(int l=0,int r=0,int v=0,int o=0):L(l),R(r),v(v),o(o){}
  bool operator<(const QUERY &rhs)const{ return (L/Bsz)<(rhs.L/Bsz) or (L/Bsz)==(rhs.L/Bsz) and R<rhs.R; }
} query[MAXN];

inline void add(int x){ cnt[x]++; }
inline void sub(int x){ cnt[x]--; }
int main(){

  int Q, qL, qR, qV;
  scanf("%d",&N);
  scanf("%d",&Q);
  Bsz=ceil(sqrt(N));
  for(int i=1;i<=N;i++){
    scanf("%d",&org[i]);
    for(int fac=2;fac<SQTN;fac++) // 前綴和版本
      pos[fac-2][i]=pos[fac-2][i-1]+(org[i]%fac==0);
  }
  int tot=0;
  for(int i=0;i<Q;i++){
    scanf("%d",&qL),
    scanf("%d",&qR),
    scanf("%d",&qV);
    if(qV<SQTN) // 查詢的因數太小時直接根據前綴和計算落在這個區間內可以被該因數整除的個數
      ans[i]=(qV==1)? (qR-qL+1): (pos[qV-2][qR]-pos[qV-2][qL-1]);
    else // 查詢因數略大(接近√Ｎ)時則採用莫隊算法，維護每個數字在區間內出現的個數
      query[tot++]=QUERY(qL,qR,qV,i);
  }
  // 需要用到莫隊算法的查詢個數是tot
  sort(query,query+tot);
  int nowL=0, nowR=0;
  for(int i=0;i<tot;i++){
    while(nowL<query[i].L) sub(org[nowL++]);
    while(nowL>query[i].L) add(org[--nowL]);
    while(nowR>query[i].R) sub(org[nowR--]);
    while(nowR<query[i].R) add(org[++nowR]);
    // QueryCnt(): 暴力法累計所有屬於該除數倍數的個數
    for(int j=query[i].v; j<=N; j+=query[i].v)
      ans[ query[i].o ]+=cnt[j];
  }
  for(int i=0;i<Q;i++)
    printf("%d\n",ans[i]);
}