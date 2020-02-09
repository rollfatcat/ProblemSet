#include<bits/stdc++.h>
using namespace std;

const int MAXN=5000000;
const int H=__lg(MAXN);
int ST[H+1][MAXN];
inline void scanInt(int &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
}
int main(){
  int N, Q, qL, qR;
  scanInt(N);
  for(int i=0;i<N;i++)
    scanInt(ST[0][i]);
  // --- 建樹 ---
  for(int h=0;h<__lg(N);h++)
    for(int st=0;st+(1<<h)<=N;st++)
      ST[h+1][st]=max(ST[h][st],ST[h][st+(1<<h)]);
  // ---區間查詢---
  for(scanInt(Q); Q--;){
    scanInt(qL),  scanInt(qR);
    if(qL>qR) qL^=qR^=qL^=qR;
    int h=__lg(qR-qL+1);
    printf("%d\n",max(ST[h][qL-1],ST[h][qR-(1<<h)]));
  }
}