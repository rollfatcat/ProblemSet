/* 本題和 01 背包無關僅作為 ZJ-e896 的對照題
 * 觀察規律可以發現『動態規劃』的狀態轉移方式：DP[i]＝Σ DP[j], 0 ≤j<i
 * 根據狀態轉移方式知道：需要利用『迴圈』加總但 MaxN=1e5，雙層迴圈＝TLE
 * 所以需要再觀察『數列的規則』可以推出 DP[i]＝2^(i-1)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int mod=10007;
int cnt[MaxN]={1,1,2,4};
int main(){
	for(int i=4;i<MaxN;i++)
		cnt[i]=(cnt[i]<<1)%mod;
	for(int N;scanf("%d",&N);)
		printf("%d\n",cnt[N]);
}


