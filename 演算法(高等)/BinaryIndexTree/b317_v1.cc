// 不需要BIT，以動態規劃的二維陣列解題(9ms)
#include<iostream>
using namespace std;

int DP[101][101]={};
int main(){
  int N, K, R, H;
  scanInt(N),
  scanInt(K);
  while(N--)
    scanInt(R),
    scanInt(H),
    DP[R][H]++;
  if(K==0){ puts("0"); return 0; }
  for(R=1;R<=100;R++)
    for(H=1;H<=100;H++)
      DP[R][H]+=(DP[R-1][H]+DP[R][H-1]-DP[R-1][H-1]);
  int minV=1<<30;
  for(R=1;R<=100;R++){
    for(H=1;H<=100 and DP[R][H]<K;H++);
    if(H<=100)
      minV=min(minV,(R*R*H)<<2);
  }
  printf("%d\n",minV);
}