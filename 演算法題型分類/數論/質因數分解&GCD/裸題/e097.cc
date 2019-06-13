// 接續題：b539，完成後再挑戰這題
#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
inline void seive(int N){
  int Ns=sqrt(N);
  vector<bool> NotPrime(N+1,0);
  NotPrime[0]=NotPrime[1]=1;
  for(int i=4;i<=N;i+=2)
    NotPrime[i]=1;
  for(int i=3;i<=Ns;i+=2)
    for(int j=3;i*j<=N;j+=2)
      NotPrime[i*j]=1;
  prime.push_back(2);
  for(int i=3;i<=N;i+=2)
    if(NotPrime[i]==0)
      prime.push_back(i);
}
int main(){
  // 題目沒說不過輸入的最大值落在2^31以內
  int caseT, A, M;
  scanf("%d %d %d",&caseT,&A,&M);
  // 用『埃式篩法』找齊 最大值根號 範圍內的所有質數
  seive(sqrt(A));

  // 主程式
  int B, P, H, t;
  while(caseT--){
    scanf("%d %d %d",&B,&P,&H);
    // 質因數分解
    vector<int> base, powr;
    for(int p,i=0;i<prime.size() and B>1;i++){
      for(p=0;B%prime[i]==0;p++,B/=prime[i]);
      if(p) base.push_back(prime[i]), powr.push_back(p);
    }
    if(B>1) base.push_back(B), powr.push_back(1);
    // 轉成輸出格式：不需要快速幂加速
    long b=1, c=1;
    for(int i=0;i<base.size();i++){
      t=powr[i]*P/H;
      for(int j=1;j<=t;j++) b*=base[i];
      t=powr[i]*P-t*H;
      for(int j=1;j<=t;j++) c*=base[i];
    }
    printf("%ld %ld\n",b,c);
  }
}
/*
2 1000 100
108 5 10
15 3 2
*/