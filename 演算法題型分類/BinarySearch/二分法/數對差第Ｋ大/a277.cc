// (高難度問題)數組內差距的中位數 => 二分搜尋中位數
// 題解：http://mypaper.pchome.com.tw/zerojudge/post/1322549212
/* 測資的個數高達 1e5 個，枚舉任兩點算差值的話，差值的個數會有 5e9 個
 * 二分法在可能的範圍內暴力搜索( 題目保證0<Ai<=1000000000 )
 * 如何使用二分法暴力搜尋？ => 轉成個數計算
 * 中位數的定義：所有數值有一半小於這個數值且有一半大於
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100000;
int node[MAXN];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  for(int nodeN;scanInt(nodeN);){
    for(int i=0;i<nodeN;i++)
      scanInt(node[i]);
    sort(node,node+nodeN);
    // Main Function
    long allN=(long)nodeN*(nodeN-1)>>1;
    long limitCnt=(allN>>1)+(allN&1);
    long lowerCnt, upperCnt;
    int nL=1, nR=1000000000, nM, st;
    bool IsIn;
    while(nL<=nR){
      nM=(nL+nR)>>1;
      int idxL=0, idxU=0;
      IsIn=upperCnt=lowerCnt=0;
      /* 枚舉每個數對的起點，(1)『線性搜尋』落在差值(等於可能中間值)的另一個終點位置
       *                     (2)『二分搜尋』
       * (1) 0.2s => 註解的部分，總體來說時間是線性(只把整個陣列掃過一遍)
       * (2) 0.3s => 利用lower_bound和upper_bound實作
       */
      for(st=0;st<nodeN;st++){
        //for(; idxL<nodeN and node[idxL]-node[st]<nM ; idxL++);
        idxL=lower_bound(node+idxL,node+nodeN,node[st]+nM)-node;
        lowerCnt+=idxL-1-st;

        //for(; idxU<nodeN and node[idxU]-node[st]<=nM; idxU++);
        idxU=upper_bound(node+idxU,node+nodeN,node[st]+nM)-node;
        upperCnt+=idxU-1-st;
        // 中間值存在( 是某對數值的差值 )
        IsIn|=(node[idxU-1]-node[st]==nM);
      }
      // 差值存在 且 這個估算出來的差值落在『中間值』的定義範圍內
      if(IsIn and upperCnt>=limitCnt and limitCnt>lowerCnt) break;
      if(upperCnt<limitCnt) nL=nM+1;
      else  nR=nM-1;
    }
    printf("%d\n",nM);
  }
}
/*
3
1 3 9

5
1 3 3 3 5
////
0 0 0 2 2 2 2 2 2 4 => 2
*/