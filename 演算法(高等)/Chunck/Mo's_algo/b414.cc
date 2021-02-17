// (X) 離線＋樹狀數組 => 問題出在移動指標時修改維護的數組是㏒Ｎ，這是TLE的關鍵
// (O) 離線＋分塊算法 => 讓修改的成本降低為O(1)，而查詢成本一樣是O(㏒Ｎ)
/* 離線就透過莫隊算法實現。<= 詳細介紹：ZJ-b417
 * 用分塊算法維護，分别維護每個數字的個數(cnt[x])和每個區塊的值(區間內的種類個數)，
 * 修改時分别在目標位置和所在區塊的值上加上增量，複雜度O(1)。
 * 查詢時將整塊的和整塊外的值分别加入，複雜度O(√Ｎ)，因為只需要進行√Ｎ次查詢，所以整體為O(Q√Ｎ)，
 * 單點修改時的複雜度相對與樹狀數组等结構少㏒。
 */

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXQ 1000005

int org[MAXN];
int ans[MAXQ]; // 離線時對應回原先的輸出順序
int cnt[MAXN]; // cnt[x] 代表 x 這個數字的個數
int belong[MAXN];
int block[320]; // sqrt(MAXN)=316
int blocksz;

struct QUERY{
  int L,R,a,b,o;
  QUERY(int l=0,int r=0,int a=0,int b=0,int o=0):L(l),R(r),a(a),b(b),o(o){}
  bool operator<(const QUERY &rhs)const{ return belong[L]<belong[rhs.L] or (belong[L]==belong[rhs.L] and R<rhs.R); }
}query[MAXQ];

inline int QueryBlock(int nL,int nR,int ret=0){
  if( belong[nL]==belong[nR] ){ //查詢範圍屬於相同區塊時
    for(int i=nL;i<=nR;i++)
      if(cnt[i])
        ret++;
  }
  else{ //查詢範圍屬於不同區塊時
    for(int i=nL;i<=belong[nL]*blocksz;i++)
      if(cnt[i])
        ret++;
    for(int i=belong[nL]+1;i<=belong[nR]-1;i++)
      ret+=block[i];
    for(int i=(belong[nR]-1)*blocksz+1;i<=nR;i++)
      if(cnt[i])
        ret++;
  }
  return ret;
}
inline void add(int x){
  cnt[x]++; // 原本的數量+1
  if(cnt[x]==1) // 某個數量從0變成1，代表這個區塊的種類數+1
    block[ belong[x] ]++;
}
inline void sub(int x){
  cnt[x]--; // 原本的數量-1
  if(cnt[x]==0) // 某個數量從1變成0，代表這個區塊的種類數-1
    block[ belong[x] ]--;
}
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int N, Q, L, R, a, b;
  scanInt(N);
  scanInt(Q);
  for(int i=1;i<=N;i++)
    scanInt(org[i]);
  for(int i=0;i<Q;i++)
    scanInt(L),
    scanInt(R),
    scanInt(a),
    scanInt(b),
    query[i]=QUERY(L,R,a,b,i);
  blocksz=ceil(sqrt(N));
  for(int i=1;i<=N;i++)
    belong[i]=(i-1)/blocksz+1;
  sort(query,query+Q);
  int nowL=0, nowR=0;
  for(int Qid=0;Qid<Q;Qid++){
    while( nowR>query[Qid].R ) sub(org[nowR--]);
    while( nowR<query[Qid].R ) add(org[++nowR]);
    while( nowL>query[Qid].L ) add(org[--nowL]);
    while( nowL<query[Qid].L ) sub(org[nowL++]);
    ans[ query[Qid].o ]=QueryBlock(query[Qid].a,query[Qid].b);
  }
  for(int Qid=0;Qid<Q;Qid++)
    printf("%d\n",ans[Qid]);
}