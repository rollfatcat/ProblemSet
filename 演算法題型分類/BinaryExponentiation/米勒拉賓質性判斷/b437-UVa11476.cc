// 要判斷10^18以內的數是不是質數？(8.9s)
// (X)不可能建立10^9內全部的質數
// 解法：http://mypaper.pchome.com.tw/zerojudge/post/1325454597
// 詳細說明：https://www.cnblogs.com/Doggu/p/MillerRabin_PollardRho.html
/*
 * 本題需要兩個數學的演算法：Miller-Rabin Algorithm＋Pollard's ρ  Algorithm
 * Miller-Rabin Algorithm 判斷是否為質數(判斷2^64以內的質數要通過7個強偽證)
 * Pollard's ρ  Algorithm 根據亂數產生器，概率產生一部分的因數。
 * 實作時請注意ｘ＊ｙ％mod 的計算，因為 x,y,mod 都是６４位元，相乘可能會 overflow。
 * 很多人誤以為 (x%mod)*(y%mod)%mod 就可以解決 overflw，這是錯誤的想法。
 * 真正作法請參照 modmul，透過快速幂次法將乘法簡化為多個加法。
 */
#include<bits/stdc++.h>
using namespace std;

const long INTbound=(long)1<<31;
int prime_num=2;
int prime[4800]={2,3}; // prime[4797]=46411
vector<long> base;

// 篩法：找到sqrt(1<<31)以內的質數
inline void seive(int bound){
  for(int test,now=5;now<=bound;now+=2){
    for(test=1;test<prime_num and now%prime[test];test++);
    if(test==prime_num) prime[prime_num++]=now;
  }
}
// 快速幂次法實作『乘法』，避免兩個long直接相乘導致的overflow
long modmul(long x,long y,long mod,long ret=0){
  for(x%=mod;y>0;y>>=1,x=(x<<1)%mod)
    if(y&1)
      ret=(ret+x)%mod;
  return ret%mod;
}
// 快速幂次法實作『次方』，避免兩個long直接相乘導致的overflow
long modpow(long x,long y,long mod,long ret=1){
  for(;y>0;y>>=1,x=modmul(x,x,mod))
    if(y&1)
      ret=modmul(ret,x,mod);
  return ret;
}

// 米勒拉賓質數檢定：基底有7個確保2^64以內有效
long MRPT[7]={2,325,9375,28178,450775,9780504,1795265022};
bool MillerRabinPrimalityTest(long number){
  if(number==2) return true;
  if(number<2 or (number&1)==0) return false;
  long buffer=number-1;
  int twosPower=0;
  while((buffer&1)==0)
    buffer>>=1, twosPower++;
  for(int i=0,j;i<7;i++){
		long powers=modpow(MRPT[i],buffer,number);
		if(powers==1 or powers==number-1 or powers==0)
			continue;
		for(j=0;j<twosPower;j++){
			powers=modmul(powers,powers,number);
			if(powers==1)	return false;
			if(powers==number-1)	break;
		}
		if(j==twosPower)
			return false;
	}
	return true;// 需要取得7個強偽證才能判定是質數
}

// Pollard’s Rho 算法＋Floyed 環偵測機制
/* 基於生日問題(birthday problem)或者生日悖論(birthday paradox)出現的隨機算法
 * 在區間[𝟐,𝑵−𝟏]中隨機選取𝒌個數字，𝒙𝟏… …𝒙𝒌
 * 判斷是否存在 gcd(𝒙𝒊−𝒙𝒚,𝑵)>𝟏，若存在，gcd(𝒙𝒊−𝒙𝒚,𝑵) 是𝑵的一個因子
 * 參考附件：https://files-cdn.cnblogs.com/files/Doggu/Pollard-rho%E7%AE%97%E6%B3%95%E8%AF%A6%E8%A7%A3.pdf
 */
long Pollard_Rho(long number,long bias,long x=2,long y=2){
  while(true){
    //x = (x*x+c)%n;
    x=( modmul(x,x,number)+bias ) %number,
    //y = (y*y+c)%n, y = (y*y+c)%n;
    y=( modmul(y,y,number)+bias ) %number,
    y=( modmul(y,y,number)+bias ) %number;
    // 判斷：f(x)=f(f(y))，GCD前處理差值可能是負的問題
    long d=__gcd( (x>=y)?(x-y):(y-x), number);
    if(d>1) return d;
  }
  return number;
}

void factorize(long number){
  // 質數檢定
  if(MillerRabinPrimalityTest(number)){ base.push_back(number); return; }
  // 當範圍在整數以內時就一般的質因數分解
  if(number<=INTbound){
    for(int p,idx=0;idx<prime_num and number>1;idx++){
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
  int caseN, p;
  scanf("%d",&caseN);
  for(long number;caseN--;){
    scanf("%ld",&number);
    // factorize
    base.clear();
    factorize(number);
    sort(base.begin(),base.end());
    base.erase( unique(base.begin(),base.end()), base.end());
    // 根據格式輸出
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