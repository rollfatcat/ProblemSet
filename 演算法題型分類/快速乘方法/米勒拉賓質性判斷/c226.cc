// 題解概念同於 b437，只是範圍變更為10^18 (1.5s)
// 題解：質因數分解，質奇數的次方乘積
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
  if(number<2) return false;
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
    long d=__gcd( (x>=y)?(x-y):(y-x),number);
    if(d>1) return d;
  }
  return number;
}

void factorize(long number){
  // 質數檢定
  if(MillerRabinPrimalityTest(number)){ base.push_back(number); return; }
  // 當範圍在整數以內時就一般的質因數分解
  if(number<=INTbound){
    for(int p,idx=1;idx<prime_num and number>1;idx++){
      for(p=0;number%prime[idx]==0;p++,number/=prime[idx]);
      if(p) base.push_back(prime[idx]);
    }
    if(number>1)  base.push_back(number);
  }else{
    // 透過 Pollard's ρ Algorithm 拆出一個因數後繼續 Divide＆Conqure
    long d=number;
    for(int c=2;d==number;c++)
      d=Pollard_Rho(number,c);
    if(d>1) factorize(d);
    if(number/d>1) factorize(number/d);
  }
}
int main(){

  seive(sqrt(INTbound));
  //
  long number;
  while(scanf("%ld",&number) and number){
    while((number&1)==0)
      number>>=1;
    // factorize
    base.clear();
    factorize(number);
    sort(base.begin(),base.end());
    base.erase( unique(base.begin(),base.end()), base.end());
    // 根據格式輸出
    int cnt=1;
    for(int p,i=0;i<base.size();i++){
      for(p=0;number%base[i]==0;p++,number/=base[i]);
      cnt*=(p+1);
    }
    printf("%d\n",cnt-1);
  }
}