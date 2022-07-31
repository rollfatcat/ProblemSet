/* 第ｉ位的答案就是在未選的數中第 Ki 小的 => 如何確定未選的數中第Ｋ小的數
 * 用樹狀數组，维護數字i之前有多少个數被取走了。該操作屬於單點修改 + 區間查詢。
 * 這樣如果 i-BIT[i]>=k，那麼ｉ這個位置就是可選的。
 * 用二分法找滿足條件的最小的ｉ
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e4+1;
short BIT[MaxN]={};

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
inline int lowbit(int x){ return -x&x; }
int main(){
  int caseN, N, qN;
  for(scanInt(caseN);caseN--;){
    scanInt(N);
    // ---建樹---
    fill(BIT+1,BIT+N+1,1);
    for(int uppos,i=1;i<=N;i++)
      if( (uppos=i+lowbit(i))<=N )
        BIT[uppos]+=BIT[i];
    // 第一個數字最容易處理，方便輸出就獨立出來
    scanInt(qN), qN++;
    for(int i=qN;i<=N;i+=lowbit(i))
      BIT[i]--;
    printf("%d",qN);
    for(int i=1;i<N;i++){
      scanInt(qN), qN++;
      int qL, qR, qM, rank;
      for(qL=1,qR=N;qL<qR;){
        qM=(qL+qR)>>1;
        rank=0;
        for(int j=qM;j;j-=lowbit(j))
          rank+=BIT[j];
        if(rank>=qN) qR=qM;
        else qL=qM+1;
      }
      printf(" %d",qL);
      for(int j=qL;j<=N;j+=lowbit(j))
        BIT[j]--;
    }
    puts("");
  }
}