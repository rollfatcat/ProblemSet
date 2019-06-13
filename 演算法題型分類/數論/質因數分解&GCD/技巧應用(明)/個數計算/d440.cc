// 題目問小於所有Ｎ且和Ｎ互質的個數(Ｎ≦ 1e9)
// 建表＋排容(尤拉公式)
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1e9

int N, Layerall;
vector<int> base;
vector<int> prime; // 3401th prime is 31607
inline void seive(int bound){
  vector<bool> NotPrime(bound+1,0);
  for(int i=4;i<=bound;i+=2)
    NotPrime[i]=true;
  int sbound=sqrt(bound); // sqrt(1e9)=31622
  for(int i=3;i<=sbound;i+=2)
    for(int j=3;i*j<=bound;j+=2)
      NotPrime[i*j]=true;
  prime.push_back(2);
  for(int i=3;i<=bound;i+=2)
    if(NotPrime[i]==0)
      prime.push_back(i);
}
void DFS(int pickNum,int st,int LCM){
  if(pickNum==0){ Layerall+=N/LCM; return; }
  for(int i=st;i<=base.size()-pickNum;i++)
    DFS(pickNum-1,i+1,LCM*base[i]);
}

int main(){
  seive(sqrt(MAXN));
  //
  while(scanf("%d",&N) and N){
    // 質因數分解(只需要基底)
    int cN=N; base.clear();
    for(int i=0; i<prime.size() and prime[i]<=cN; i++){
      if(cN%prime[i]==0) base.push_back(prime[i]);
      for( ;cN%prime[i]==0;cN/=prime[i]);
    }
    if(cN>1) base.push_back(cN);
    cN=N;
    for(int pickNum=1;pickNum<=base.size();pickNum++)
      Layerall=0,
      DFS(pickNum,0,1),
      cN+=(pickNum&1)? -Layerall: Layerall;
    printf("%d\n",cN-(N==1));
  }
}