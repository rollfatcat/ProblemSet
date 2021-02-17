/* 題目有標示『本題無法以暴力AC，也無法利用建質數表來AC，請找出比較有效率的方法』
 * 根據題目給予的輸入範圍(2^32)推算需要檢驗的質數是65536以內的所有質數(6542個)
 * 『有效率的方法』＝米勒-拉賓質數判定法
 * 注意：計算過程中型態導致的溢位問題
 */
#include<bits/stdc++.h>
using namespace std;

int judge[3]={2,7,61};
inline void scanLong(long &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
}
// ---快速幂次法---
__int128 FastPowerModular(__int128 base,long power,long mod){
	base%=mod;
	__int128 out=(power&1)?base:1;
	for(power>>=1; power>0; power>>=1){
		base=base*base%mod;
		if(power&1)
			out=(out*base)%mod;
	}
	return out;
}
// ---米勒-拉賓質數判定法---
/* 需要取得3個強偽證才能判定是質數，
 * 只要其中一個強偽證失敗即是『合數』的憑證
 */
bool MillerRabinPrimalityTest(long number){
  if(number==2) return true;
  if(number<2 or (number&1)==0 or (number%5)==0) return false;
  long buffer=number-1;
  int twosPower=0;
  while((buffer&1)==0)
    buffer>>=1, twosPower++;
  for(int i=0,j;i<3;i++){
		__int128 powers=FastPowerModular(judge[i],buffer,number);
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
	return true;// 需要取得3個強偽證才能判定是質數
}
int main(){
  long N, tmpN, number;
  scanLong(N),
  scanLong(tmpN),
  scanLong(tmpN);
  while(N--){
    scanLong(number);
    /* 題目要求輸出比 number 大的質數，第一步是先找出比 number 大的6K+1 or 6K+5
     * 交替測試：6K+1 和 6K+5 是否通過『米勒-拉賓質數判定法』
     */
    tmpN=number/6*6+1;
    if(tmpN>number and MillerRabinPrimalityTest(tmpN)){
      printf("%ld\n",tmpN);  continue;
    }
    tmpN+=4;
    if(tmpN>number and MillerRabinPrimalityTest(tmpN)){
      printf("%ld\n",tmpN);  continue;
    }
    for(number=tmpN+2;MillerRabinPrimalityTest(number)==0;number+=2){
      number+=4;
      if(MillerRabinPrimalityTest(number))
        break;
    }
    printf("%ld\n",number);
  }
}