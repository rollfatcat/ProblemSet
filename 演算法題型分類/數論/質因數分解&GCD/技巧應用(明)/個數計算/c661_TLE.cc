#include<bits/stdc++.h>
using namespace std;

inline long power5(int num,long res=0){
  for(;num;num/=5)
    res+=(num/5);
  return res;
}
int main(){
  int caseT, nL, nR;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d %d",&nL,&nR);
    long sum=0;
    for(int i=nL;i<=nR;i++)
      sum+=power5(i);
    printf("%ld\n",sum);
  }
}