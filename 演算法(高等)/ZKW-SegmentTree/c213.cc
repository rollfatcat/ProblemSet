// 離線操作＋區間更新＋區間和( ZKW_SegmentTree＋離線 )
/* 離線操作：將所有的查詢儲存起來後依據區間排序(目的是讓查詢具有單調性，以莫隊算法為代表)
 * 既然涉及儲存就必須注意記憶體空間是否過量問題
 * 解法核心：
 * 離線預先將區間和儲存起來排序，將查詢Query(nL,nR,vL,vR)轉變為Query(nL,nR,vR)-Query(nL,nR,vL-1)
 * 不同歷史版本疊加拆分為在不同時刻的查詢，視為相同區間但不同版本的相減，最後再加上前綴和即可。
 */

#include<bits/stdc++.h>
using namespace std;
#define MAXN 300005

const int MAXM=1<<(__lg(MAXN)+1);
struct VUNIT{
  int nL,nR,ver;
  VUNIT(int l=0,int r=0,int v=0):nL(l),nR(r),ver(v){}
} version[MAXN];
struct QUNIT{
  int nL,nR,ver,id;
  QUNIT(int l=0,int r=0,int v=0,int id=0):nL(l),nR(r),ver(v),id(id){}
  bool operator<(const QUNIT &rhs)const{ return ver<rhs.ver; }
} query[MAXN<<1];
long add[MAXM<<1|1]={};
long sum[MAXM<<1|1]={};
long ans[MAXN]={};
long PreSum[MAXN]={};
int B;

inline void Update(int qL,int qR,long qK){
  int nL=0, nR=0, len=1;
  for(qL+=B-1,qR+=B+1; qL^qR^1; ){
    if(~qL&1) add[qL^1]+=qK, nL+=len;
    if( qR&1) add[qR^1]+=qK, nR+=len;
    qL>>=1, qR>>=1, len<<=1;
    sum[qL]+=qK*nL;
    sum[qR]+=qK*nR;
  }
  for(nL+=nR,qL>>=1; qL; qL>>=1)
    sum[qL]+=qK*nL;
}
inline long Query(int qL,int qR,long sumN=0){
  int nL=0, nR=0, len=1;
  for(qL+=B-1,qR+=B+1; qL^qR^1; ){
    if(~qL&1) sumN+=sum[qL^1]+add[qL^1]*len, nL+=len;
    if( qR&1) sumN+=sum[qR^1]+add[qR^1]*len, nR+=len;
    qL>>=1,qR>>=1,len<<=1;
    if(add[qL]) sumN+=add[qL]*nL;
    if(add[qR]) sumN+=add[qR]*nR;
  }
  for(nL+=nR,qL>>=1; qL; qL>>=1)
    if(add[qL])
      sumN+=add[qL]*nL;
  return sumN;
}
inline void scanInt(int &x){
  char c=getchar();
  bool sign=c=='-';
  for(x=sign? 0: c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
}
int main(){

  int N, M, Q ,Qid;
  int qL, qR, qK;
  scanInt(N);
  scanInt(M);
  B=1<<(__lg(N)+1); // <- 取 base 時記得 base 的由來是最底層空間必須完全容納現有節點才可
  // 前綴和
  for(int i=1;i<=N;i++)
    scanInt(qK),
    PreSum[i]=PreSum[i-1]+qK;
  for(int i=1;i<=M;i++){
    scanInt(qL),
    scanInt(qR),
    scanInt(qK),
    version[i]=VUNIT(qL,qR,qK);
  }
  // 離線操作
  scanInt(Q);
  for(int i=1;i<=Q;i++){
    scanInt(qL),
    scanInt(qR),
    scanInt(qK),
    query[ i ]=QUNIT(qL,qR,qK-1,-i);
    scanInt(qK),
    query[Q+i]=QUNIT(qL,qR,qK,i),
    // 處理前綴和
    ans[i]=PreSum[qR]-PreSum[qL-1];
  }
  sort(query+1,query+(Q<<1|1));

  for(Qid=1;query[Qid].ver==0;Qid++);
  for(int nowv=0;Qid<=(Q<<1);Qid++){
    while(nowv<query[Qid].ver)
      nowv++, Update(version[nowv].nL,version[nowv].nR,version[nowv].ver);
    if(query[Qid].id<0)
      ans[ -query[Qid].id ]-=Query(query[Qid].nL,query[Qid].nR);
    else
      ans[  query[Qid].id ]+=Query(query[Qid].nL,query[Qid].nR);
  }
  for(Qid=1; Qid<=Q; Qid++)
    printf("%ld\n",ans[Qid]);
}
/*
5 3
1 3 2 7 9
1 5 10
1 3 -7
3 5 8
4
1 5 1 3
3 3 3 3
3 4 1 2
2 5 2 3
=======
 1  3  2  7  9
11 13 12 17 19
 4  6  5 17 19
 4  6 13 25 27


*/