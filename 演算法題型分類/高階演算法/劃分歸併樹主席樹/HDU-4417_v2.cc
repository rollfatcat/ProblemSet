// 題解：http://cthbstalpha.blogspot.com/2017/01/hdu-4417-super-mario.html
/* 歸併樹解法(支援在線查詢)
 * 原理大概是把 merge sort 每一層的狀態紀錄下來，有點像是把 merge sort時間維度儲存下來。
 * 因為將分治法的時間維度儲存下來所以多了一個時間的自由度，也就是我們可以達到動態查詢的效果，
 * 跟持久化線段數比起來，實作簡單一點點點，但是一次查詢是 O(㏒N*㏒N)
 * 劃分樹可以解決的問題幾乎都可以用持久化線段樹解決而且持久化線段樹的時間複雜度會比較好
 * 時間 O( n㏒n + Q㏒N㏒N ) 空間 O(n㏒n)
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define MAXH __lg(MAXN)+2

int seg[MAXH][MAXN];
int qL, qR, qH;

void mergeSort(int deep,int nL,int nR){
  // 到達葉節點(最底層)讀取資料
  if(nL==nR){ scanf("%d",&seg[deep][nL]); return; }
  int nM=nL+nR>>1;
  // 往下遞迴直到最底層
  mergeSort(deep+1,  nL,nM);
  mergeSort(deep+1,nM+1,nR);
  // ---合併兩棵子樹的數列---
  int idxL=nL, idxR=nM+1, top=nL;
  while(idxL<=nM and idxR<=nR){
    if(seg[deep+1][idxL]<seg[deep+1][idxR])
      seg[deep][top++]=seg[deep+1][idxL++];
    else
      seg[deep][top++]=seg[deep+1][idxR++];
  }
  while(idxL<=nM) seg[deep][top++]=seg[deep+1][idxL++];
  while(idxR<=nR) seg[deep][top++]=seg[deep+1][idxR++];
}
int query(int deep,int nL,int nR){
  if(qL<=nL and nR<=qR) // 區段落在查詢的範圍時計算大於qH的個數
    return upper_bound(seg[deep]+nL,seg[deep]+nR+1,qH)-seg[deep]-nL;
  int nM=nL+nR>>1, ret=0;
  if(qL<=nM) ret+=query(deep+1,  nL,nM);
  if(qR>nM ) ret+=query(deep+1,nM+1,nR);
  return ret;
}
int main(){
  int caseT, N, Q;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d%d",&N,&Q);
    // 到達葉節點時才讀取原始資料
    mergeSort(0,0,N-1);
    // 在線查詢：線段樹維護每個『排序好的片段』，針對每個片段都做二分搜尋
    while(Q--)
      scanf("%d%d%d",&qL,&qR,&qH),
      printf("%d\n",query(0,0,N-1));
  }
}
/*
1
10 10
0 5 2 7 5 4 3 8 7 7
2 8 6
3 5 0
1 3 1
1 9 4
0 1 0
3 5 5
5 5 1
4 6 3
1 5 7
5 7 3
*/