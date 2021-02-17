// 質因數分解的範圍是2^64以內，需要米勒拉賓值性判斷和Pollard_Rho
// 排容性質：扣除範圍內不會互質的數字。
#include<bits/stdc++.h>
using namespace std;

const long INTbound=(long)1<<31;
int prime_num=2;
int prime[4800]={2,3}; // prime[4797]=46411
vector<unsigned long> base;
unsigned long Layerall, N;

inline void seive(int bound){
  for(int test,now=5;now<=bound;now+=2){
    for(test=1;test<prime_num and now%prime[test];test++);
    if(test==prime_num) prime[prime_num++]=now;
  }
}
long modpow(__int128 x,unsigned long y,unsigned long mod,__int128 ret=1){
  for(;y>0;y>>=1,x=x*x%mod)
    if(y&1)
      ret=ret*x%mod;
  return ret;
}

long MRPT[7]={2,325,9375,28178,450775,9780504,1795265022};
bool MillerRabinPrimalityTest(unsigned long number){
  if(number==2) return true;
  if(number<2 or (number&1)==0) return false;
  unsigned long buffer=number-1;
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
long Pollard_Rho(__int128 number,unsigned long bias,__int128 x=2,__int128 y=2){
  while(true){
    x=( x*x+bias )%number,
    y=( y*y+bias )%number,
    y=( y*y+bias )%number;
    unsigned long d=__gcd( (x>=y)?(x-y):(y-x), number);
    if(d>1) return d;
  }
  return number;
}

void factorize(unsigned long number){
  if(MillerRabinPrimalityTest(number)){ base.push_back(number); return; }

  if(number<=INTbound){
    for(int p,idx=0;idx<prime_num and number>1;idx++){
      for(p=0;number%prime[idx]==0;p++,number/=prime[idx]);
      if(p) base.push_back(prime[idx]);
    }
    if(number>1)  base.push_back(number);
  }else{
    unsigned long d=number;
    for(int c=2;d==number;c++)
      d=Pollard_Rho(number,c);
    if(d>1) factorize(d);
    if(number/d>1) factorize(number/d);
  }
}

void Pick(int now, int st,unsigned long LCM){
  if(now==0){ Layerall+=(N/LCM); return; }
  for(int i=st;i<=(base.size()-now);i++)
    Pick(now-1,i+1,LCM*base[i]);
}
int main(){

  seive(sqrt(INTbound));
  while(scanf("%lu",&N)!=EOF){

    base.clear();
    factorize(N);
    sort(base.begin(),base.end());
    base.erase( unique(base.begin(),base.end()), base.end());
    unsigned long ans=N;
    for(int i=1;i<=base.size();i++)
      Layerall=0,
      Pick(i,0,1),
      ans+=((i%2)?-Layerall:Layerall);
    printf("%lu\n",ans);
  }
}
// 18446744073709551615