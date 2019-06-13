// 歸併樹版本(94ms/7.2MB)
// 解法出處：http://mypaper.pchome.com.tw/zerojudge/post/1323170731
// 題目保證給的數列中不會有『重複的』數字(原版題目會給重複，所以以下做法需要調整)
/* 建立歸併樹：將 MergeSort 過程的每個『區間』都存起來，分割的方法等同線段樹的 Divide
 * seg[h][x]: h代表總長度切成(1<<h)個區間時的狀態且每個區間都是排序後的嚴格遞增數列
 * seg[0][x]: 整個排序後的嚴格遞增數列
 * seg[__lg(N)][x]: 葉節點
 * 1.用二分法枚舉排序好的元素中在[qL,qR]中的rank，直到該rank值和詢問中的rank相等；
 * 2.那排序好的某個元素val，如何求得該元素在指定區間[qL,qR]中的rank
 *   問題出在於 指定區間內的元素並未排序無法直接套上二分搜尋？ => 區塊分治(拆成數個排序好的子區間)
 *   這就要利用到剛建好的歸併樹：我們可以利用類似線段樹的Query()操作找到所有属於[qL,qR]的子區間，
 *   然後累加元素val在個别子區間内的rank，得到的就是val在區間[qL,qR]中的rank，注意到這和合併排序的合併過程一致；
 * 3.由於属於子區間的元素的排序结果已经紀錄下来，所以元素val在子區間内的rank可以通過二分法得到。
 * 上面三步經過三次二分操作(Query也是種二分)，於是每次詢問的複雜度是O(logN*logN*logN)
 */
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