// 質數判斷(範圍=1e4)精確度問題：加上ESP來看進位的情況, 通常是[1e-6,1e-8]
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define ESP 1e-8

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  vector<int> isPrime(10002,1);
  vector<int> prime;
  prime.push_back(2);
  for(int j=4;j<=10000;j+=2)
    isPrime[j]=0;
  for(int i=3;i<=100;i+=2)
    if(isPrime[i])
      for(int k=i+i, j=i+k;j<=10001;j+=k)
        isPrime[j]=0;
  for(int i=3;i<=10001;i+=2)
    if(isPrime[i])
      prime.push_back(i);

  for(int i=0;i<40;i++)
    isPrime[i]=i+1;
  isPrime[41]=isPrime[40]=isPrime[39];

  for(int i=42;i<=10000;i++){
    int num=i*i+i+41;
    int bound=sqrt(num), flag=1;
    for(int j=0;j<prime.size() and prime[j]<=bound;j++)
      if(num%prime[j]==0)
        flag=0;
    isPrime[i]=isPrime[i-1]+((flag)?1:0);
  }

  for(int a, b; cin>>a>>b;){
    int L=(a==0)?0:isPrime[a-1];
    printf("%.2lf\n", 100.00*(isPrime[b]-L)/(b-a+1)+ESP );
  }
}