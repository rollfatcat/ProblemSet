// 範圍不大的綜合題，質因數分解+最大公因數+質數判斷
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

bool isPrime[65537];
int GCD(int a,int b){ return(a%b)?GCD(b,a%b):b; }
int main(){
  vector<int>prime;
  memset(isPrime,true,sizeof(isPrime));
  isPrime[0]=isPrime[1]=0;
  prime.push_back(2);
  for(int i=4;i<=65536;i+=2)
    isPrime[i]=0;
  for(int i=3;i<=256;i+=2)
    if(isPrime[i]){
      prime.push_back(i);
      for(int k=i<<1,j=i+k;j<=65536;j+=k)
        isPrime[j]=0;
    }
  int n; cin>>n;
  for(int a,b; n--;){
    cin>>a>>b;
    // 對a做質因數分解
    bool first=true;
    int num=a;
    for(int i=0; i<prime.size() and num; i++){
      int Np=0;
      for(; num%prime[i]==0; num/=prime[i],Np++);
      if(Np>0){
        if(!first)  cout<<'*';
        cout<<prime[i];
        first=false;
        if(Np>1)  cout<<'^'<<Np;
      }
    }
    if(num>1){
      if(!first)  cout<<'*';
      cout<<num;
    }
    // GCD(a,b)
    int gcd=GCD(a,b);
    cout<<" , "<<gcd<<" , "<<( (isPrime[gcd])?'Y':'N')<<endl;
  }
}