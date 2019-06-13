// 此題有規則解(0ms)，可以和c519一起看，但也可以用簡單模擬(0.6s)
/* 規則寫得很複雜...，但概括就是往左上移動，超過邊界就overflow
 * 直到這一整個斜條都被填滿往下一斜條填
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  int T, N, tR, tC;
  for(scanf("%d",&T);T--;){
    scanf("%d %d %d",&N,&tR,&tC), tR--, tC--;
    // ---先計算落在哪一條直線上，直線範圍是(-N/2,N/2)---
    int coff=tC-tR, hN=N>>1;
    if(coff> hN) coff-=N;
    if(coff<-hN) coff+=N;

    int x=0, y=hN;
    for(int t=0;t<hN-coff;t++)
      x=(x+2)%N, y=(y+1)%N;
    int num=1+(hN-coff)*N;
    while(x!=tR and y!=tC)
      num++,
      x=(x)?(x-1):(N-1),
      y=(y)?(y-1):(N-1);
    printf("%d\n",num);
  }
}