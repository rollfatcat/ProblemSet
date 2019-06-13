// 判斷輸入的數字和反轉後的數字是否是質數
#include<bits/stdc++.h>
using namespace std;

bitset<1000000> NotPrime(0);
int main(){
  // seive
  NotPrime[0]=NotPrime[1]=1;
  for(int i=4;i<1000000;i+=2)
    NotPrime[i]=1;
  for(int i=3;i<1000000;i+=2)
    if(NotPrime[i]==0)
      for(int j=3;i*j<1000000;j+=2)
        NotPrime[i*j]=1;
  // Main
  int N, Nreverse, cN;
  while(scanf("%d",&N)!=EOF){
    printf("%d ",N);
    if(NotPrime[N])  puts("is not prime.");
    else{
      for(cN=N,Nreverse=0;cN;Nreverse=10*Nreverse+cN%10,cN/=10);
      puts( (N==Nreverse or NotPrime[Nreverse])? "is prime.": "is emirp.");
    }
  }
}