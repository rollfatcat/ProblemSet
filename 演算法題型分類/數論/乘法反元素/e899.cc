/* 動態規劃，卡塔蘭數 
 * 題目可以等價為：括號配對的過程必須維持合法性＝左括號≧右括號
 * 狀態轉移：Ｃn＝Σ Ｃi*Ｃn-i
 * 數論(模的乘法反元素)：卡塔蘭數Ｃn+1＝２(２n+1)/(n+２)Ｃn
 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxQ=1e5;
const int MaxN=1e4;
const int mod=10007;
long dpv[MaxN+1]={1,1,2};
/* 費馬小定理定理 求 乘法反元素＝
 * a^(p-1)=1(mod p), p不是a的倍數, 則 a(p-2)＝a^(-1) (mod p)
 */
inline int ModuleInverse(int B,int out=1){
	for(int x=mod-2;x;x>>=1,B=B*B%mod)
		if(x&1)
			out=out*B%mod;
	return out;
}
int main(){
	/* 動態規劃解法：0.2s
	 * for(int i=3;i<=MaxN;i++)
	 *	 for(int j=0;j<i;j++)
	 *		 dpv[i]=(dpv[i]+(dpv[j]*dpv[i-1-j])%mod)%mod;
	 */
	/* 數論規律＋取模的乘法反元素：27ms */
	for(int i=2;i<MaxN;i++)
		dpv[i+1]=dpv[i]*((i<<1|1)<<1)*ModuleInverse(i+2)%mod;
	for(int N;scanf("%d\n",&N)!=EOF;)
		printf("%ld\n",dpv[N]);
}