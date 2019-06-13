// 計算 N! 的質因數個數+二分搜尋法
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

vector<int> fac;
int BS(int x){
  int l=0,r=fac.size()-1,m;
  while(l<=r){
    m=(l+r)>>1;
    if(x==fac[m])  return m;
    else if(x>fac[m])  l=m+1;
    else r=m-1;
  }
  return -1;
}
int main(){
  // 建表: 範圍是 2703665 內
  vector<int>prime, p2;
  int bound=sqrt(2703665);
  bool isPrime[bound+1];
  memset(isPrime,0xff,sizeof(isPrime));
  isPrime[0]=isPrime[1]=0;
  prime.push_back(2),
  p2.push_back(4);
  for(int i=4;i<=bound;i+=2)
    isPrime[i]=0;
  for(int i=3;i<=sqrt(bound);i+=2)
    if(isPrime[i])
      for(int k=i<<1,j=i+k;j<=bound;j+=k)
        isPrime[j]=0;
  for(int i=3;i<=bound;i+=2)
    if(isPrime[i])
      prime.push_back(i),
      p2.push_back(i*i);
  prime.push_back(1657),
  p2.push_back(1657*1657);
  // 推算
  fac.push_back(0),
  fac.push_back(0),
  fac.push_back(1),
  fac.push_back(2);
  int now=4;
  for(int cnt=2; cnt<=10000001; now++){
    int num=now;
    for(int idx=0; p2[idx]<=num; idx++){
      int Np=0;
      for(;num%prime[idx]==0; num/=prime[idx],Np++);
      if(Np) cnt+=Np;
    }
    if(num>1) cnt++;
    fac.push_back(cnt);
  }
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  //查表+二分搜尋
  for(int n, caseN=1; cin>>n and n>=0; caseN++){
    if(n==0){ cout<<"Case "<<caseN<<": 0!"<<endl; continue; }
    n=BS(n);
    if(n==-1) cout<<"Case "<<caseN<<": Not possible."<<endl;
    else  cout<<"Case "<<caseN<<": "<<n<<"!"<<endl;
  }
}