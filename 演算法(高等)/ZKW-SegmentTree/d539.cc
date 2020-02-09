// zkw線段樹練習(極值轉換成差分)
#include<bits/stdc++.h>
using namespace std;

const int MAXN=5000002;
int zkwtr[MAXN<<2];
inline void scanInt(int &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
}
int main(){
  int N, Q, qL, qR;
  scanInt(N);
  // ---讀取測資到leaf＋建樹---
  int M=1<<(__lg(N)+1);
  for(int i=M+1; i<=M+N; i++)
    scanInt(zkwtr[i]);
  for(int i=M-1; i;i--)
    zkwtr[i]=max(zkwtr[i<<1],zkwtr[i<<1|1]),
    zkwtr[i<<1]-=zkwtr[i], zkwtr[i<<1|1]-=zkwtr[i];

  for(scanInt(Q); Q--;){
    scanInt(qL),
    scanInt(qR);
    if(qL>qR) qL^=qR^=qL^=qR;
    // ---區間極值查詢---
    int L=0, R=0, maxN=0;
    qL+=M, qR+=M;
    if(qL!=qR){
      for(; qL^qR^1; qL>>=1,qR>>=1){
        L+=zkwtr[qL],
        R+=zkwtr[qR];
        if(~qL&1) L=max(L,zkwtr[qL^1]);
        if(qR&1)  R=max(R,zkwtr[qR^1]);
      }
    }
    for(maxN=max(L+zkwtr[qL],R+zkwtr[qR]); qL;qL>>=1)
      maxN+=zkwtr[qL>>1];
    printf("%d\n",maxN);
  }
}
/*
10
3 2 4 5 6 8 1 2 9 7
10
1 5
3 5
1 10
5 8
6 6
2 4
2 9
*/