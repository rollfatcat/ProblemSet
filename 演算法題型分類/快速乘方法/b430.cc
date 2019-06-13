// 實作前可以先教大數運算
// 避免大數乘法：快速乘方法的想法套用在加法上
#include<iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long int a, b, n, mod;
  while(cin>>a>>b>>mod){
    a%=mod, b%=mod;
    if(a>b) n=a, a=b, b=n;
    for(n=0; b>0; a=(a<<1)%mod, b>>=1 )
      if(b&1)
        n=(n+a)%mod;
    cout<<n<<endl;
  }
}