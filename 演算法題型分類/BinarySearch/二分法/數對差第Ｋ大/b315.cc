/* (高難度問題)數列內差距的第Ｋ大的差值 => 二分法暴力搜尋
 * (X) 數字的個數高達 1e5 個，枚舉任兩個數字算差值的話，差值的個數會有 5e9 個
 * (O) 二分法在可能的範圍內做嘗試( 題目保證 0 ≦ Ai ≦ 1e9 )
 * 如何將找出第Ｋ大差值的問題轉換為二分法做暴力搜尋？ => 個數計算＋夾擊的概念
 * 第Ｋ大的定義：小於目前的猜測值的差值有Ｃ(n,2)－Ｋ＋1個
 * 換句話說，#小於中位數 < Ｃ(n,2)-K+1 ≦ #小於等於中位數(夾擊於區間內)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;
const int INF=1<<30;
int num[MAXN];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  int N, K;

  scanInt(N);
  scanInt(K);
  int nR=0, nL=INF;
  for(int i=0;i<N;i++)
    scanInt(num[i]),
    nR=max(nR,num[i]),
    nL=min(nL,num[i]);

  // 排序：方便線性枚舉起點時根據猜測的差值算出終點
  sort(num,num+N);
  long Kcnt=((long)N*(N-1)>>1)-K+1; // 將第Ｋ大轉換成需要贏過多少個
  int nM, st, ed;
  nR=nR-nL, nL=0;
  while(nL<nR){
    nM=nL+nR>>1;
    bool IsIn=0;
    long lower_cnt=0;
    long upper_cnt=0;
    int st, ed=lower_bound(num,num+N,nM)-num;
    for( st=0; st<N; st++){
      // 小於猜測值的個數
      while(ed<N and num[ed]-num[st]<nM)  ed++;
      lower_cnt+=ed-1-st;
      // 小於等於猜測值的個數
      while(ed<N and num[ed]-num[st]<=nM) ed++;
      upper_cnt+=ed-1-st;
      // 猜測的差值存在
      IsIn|=num[ed-1]-num[st]==nM;
    }
    // 猜測的差值存在且收斂於正確的位置
    if(IsIn and lower_cnt<Kcnt and Kcnt<=upper_cnt) break;
    (lower_cnt<Kcnt)? nL=nM+1: nR=nM;
  }
  printf("%d\n",nM);
}
/*
4 5
1 5 8 10
*/