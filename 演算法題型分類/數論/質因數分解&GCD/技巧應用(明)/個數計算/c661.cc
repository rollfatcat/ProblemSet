// 分別找出範圍內 5的倍數的個數，25的倍數的個數，125的倍數的個數...累加起來即可
#include<bits/stdc++.h>
using namespace std;

int nL, nR;
inline long powerK(int mod){
  long L=nL/mod, R=nR/mod;
  long res=(1+nR-nR/mod*mod)*R-(nL-nL/mod*mod)*L;
  res+=(R-1+L)*(R-L)/2*mod;
  return res;
}
int main(){
  int caseT;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d %d",&nL,&nR);
    long sum=0;
    for(long i=5;i<=nR;i*=5)
      sum+=powerK(i);
    printf("%ld\n",sum);
  }
}
//  5 -  9 : 1
// 10 - 14 : 2
// 15 - 19 : 3
// 20 - 24 : 4
// 25 - 24 : 6