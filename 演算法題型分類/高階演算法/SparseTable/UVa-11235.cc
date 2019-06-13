// 題解(zkwSegmentTree)：http://naivered.github.io/2018/05/20/Problem_Solving/UVa/UVa-11235-Frequent-values/
// 題解(SparseTable)：https://blog.csdn.net/MIKASA3/article/details/52153601
// 想法：題目只要求做區間查詢且次數高達1e5 => SparseTable
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+1;
int N, Q, H;
int num[MAXN];
int bound_L[MAXN];
int bound_R[MAXN];
int ST[18][MAXN]; // __lg(MAXN)=16

inline bool scanInt(int &x){
  char c=getchar();
  bool sign=c=='-';
  for(x=(sign)?0:(c-'0');(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
  return c!=EOF;
}
int Query_part(int qL,int qR){
  // ---查詢範圍落在某個連續數列的區間內---
  if(num[qL]==num[qR])
    return qR-qL+1;
  // ---查詢範圍內有兩個以上的連續數列---
  /* 判斷左/右邊界是不是剛好是連續區間的開頭/結尾
   * 若不是，代表 cnt[x] 紀錄的連續個數是錯誤的必須重新計算個數，並更新區間左右邊界
   */
  int sideL=0, sideR=0, sideM=0;
  if(qL!=bound_L[qL]) sideL=bound_R[qL]-qL+1, qL=bound_R[qL]+1;
  if(qR!=bound_R[qR]) sideR=qR-bound_L[qR]+1, qR=bound_L[qR]-1;
  if(qL<=qR){
    int h_ST=__lg(qR-qL+1);
    sideM=max(ST[h_ST][qL], ST[h_ST][qR-(1<<h_ST)+1]);
  }
  return max(max(sideL,sideR),sideM);
}
int main(){

  while(scanInt(N) and N){
    scanInt(Q);
    // ---邊讀取邊紀錄連續個數和左右邊界---
    scanInt(num[1]);
    int now_v=num[1], pre=1, cnt;
    for(int idx=2;idx<=N;idx++){
      scanInt(num[idx]);
      if(now_v!=num[idx]){
        cnt=idx-pre;
        for(int i=pre;i<idx;i++)
          ST[0][i]=cnt,
          bound_L[i]=pre,
          bound_R[i]=idx-1;
        pre=idx,
        now_v=num[idx];
      }
    }
    // ---最後一段的連續值---
    cnt=N+1-pre;
    for(int i=pre;i<=N;i++)
      ST[0][i]=cnt,
      bound_L[i]=pre,
      bound_R[i]=N;
    // ---建 Sparse Table 做區間查詢---
    for(int h=0;(1<<h)<N;h++)
      for(int st=1;st+(1<<h)<=N;st++)
        ST[h+1][st]=max(ST[h][st],ST[h][st+(1<<h)]);
    // ---區間查詢---
    for(int qL,qR; Q--;)
      scanInt(qL),
      scanInt(qR),
      printf("%d\n",Query_part(qL,qR));
  }
}
/*
10 3
-1 -1 1 1 1 1 3 10 10 10

*/