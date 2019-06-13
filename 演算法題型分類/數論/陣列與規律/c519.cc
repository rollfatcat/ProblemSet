// 因為 N=10^9 得設法找出規律解
#include<bits/stdc++.h>
using namespace std;

int main(){
  long N, K;
  scanf("%ld %ld",&N,&K);
  // ---先找出號碼落在哪一條直線方程式上面---
  int t=(K-1)/N,
      x=(t<<1)%N,
      y=(N>>1)-t;
  if(y<0) y+=N;
  // ---從這一條的起點往右上角前進 d 步---
  int d=K-1-(K-1)/N*N;
  x-=d, y+=d;
  if(x<0) x+=N;
  if(y>=N) y-=N;
  printf("%d %d\n",x+1,y+1);
}