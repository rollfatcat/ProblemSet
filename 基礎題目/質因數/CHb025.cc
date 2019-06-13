#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int x, y;
int len=11, Prime[11]={2,3,5,7,11,13,17,19,23,29,31};
int power[11];
int PrimeFactorization(int x, int w){
  for(int i=0;x>=1 and i<len;i++)
    for(; x%Prime[i]==0; x/=Prime[i])
      power[i]+=w;
  return x;
}
int main(){
  cin>>x>>y;
  int z=x+y;
  memset(power,0,sizeof(power));
  vector<int> otherPrime;
  for(int i=x+1;i<=z;i++){
    int tmp=PrimeFactorization(i,1);
    if(tmp>1)
      otherPrime.push_back(tmp);
  }
  for(int i=2;i<=y;i++)
    PrimeFactorization(i,-1);
  //
  unsigned long long int ans=1;
  for(int i=0;i<len;i++)
    for(int j=0;j<power[i];j++)
      ans*=Prime[i];
  for(int i=0;i<otherPrime.size();i++)
    ans*=otherPrime[i];
  cout<<ans<<endl;
}