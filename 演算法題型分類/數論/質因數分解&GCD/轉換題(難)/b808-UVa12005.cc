// 題解：求(a,b)的問題可以轉化成 (2a-1)(2b-1)=4c-3
// 對 4c-3 做質因數分解，因為4c-3必定是奇數所以2a-1和2b-1必定有解，算出所有因數個數即可

#include<bits/stdc++.h>
using namespace std;

bool notP[20000001]={};
int main(){
  // sieve
  notP[0]=notP[1]=1;
  for(int i=4;i<20000000;i+=2)
    notP[i]=1;
  for(int i=3;i<=4473;i+=2) // 4473=sqrt(20000000)
    if(!notP[i])
      for(int k=i<<1,j=i+k;j<20000000;j+=k)
        notP[j]=1;
  vector<int>prime;
  for(int i=2;i<20000000;i++)
    if(!notP[i])
      prime.push_back(i);
  // main
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(long c;cin>>c and c;){
    cout<<c<<' ';
    c=(c<<2)-3;
    vector<int> power;
    for(int i=0;i<prime.size() and c>=(long)prime[i]*prime[i];i++){
      int p;
      for(p=0;c%prime[i]==0;c/=prime[i],p++);
      if(p)
        power.push_back(p);
    }
    if(c>1) power.push_back(1);
    int cnt=1;
    for(int i=0;i<power.size();i++)
      cnt*=(power[i]+1);
    cout<<cnt<<'\n';
  }
}