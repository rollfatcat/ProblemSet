// 先做a471，理解連續整數和可以視為質因數分解的關係
// 數論：連續非負整數和的方法數 => a+...+b的和為 (b+a)*(b-a+1)/2，分子部份一為奇、一為偶，所以就是求奇因數的個數
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

// 29999999 = 1857859th prime
vector<int>prime;
int bound=30000000;
bool isPrime[30000001];
bool scanLong(long &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); return c!=EOF; }
int main(){
  memset(isPrime,true,sizeof(isPrime));
  isPrime[0]=isPrime[1]=0;
  prime.push_back(2);
  for(int i=4;i<=bound;i+=2)
    isPrime[i]=0;
  for(int i=3;i<=sqrt(bound);i+=2)
    if(isPrime[i])
      for(int k=i<<1,j=i+k;j<=bound;j+=k)
        isPrime[j]=0;
  for(int i=3;i<=bound;i+=2)
    if(isPrime[i])
      prime.push_back(i);
  prime.push_back(30000001);
  // 計算奇數的質因數個數
  for(long x,now; scanLong(x); ){
    int cnt=(x)?1:0;
    for(now=x; now and (now&1)==0; now>>=1);
    // 加速技巧：只要判斷質數的平方以內即可(但這次質數個數太多所以不存平方的值)
    for(int idx=1; (long)prime[idx]*prime[idx]<=now; idx++){
      int Np=0;
      for(;now%prime[idx]==0; now/=prime[idx], Np++);
      if(Np) cnt*=(1+Np);
    }
    // 跳開後要判斷數值是不是大於0，因為只會檢查平方根以內的質數
    if(now>1) cnt<<=1;
    // 確認存在一組解是0+1+2+...
    long Nx=sqrt(x<<1);
    bool haveZero=(Nx*(Nx+1))==(x<<1);
    printf("%d\n",cnt+haveZero);
  }
}