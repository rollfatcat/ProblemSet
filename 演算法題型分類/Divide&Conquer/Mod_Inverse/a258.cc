/* 題目給定(ｍ,ａ,ｂ)求(ｃ,ｄ)
 * (1)Ｙ ≡ ａＸ＋ｂ(mod ｍ)，其中ａ、ｂ為整數。
 * (2)Ｘ ≡ ｃＹ＋ｄ(mod ｍ)，其中ｃ、ｄ為整數
 * (1)帶入(2) : Ｘ ≡ ａｃＸ＋ｂｃ＋ｄ(mod ｍ)
 * 因此，我們可以看出ａ、ｃ互為模乘法反元素(Modular Multiplicative Inverse，模反元素) 且ｄ≡-ｂｃ(mod ｍ)
 * 透過『擴展歐幾里得』演算法求 ａ在ｍ的餘數下的模反元素也就是ｃ。之後再乘上-ｂ，取除以ｍ的餘數，即為ｄ。
 */
#include<bits/stdc++.h>
using namespace std;

long InverseN(long x,long mod){
  long maxtrix[2][2]={{1,0},{0,1}}, num[2]={x,mod};
  bool now=0, nxt;
  for(int t; num[0] and num[1]; num[now]%=num[nxt],now=nxt){
    nxt=now^1;  t=num[now]/num[nxt];
    maxtrix[now][0]-=t*maxtrix[nxt][0],
    maxtrix[now][1]-=t*maxtrix[nxt][1];
  }
  if(maxtrix[now][0]<0)
    maxtrix[now][0]+=mod;
  return maxtrix[now][0];
}
int main(){
  int T, m, a, b;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d %d",&m,&a,&b);
    int hasInverse=__gcd(m,a);
    if(hasInverse!=1){
      printf("No inverse, gcd(a,m)=%d\n",hasInverse);
      continue;
    }
    long inverse=InverseN(a,m);
    long constant=m-inverse*b%m;
    printf("%ld %ld\n",inverse,constant);
  }
}