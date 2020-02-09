// (X) 主席樹問題？or 樹狀數組套線段數解？ => 更新節點數過多導致 MLE
// 離線操作＋區間更新＋區間和( ZJ-d799＋離線 )
/* 離線操作：將所有的查詢儲存起來後依據區間排序(目的是讓查詢具有單調性，以莫隊算法為代表)
 * 既然涉及儲存就必須注意記憶體空間是否過量問題
 * 解法核心：
 * 離線預先將區間和儲存起來排序，將查詢Query(nL,nR,vL,vR)轉變為Query(nL,nR,vR)-Query(nL,nR,vL-1)
 * 不同歷史版本疊加拆分為在不同時刻的查詢，視為相同區間但不同版本的相減，最後再加上前綴和即可。
 */

#include<bits/stdc++.h>
using namespace std;
#define MAXN 300005

struct VUNIT{
  int nL,nR,ver;
  VUNIT(int l=0,int r=0,int v=0):nL(l),nR(r),ver(v){}
} version[MAXN];
struct QUNIT{
  int nL,nR,ver,id;
  QUNIT(int l=0,int r=0,int v=0,int id=0):nL(l),nR(r),ver(v),id(id){}
  bool operator<(const QUNIT &rhs)const{ return ver<rhs.ver; }
} query[MAXN<<1];
long add[MAXN<<2]={};
long sum[MAXN<<2]={};
long ans[MAXN]={};
long PreSum[MAXN]={};

void Update(int nL,int nR,int pt,int qL,int qR,long qK){
  sum[pt]+=(qR-qL+1)*qK;
  if(qL==nL and nR==qR){ add[pt]+=qK; return; }
  int nM=nL+nR>>1;
  if(qR<=nM)
    Update(nL,nM,pt<<1,qL,qR,qK);
  else if(qL>nM)
    Update(nM+1,nR,pt<<1|1,qL,qR,qK);
  else
    Update(nL,nM,pt<<1,qL,nM,qK),
    Update(nM+1,nR,pt<<1|1,nM+1,qR,qK);
}
long Query(int nL,int nR,int pt,int qL,int qR,long qK){
  if(qL==nL and nR==qR){ return sum[pt]+(qR-qL+1)*qK; }
  int nM=nL+nR>>1;
  // 若不是匹配线段，更新增量，继续往下找
  if(nM>=qR)
    return Query(nL,nM,pt<<1,qL,qR,qK+add[pt]);
  else if(nM<qL)
    return Query(nM+1,nR,pt<<1|1,qL,qR,qK+add[pt]);
  else
    return Query(  nL,nM,  pt<<1,  qL,nM,qK+add[pt])+
           Query(nM+1,nR,pt<<1|1,nM+1,qR,qK+add[pt]);
}
inline void scanInt(int &x){
  char c=getchar();
  bool sign=c=='-';
  for(x=sign? 0: c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
}
int main(){

  int N, M, Q, Qid;
  int qL, qR, qK;
  scanInt(N);
  scanInt(M);
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
    query[Q+i]=QUNIT(qL,qR,qK,i);
    ans[ i ]+=PreSum[qR]-PreSum[qL-1];
  }
  sort(query+1,query+(Q<<1|1));

  for(Qid=1;query[Qid].ver==0;Qid++)
    ans[query[Qid].id]=0;
  for(int nowv=0;Qid<=(Q<<1);Qid++){
    while(nowv<query[Qid].ver)
      nowv++, Update(1,N,1,version[nowv].nL,version[nowv].nR,version[nowv].ver);
    if(query[Qid].id<0)
      ans[ -query[Qid].id ]-=Query(1,N,1,query[Qid].nL,query[Qid].nR,0);
    else
      ans[  query[Qid].id ]+=Query(1,N,1,query[Qid].nL,query[Qid].nR,0);
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