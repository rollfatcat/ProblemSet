// 前置題：e097，完成後再挑戰這題
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100000000;
struct PAIR{long u,v;};
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
inline void reduce(long &x,long &y){
  long GCD=__gcd(x,y);
  x/=GCD, y/=GCD;
}
inline PAIR factor(int B,int P,int H){
  vector<int> base, powr;
  for(int p,i=0;i<prime.size() and B>1;i++){
    for(p=0;B%prime[i]==0;p++,B/=prime[i]);
    if(p) base.push_back(prime[i]), powr.push_back(p);
  }
  if(B>1) base.push_back(B), powr.push_back(1);
  // 轉成輸出格式：不需要快速幂加速
  PAIR ans={1,1};
  for(int t,i=0;i<base.size();i++){
    t=powr[i]*P/H;
    for(int j=1;j<=t;j++) ans.u*=base[i];
    t=powr[i]*P-t*H;
    for(int j=1;j<=t;j++) ans.v*=base[i];
  }
  return ans;
}

int main(){
  // 題目保證輸入的數字小於100,000,000，建表範圍＝10,000
  seive(sqrt(MAXN));

  long a, b, c, d;
  while(scanf("%ld %ld",&a,&b)==2){
    scanf("%ld %ld",&c,&d);
    // 指數和底數項各自約分
    reduce(a,b);
    reduce(c,d);
    // 質因數分解
    PAIR num=factor(a,c,d);
    PAIR den=factor(b,c,d);
    reduce(num.u,den.u);
    reduce(num.v,den.v);
    // 輸出格式
    if(num.u!=den.u){
      printf("%ld",num.u);
      if(den.u>1) printf("/%ld",den.u);
    }
    if(num.v!=den.v){
      printf("_/%ld(%ld",d,num.v);
      if(den.v>1) printf("/%ld",den.v);
      putchar(')');
    }
    putchar('\n');
    if(num.u==den.u and num.v==den.v) puts("1");
  }
}
/*
1684800 2323139 4 10
125 32 35 21
135 12 2 4
125 64 35 21
3 5 3 5
123 3 5 5
1234567 1234567 6543 6543
*/
