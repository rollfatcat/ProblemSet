/* (高難度問題)數組內差距的中位數 => 二分搜尋中位數
 * (X) 數字的個數高達 1e5 個，枚舉任兩個數字算差值的話，差值的個數會有 5e9 個
 * (O) 二分法在可能的範圍內做嘗試( 題目保證 0 < Ai ≦ 1e9 )
 * 如何將找出中位數的問題轉換為二分法做暴力搜尋？ => 個數計算
 * 中位數的定義：所有數值有一半小於這個數值且有一半大於，
 * 換句話說，#小於中位數 < Ｃ(n,2) ≦ #小於等於中位數
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;
int node[MAXN];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  int nodeCnt;
  while(scanInt(nodeCnt)){
    for(int i=0;i<nodeCnt;i++)
      scanInt(node[i]);
    sort(node,node+nodeCnt);
    // Main Function
    long allCnt=(long)nodeCnt*(nodeCnt-1)>>1;
    /* 中位數的定義：所有差值有一半的個數小於這個數值且有一半的個數大於『估測值』
     * #『小於估測值』 < Ｃ(n,2) ≦ #『小於等於估測值』
     * lowerCnt < midCnt ≦ upperCnt
     */
    long midCnt=(allCnt>>1)+(allCnt&1);
    int nL=1, nR=1e9, nM, st;
    while(nL<nR){
      nM=nL+nR>>1; // 透過左右端點推算出中間點作為這次的猜測值
      int idx=lower_bound(node,node+nodeCnt,nM)-node;
      bool IsIn=0;
      long lowerCnt=0;
      long upperCnt=0;
      /* 線性枚舉每個數對的起點，『線性搜尋』落在差值(等於可能中間值)的另一個終點位置
       * 根據現在的『估算值』計算『小於』這個差值的#數對 和 『小於等於』這個差值的#數對
       */
      for(st=0;st<nodeCnt;st++){
        // 計算『小於』這個差值的#數對
        while(idx<nodeCnt and node[idx]-node[st]<nM)  idx++;
        lowerCnt+=idx-1-st;
        // 計算『小於等於』這個差值的#數對
        while(idx<nodeCnt and node[idx]-node[st]<=nM) idx++;
        upperCnt+=idx-1-st;
        // 檢測中間值存在
        IsIn|=node[idx-1]-node[st]==nM;
      }
      // 差值存在 且 這個估算出來的差值落在『中間值』的定義範圍內
      if(IsIn and upperCnt>=midCnt and midCnt>lowerCnt) break;
      (upperCnt<midCnt)? nL=nM+1: nR=nM;
    }
    printf("%d\n",nM);
  }
}
/*
3
1 3 9
///
2 6 8 => 6
===
5
1 3 3 3 5
///
0 0 0 2 2 2 2 2 2 4 => 2
*/