// 負數版本的質因數分解
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> prime;
int main(){
  int bound=sqrt(0x7fffffff);
  vector<bool>isPrime(bound,true);
  isPrime[0]=isPrime[1]=false;

  for(int j=4;j<=bound;j+=2)
    isPrime[j]=false;
  for(int i=3;i<=sqrt(bound);i+=2)
    if(isPrime[i])
      for(int k=i+i, j=i+k;j<=bound;j+=k)
        isPrime[j]=false;
  prime.push_back(2);
  for(int i=3;i<=bound;i+=2)
    if(isPrime[i])
      prime.push_back(i);
  // 輸出
  bound=prime.size();
  for(int n;cin>>n and n;){
    cout<<n<<" = ";
    vector<int> f;
    if(n<0) f.push_back(-1),  n*=-1;
    for(int i=0;i<bound and n>1;i++)
      for(; n%prime[i]==0; n/=prime[i])
        f.push_back(prime[i]);
    if(n>1) f.push_back(n);
    cout<<f[0];
    for(int i=1;i<f.size();i++)
      cout<<" x "<<f[i];
    cout<<endl;
  }
}