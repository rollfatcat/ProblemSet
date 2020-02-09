// 這是可以處理『重複』數字的劃分樹版本
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;
const int MAXH=__lg(MAXN); // 一般預設是20，__lg(MAXN)=16
int* srt;
int qL, qR, qK;
int toL[MAXH+2][MAXN+1]={};
int num[MAXH+2][MAXN+1]={};

inline bool scanInt(int &x){
  char c;
  while((c=getchar())==' ');
  bool sign=c=='-';
  for(x=(sign)?0:(c-'0');(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
  return c!=EOF;
}
void BuildTree(int nL,int nR,int depth){
  // ---走到葉節點時代表結束，此時葉節點就是排序完成的區間---
  if(nL==nR) return;
  int nM=(nL+nR)>>1;
  int pivot=srt[nM], cntL=nM-nL+1;
  // ---計算現在這個區間內小於中間值的個數---
  for(int top=nL;top<=nR;top++)
    if(num[depth][top]<pivot)
      cntL--;
  /* (1)小於中間值或是(2)等於中間值且還有個數可以放在左子樹時，
   * 將數字複製到下一層且(同一層的)紀錄包含目前這個數字左邊有幾個屬於左子樹
   * 左邊界的第一個數額外處理
   */
  int idxL=nL, idxR=nM+1;
  toL[depth][nL]=(num[depth][nL]<pivot or num[depth][nL]==pivot and cntL--);
  num[depth+1][(toL[depth][nL])?idxL++:idxR++]=num[depth][nL];
  for(int top=nL+1;top<=nR;top++){
    if(idxL<=nM and (num[depth][top]<pivot or num[depth][top]==pivot and cntL--))
      num[depth+1][idxL++]=num[depth][top],
      toL[depth][top]=toL[depth][top-1]+1;
    else
      num[depth+1][idxR++]=num[depth][top],
      toL[depth][top]=toL[depth][top-1];
    if(top==nL) toL[depth][top]-=toL[depth][top-1];
  }
  // ---往下遞迴---
  BuildTree(  nL,nM,depth+1);
  BuildTree(nM+1,nR,depth+1);
}
int Query(int nL,int nR,int depth){
  if(nL==nR) return num[depth][nL];
  int nM=(nL+nR)>>1;
  int cntL=(qL>nL)?toL[depth][qL-1]:0;
  int rem=toL[depth][qR]-cntL;
  if(rem>=qK){
    qL=nL+cntL,
    qR=nL+toL[depth][qR]-1;
    return Query(  nL,nM,depth+1);
  }else{
    qK-=rem,
    qL=nM+1+qL-nL-cntL,
    qR=nM+1+qR-nL-toL[depth][qR];
    return Query(nM+1,nR,depth+1);
  }
}
int main(){
  for(int N,Q;scanInt(N) and scanInt(Q);){
    int maxH=__lg(N);
    maxH+=(N>(1<<maxH));
    srt=&num[maxH][0];
    for(int i=1;i<=N;i++)
      scanInt(num[0][i]),
      srt[i]=num[0][i];
    sort(srt+1,srt+N+1); // 最底層是完成排序的數列
    BuildTree(1,N,0);

    while(Q--)
      scanInt(qL),
      scanInt(qR),
      scanInt(qK),
      printf("%d\n",Query(1,N,0));

  }
}
/*
7 3
1 5 2 6 3 7 4

8 3
5 3 1 7 4 2 8 6
*/