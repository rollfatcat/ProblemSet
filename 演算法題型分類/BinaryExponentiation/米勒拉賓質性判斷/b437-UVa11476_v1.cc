// 要判斷10^18以內的數是不是質數？(2.1s)
// (X)不可能建立10^9內全部的質數
// 解法：http://mypaper.pchome.com.tw/zerojudge/post/1325454597
// 詳細說明：https://www.cnblogs.com/Doggu/p/MillerRabin_PollardRho.html
/*
 * 本題需要兩個數學的演算法：Miller-Rabin Algorithm＋Pollard's ρ  Algorithm
 * Miller-Rabin Algorithm 判斷是否為質數(判斷2^64以內的質數要通過7個強偽證)
 * Pollard's ρ  Algorithm 根據亂數產生器，概率產生一部分的因數。
 * 實作時請注意ｘ＊ｙ％mod 的計算，因為 x,y,mod 都是６４位元，相乘可能會 overflow。
 * 相乘的單位改為__int128，快速幂次方部分照舊
 */
#include<bits/stdc++.h>
using namespace std;

const long INTbound=(long)1<<31;
int prime_num=2;
int prime[4800]={2,3}; // prime[4797]=46411
vector<long> base;

inline void seive(int bound){
  for(int test,now=5;now<=bound;now+=2){
    for(test=1;test<prime_num and now%prime[test];test++);
    if(test==prime_num) prime[prime_num++]=now;
  }
}
long modpow(__int128 x,long y,long mod,__int128 ret=1){
  for(;y>0;y>>=1,x=x*x%mod)
    if(y&1)
      ret=ret*x%mod;
  return ret;
}

long MRPT[7]={2,325,9375,28178,450775,9780504,1795265022};
bool MillerRabinPrimalityTest(long number){
  if(number==2) return true;
  if(number<2 or (number&1)==0) return false;
  long buffer=number-1;
  int twosPower=0;
  while((buffer&1)==0)
    buffer>>=1, twosPower++;
  for(int i=0,j;i<7;i++){
		__int128 powers=modpow(MRPT[i],buffer,number);
		if(powers==1 or powers==number-1 or powers==0)
			continue;
		for(j=0;j<twosPower;j++){
			powers=powers*powers%number;
			if(powers==1)	return false;
			if(powers==number-1)	break;
		}
		if(j==twosPower)
			return false;
	}
	return true;
}
long Pollard_Rho(__int128 number,long bias,__int128 x=2,__int128 y=2){
  while(true){
    x=( x*x+bias )%number,
    y=( y*y+bias )%number,
    y=( y*y+bias )%number;
    long d=__gcd( (x>=y)?(x-y):(y-x), number);
    if(d>1) return d;
  }
  return number;
}

void factorize(long number){
  if(MillerRabinPrimalityTest(number)){ base.push_back(number); return; }

  if(number<=INTbound){
    for(int p,idx=0;idx<prime_num and number>1;idx++){
      for(p=0;number%prime[idx]==0;p++,number/=prime[idx]);
      if(p) base.push_back(prime[idx]);
    }
    if(number>1)  base.push_back(number);
  }else{
    long d=number;
    for(int c=2;d==number;c++)
      d=Pollard_Rho(number,c);
    if(d>1) factorize(d);
    if(number/d>1) factorize(number/d);
  }
}
int main(){

  seive(sqrt(INTbound));
  int caseN, p;
  scanf("%d",&caseN);
  for(long number;caseN--;){
    scanf("%ld",&number);
    base.clear();
    factorize(number);
    sort(base.begin(),base.end());
    base.erase( unique(base.begin(),base.end()), base.end());
    printf("%ld = %ld",number,base[0]);
    for(p=0;number%base[0]==0;p++,number/=base[0]);
    if(p>1) printf("^%d",p);
    for(int i=1;i<base.size();i++){
      printf(" * %ld",base[i]);
      for(p=0;number%base[i]==0;p++,number/=base[i]);
      if(p>1) printf("^%d",p);
    }
    puts("");
  }
}