// cin/cout：0.5s, printf/scanf：80ms
#include<iostream>
using namespace std;
#define MaxN 1000001

int main(){
  bool isPrime[MaxN]={0};
  isPrime[0]=isPrime[1]=1;
  for(int i=2;i<=1000;i++)
    if(isPrime[i]==0)
      for(int j=2;i*j<=1000000;j++)
        isPrime[i*j]=1;
  int n;
  while(scanf("%d",&n) and n)
    printf("%d\n",isPrime[n]);
}