/* 動態規劃＋快速幂(同 ZJ-e895)
 * 狀態轉移：DP[0]=1, DP[Ｎ]=Σ DP[i], 0≤ｉ<Ｎ
 * 數論：DP[Ｎ]=Σ DP[i]＝2^(Ｎ-1)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=1e4; //
const int mod=1e9+7;
int TwoPowerMod(int P,long out=1){
	for(long B=2; P; P>>=1, B=B*B%mod)
		if(P&1)
			out=out*B%mod;
	return out;
}
int main(){
	int caseT, L; 
	scanf("%d\n",&caseT);
	while(caseT--)
		scanf("%d\n",&L),
		printf("%d\n",TwoPowerMod(L-1));
	
}
