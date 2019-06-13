// 輸出5th完全數(因數和=本身數值)
// 一邊找完全數一邊對質數建表會TLE, 需要搭配梅森質數性質
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int>prime;
int main(){

  prime.push_back(2);
  for(int N=3; ; N++){
    int n=N, cnt=1, p;
    for(int i=0;i<prime.size() and prime[i]*prime[i]<=n and n>1;i++)
      if(n%prime[i]==0){
        for(p=0; n%prime[i]==0 and n>1; n/=prime[i],p++);
        cnt*=((pow(prime[i],p+1)-1)/(prime[i]-1));
      }
    if(n==N){  prime.push_back(n); continue; }
    if(n>1) cnt*=(n+1);
    if(cnt==(N<<1) and N>8128){  cout<<N<<endl; break; }
  }
}