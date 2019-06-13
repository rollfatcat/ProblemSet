#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main(){
  bool isPrime[1001];
  memset(isPrime,0xff,sizeof(isPrime));
  isPrime[0]=isPrime[1]=0;
  // 找到1000以下的質數就可以推出1000000以內的質數
  vector<int> prime;
  for(int i=2;i<32;i++)
    if(isPrime[i]){
      prime.push_back(i);
      for(int j=2;i*j<=1000;j++)
        isPrime[i*j]=0;
    }
  for(int i=32;i<=1000;i++)
    if(isPrime[i])
      prime.push_back(i);
  int n;
  while(cin>>n and n){
    cout<<n<<" : ";
    int p=0;
    for(int i=0;i<prime.size() and n>1;i++){
      if(n%prime[i]==0) p++;
      while(n%prime[i]==0)  n/=prime[i];
    }
    if(n>1) p++;
    cout<<p<<endl;
  }
}