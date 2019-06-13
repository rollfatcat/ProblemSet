// 判斷大範圍的質數
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
bool scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); return c!=EOF; }
int main(){
  vector<int>prime;
  int bound=sqrt(2147483647);
  bool isPrime[bound+1];

  memset(isPrime,true,sizeof(isPrime));
  isPrime[0]=isPrime[1]=0;
  prime.push_back(2);
  for(int i=4;i<=bound;i+=2)
    isPrime[i]=0;
  for(int i=3;i<=sqrt(bound);i+=2)
    if(isPrime[i]){
      prime.push_back(i);
      for(int k=i<<1,j=i+k;j<=bound;j+=k)
        isPrime[j]=0;
    }
  for(int i=sqrt(bound);i<=bound;i+=2)
    if(isPrime[i])
      prime.push_back(i);
  // 質數判斷
  for(int n; scanInt(n);){
    int idx=0;
    for(;idx<prime.size() and prime[idx]*prime[idx]<=n and n%prime[idx]; idx++);
    if(idx==prime.size() or prime[idx]*prime[idx]>n) puts("質數");
    else puts("非質數");
  }
}