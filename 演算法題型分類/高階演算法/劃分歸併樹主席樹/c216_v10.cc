/* 正解：區間和＝前綴和+要增加的高度x區間個數-(區間個數-沒爆料)x1e5
 * 以下解法是『在線』『主席樹解法』
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005

int N, Q, uN;
int tot=0, tag;
int lson[MAXN<<4];
int rson[MAXN<<4];
int Ncnt[MAXN<<4];
int root[MAXN];
int org[MAXN];
int srt[MAXN];
long sumh[MAXN];

void update(int nL,int nR,int &now,int pre){
  now=++tot;
  lson[now]=lson[pre];
  rson[now]=rson[pre];
  Ncnt[now]=Ncnt[pre]+1;
  if(nL==nR) return;
  int nM=nL+nR>>1;
  (tag<=nM)? update(nL,nM,lson[now],lson[pre]): update(nM+1,nR,rson[now],rson[pre]);
}
int query(int nL,int nR,int Lv,int Rv){
  if(nR<=tag) return Ncnt[Rv]-Ncnt[Lv];
  int nM=nL+nR>>1;
  int ret=query(  nL,nM,lson[Lv],lson[Rv]);
  if(tag>nM ) ret+=query(nM+1,nR,rson[Lv],rson[Rv]);
  return ret;
}
int main(){

  scanf("%d%d",&N,&Q);
  for(int i=1;i<=N;i++)
    scanf("%d",&org[i]), srt[i-1]=org[i],
    sumh[i]=sumh[i-1]+org[i];
  // 離散化
  sort(srt,srt+N);
  uN=unique(srt,srt+N)-srt;
  // 根據數列順序建立每條『路徑點』
  for(int i=1;i<=N;i++)
    tag=lower_bound(srt,srt+uN,org[i])-srt+1,
    update(1,uN,root[i],root[i-1]);
  // 支援在線查詢
  int opt, qL, qR;
  for(int nowH=100000; Q--;){
    scanf("%d",&opt);
    if(opt==1){ // 整個區段一起增高qL
      scanf("%d",&qL), nowH-=qL;
      while(nowH<0) nowH+=100000;
    }
    else{
      scanf("%d%d",&qL,&qR),
      tag=upper_bound(srt,srt+uN,nowH)-srt;
      int NotOver=(tag>0)? query(1,uN,root[qL-1],root[qR]): 0;
      long cnt=qR-qL+1;
      printf("%ld\n",sumh[qR]-sumh[qL-1]+(100000-nowH)*cnt-100000*(cnt-NotOver));
    }
  }
}
/*
5 6
1 2 3 4 5
1 99995
2 1 4
1 2
2 2 5
1 2
2 1 5
===
99998 99999 100000 1 2
*/