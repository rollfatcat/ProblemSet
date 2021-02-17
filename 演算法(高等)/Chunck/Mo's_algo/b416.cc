// 改編於 b414 的莫隊＋分塊(0.9s/24.7MB)
// 和 ZJ-b414 差異是題目要求是區間內出現在查詢範圍內的『個數』非『種類』
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
      ret+=cnt[i];
  }
  else{ //查詢範圍屬於不同區塊時
    for(int i=nL;i<=belong[nL]*blocksz;i++)
      ret+=cnt[i];
    for(int i=belong[nL]+1;i<=belong[nR]-1;i++)
      ret+=block[i];
    for(int i=(belong[nR]-1)*blocksz+1;i<=nR;i++)
      ret+=cnt[i];
  }
  return ret;
}
inline void add(int x){
  cnt[x]++; // 原本的數量+1
  block[ belong[x] ]++;
}
inline void sub(int x){
  cnt[x]--; // 原本的數量-1
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