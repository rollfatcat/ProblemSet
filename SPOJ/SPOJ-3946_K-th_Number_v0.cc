// 歸併樹版本(0.64s/23MB)

#include<bits/stdc++.h>
using namespace std;

const int MAXN=100005;
const int MAXH=__lg(MAXN)+2; // 一般預設是20，__lg(MAXN)=16

int qL, qR, qK, val, res;
int seg[MAXH][MAXN+1]; // 保留整個 MergeSort 的過程

void BuildTree(int nL,int nR,int depth){
  // ---到達葉節點時讀取『單點資訊』後遞迴往上合併---
  if(nL==nR){ scanf("%d",&seg[depth][nL]);  return; }
  int nM=(nL+nR)>>1;
  BuildTree(  nL,nM,depth+1);
  BuildTree(nM+1,nR,depth+1);
  // ---合併兩棵子樹的數列---
  int idxL=nL, idxR=nM+1, top=nL;
  while(idxL<=nM and idxR<=nR){
    if(seg[depth+1][idxL]<seg[depth+1][idxR])
      seg[depth][top++]=seg[depth+1][idxL++];
    else
      seg[depth][top++]=seg[depth+1][idxR++];
  }
  while(idxL<=nM) seg[depth][top++]=seg[depth+1][idxL++];
  while(idxR<=nR) seg[depth][top++]=seg[depth+1][idxR++];
}
void Query(int nL,int nR,int depth){ //每次詢問時再重算邊界即可
  if(qL<=nL and nR<=qR){
    int L=nL, R=nR, M;
    while(L<R){
      M=(L+R)>>1;
      if(seg[depth][M]<val)
        L=M+1;
      else
        R=M;
    }
    res+=L-nL+(seg[depth][L]<=val);
    return;
  }
  int nM=(nL+nR)>>1;
  if(qL<=nM) Query(  nL,nM,depth+1);
  if(qR>nM)  Query(nM+1,nR,depth+1);
}
int main(){
  for(int N,Q;scanf("%d%d",&N,&Q)==2;){
    BuildTree(1,N,0);
    while(Q--){
      scanf("%d",&qL),
      scanf("%d",&qR),
      scanf("%d",&qK);
      int nL=1, nR=N, nM;
      // ---二分搜尋：枚舉排序好的元素在指定區間內的rank---
      while(nL<nR){
        nM=(nL+nR)>>1;
        val=seg[0][nM];
        res=0;
        Query(1,N,0);
        if(res<qK)
          nL=nM+1;
        else
          nR=nM;
      }
      printf("%d\n",seg[0][nL]);
    }
  }
}