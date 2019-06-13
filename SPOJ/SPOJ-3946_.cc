// 劃分樹版本(0.19s/29MB)
// 解法出處：https://debug.fanzheng.org/post/merger-tree-and-parti-tree.html
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100005;
const int MAXH=__lg(MAXN); // 一般預設是20，__lg(MAXN)=16
int* srt;
int qL, qR, qK;
int toL[MAXH+2][MAXN]={};
int num[MAXH+2][MAXN]={};

void BuildTree(int nL,int nR,int depth){
  // ---走到葉節點時代表結束，此時葉節點就是排序完成的區間---
  if(nL==nR){ return; }
  int nM=(nL+nR)>>1;
  int pivot=srt[nM];
  // ---小於等於中間值時將數字複製到下一層且(同一層的)紀錄包含目前這個數字左邊有幾個屬於左子樹---
  // 左邊界的第一個數額外處理(因為沒有toL[depth][top]可以參考)
  int idxL=nL, idxR=nM+1;
  toL[depth][nL]=(num[depth][nL]<=pivot);
  num[depth+1][ (toL[depth][nL])?idxL++:idxR++ ]=num[depth][nL];
  for(int top=nL+1;top<=nR;top++){
    if(idxL<=nM and num[depth][top]<=pivot)
      num[depth+1][idxL++]=num[depth][top],
      toL[depth][top]=toL[depth][top-1]+1;
    else
      num[depth+1][idxR++]=num[depth][top],
      toL[depth][top]=toL[depth][top-1];
  }
  // ---往下遞迴---
  BuildTree(  nL,nM,depth+1);
  BuildTree(nM+1,nR,depth+1);
}
int Query(int nL,int nR,int depth){
  if(nL==nR) return num[depth][nL]; //到達葉節點直接回傳答案
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
  for(int N,Q;scanf("%d%d",&N,&Q)==2;){
    int maxH=__lg(N);
    maxH+=(N>(1<<maxH));
    srt=&num[maxH][0];
    for(int i=1;i<=N;i++)
      scanf("%d",&num[0][i]),
      srt[i]=num[0][i];
    sort(srt+1,srt+N+1); // 最底層是完成排序的數列
    BuildTree(1,N,0);

    while(Q--)
      scanf("%d",&qL),
      scanf("%d",&qR),
      scanf("%d",&qK),
      printf("%d\n",Query(1,N,0));

  }
}