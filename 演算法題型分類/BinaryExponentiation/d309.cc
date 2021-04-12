/* 給定Ｎ個人選出隊長和副隊長，剩餘的Ｎ-2個人可以自行決定是否加入隊伍中，輸出所有組合的數量(MOD 1e9+7)
 * 解題關鍵：快速幂
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=INT_MAX;
const int MOD=1e9+7;
long pow2[32];
int main(){
	long N, ans;
	scanf("%ld\n",&N);
    // 隊長和副隊長的人選組合
	ans=N*(N-1)%MOD;
    // 剩餘 N-2 個人各自決定是否加入
	N-=2;
    // 快速幂
	if(N&1) ans=(ans<<1)%MOD;
	pow2[1]=2; N>>=1;
	for(int i=2; N>0; i++, N>>=1){
		pow2[i]=(pow2[i-1]*pow2[i-1])%MOD;
		if(N&1)
			ans=(ans*pow2[i])%MOD;
	}
	printf("%ld\n",ans);
}