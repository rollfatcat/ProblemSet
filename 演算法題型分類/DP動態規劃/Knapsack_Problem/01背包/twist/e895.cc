/* 給定走廊長度Ｌ，利用正方形貨物堆滿長度Ｌ的#方法數(不管寬度)？
 * 解題關鍵：動態規劃( 本題和 01 背包無關僅作為 ZJ-e896 的對照題 )
 *『狀態轉移』：DP[ｉ]＝Σ DP[ｊ], 0 ≤ｊ<ｉ
 * 根據狀態轉移方式知道：需要利用『迴圈』加總但 MaxN＝1e5，須透過「前綴和」避開雙迴圈累加。
 * 或是觀察『數列的規則』可以推出 DP[ｉ]＝2^(ｉ-1)
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


