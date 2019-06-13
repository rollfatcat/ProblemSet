// 前一個查詢的答案會影響下一個查詢的輸入 => 強迫在線 => 持久化線段樹 (0.09s/22MB)
// 因為查詢的數值要做前處理可能會超過『合理情況』，非法情況時答案為0

#include<bits/stdc++.h>
using namespace std;
#define MAXN 30005

int N, Q, uN, Ntot=0, tag;
int org[MAXN]; // __lg(30000)+1=15 => 一條鏈的節點數
int srt[MAXN];
int root[MAXN]={};
int lson[MAXN<<4]={};
int rson[MAXN<<4]={};
int cntn[MAXN<<4]={};

void update(int nL,int nR,int &now,int pre){
  now=++Ntot;
  lson[now]=lson[pre];
  rson[now]=rson[pre];
  cntn[now]=cntn[pre]+1;
  if(nL==nR) return;
  int nM=nL+nR>>1;
  (tag<=nM)? update(nL,nM,lson[now],lson[pre]): update(nM+1,nR,rson[now],rson[pre]);
}
int query(int nL,int nR,int vL,int vR){
  if(nL>=tag) return cntn[vR]-cntn[vL];
  int nM=nL+nR>>1;
  int ret=query(nM+1,nR,rson[vL],rson[vR]);
  if(tag<=nM) ret+=query(nL,nM,lson[vL],lson[vR]);
  return ret;
}
int main(){
  scanf("%d",&N);
  for(int i=1;i<=N;i++)
    scanf("%d",&org[i]),
    srt[i]=org[i];
  sort(srt+1,srt+N+1);
  uN=unique(srt+1,srt+N+1)-srt;

  for(int i=1;i<=N;i++)
    tag=lower_bound(srt,srt+uN,org[i])-srt,
    update(1,uN-1,root[i],root[i-1]);

  scanf("%d",&Q);
  int pre_ans=0, L, R, K;
  while(Q--){
    scanf("%d%d%d",&L,&R,&K);
    L^=pre_ans; if(L<1) L=1;
    R^=pre_ans; if(R>N) R=N;
    K^=pre_ans;

    tag=upper_bound(srt,srt+uN,K)-srt;
    if(tag==0) pre_ans=N;
    else pre_ans=(L>R or K>srt[tag])? 0: query(1,uN-1,root[L-1],root[R]);
    printf("%d\n",pre_ans);
  }
}
/*
6
8 9 3 5 1 9
5
2 3 5
3 3 7
0 0 11
0 0 2
3 7 4
*/