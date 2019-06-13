// 模板題
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;
const int H=__lg(MAXN)+2;
unsigned int maxST[H][MAXN];
unsigned int minST[H][MAXN];
inline void scanInt(unsigned int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  unsigned int N, Q;

  // ---讀取資料---
  scanInt(N), scanInt(Q);
  minST[0][0]=0xffffffff,
  maxST[0][0]=0;
  for(int i=1;i<=N;i++)
    scanInt(maxST[0][i]),
    minST[0][i]=maxST[0][i];
  // ---建樹---
  for(int h=0;(1<<h)<N;h++)
    for(int st=1;st+(1<<h)<=N;st++)
      maxST[h+1][st]=max(maxST[h][st],maxST[h][st+(1<<h)]),
      minST[h+1][st]=min(minST[h][st],minST[h][st+(1<<h)]);
  for(unsigned int qL,qR; Q--;){
    scanInt(qL),
    scanInt(qR);
    if(qL>qR) qL^=qR^=qL^=qR;
    int w=qR-qL+1,  h_ST=__lg(w);
    int maxD=max(maxST[h_ST][qL],maxST[h_ST][qR-(1<<h_ST)+1]),
        minD=min(minST[h_ST][qL],minST[h_ST][qR-(1<<h_ST)+1]);
    printf("%u\n",maxD-minD);
  }
}
/*
8 3
5 7 3 1 9 7 10 11
*/