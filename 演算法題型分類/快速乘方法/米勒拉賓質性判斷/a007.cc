/* 利用『米勒-拉賓質數判定法』快速判斷質數(無法證實)
 * 需要學會『快速幂次法』後參考 wiki 的證明(https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test)
 * 這個算法的時間複雜度是O(k*log^3(n)) k是我們測試的不同的 a 的值，而這題只需要嘗試的a={2,7,61}
 * 該方法實作(0.1s) 相較於建表檢查 sqrt(2147483647) 以內的全部質數共4792個 (0.5s)
 */
#include<bits/stdc++.h>
using namespace std;

// ---檢驗2^32以內質數只需要這三個witnesses---
int judge[3]={2,7,61};
inline bool scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); return c!=EOF; }
// ---快速幂次法---
long FastPowerModular(long base,int power,int mod){
	base%=mod;
	long out=(power&1)?base:1;
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
bool MillerRabinPrimalityTest(int number){
  if(number==2) return true;
  if(number<2 or (number&1)==0) return false;
  int buffer=number-1, twosPower=0;
  while((buffer&1)==0)
    buffer>>=1, twosPower++;
  for(int i=0,j;i<3;i++){
		long powers=FastPowerModular(judge[i],buffer,number);
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
  for(int N;scanInt(N);)
    puts((MillerRabinPrimalityTest(N))?"質數":"非質數");
}