/* 給定走廊長度Ｌ，利用正方形邊長為整數的貨物堆滿這條長廊且「符合左右對稱」的#方法數？
 * 解題關鍵：動態規劃
 * 狀態轉移：DP[ｉ]＝ Σ DP[ｊ], 0 ≤ｊ≤ｉ/2
 * MaxN＝1e6 可以透過前綴和避開雙迴圈的累加運算，
 * 但觀察數列規律： DP[ｉ]＝ Σ DP[ｊ]＝２^(ｉ/2+1)。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=1e4;
const int MaxL=1e6;
const int MOD=1e4+7;

int dp[MaxL]={1,1};
int main(){
	for(int i=2;i<=(MaxL>>1)+1;i++)
		dp[i]=(dp[i-1]<<1)%MOD;
	int L;
	while(scanf("%d\n",&L)!=EOF)
		printf("%d\n",dp[(L>>1)+1]);
}