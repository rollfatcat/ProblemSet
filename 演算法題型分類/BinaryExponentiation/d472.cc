// 快速冪次+質數表
#include<iostream>
#include<vector>
using namespace std;
#define mod 76543

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  // seive
  vector<int> prime;
  bool notPrime[10001]={};
  for(int i=4;i<=10000;i+=2)
    notPrime[i]=1;
  for(int i=3;i<=100;i+=2)
    if(!notPrime[i])
      for(int k=i<<1, j=k+i; j<=10000;j+=k)
        notPrime[j]=1;
  for(int i=2;i<=10000;i++)
    if(!notPrime[i])
      prime.push_back(i);
  //
  unsigned long ans=1, base;
  for(int p,idx=0; cin>>p; idx++){
    base=prime[idx];
    if(p&1) ans=ans*base%mod;
    for(p>>=1; p>0; p>>=1){
      base=base*base%mod;
      if(p&1)
        ans=ans*base%mod;
    }
  }
  printf("%lu\n",ans);
}