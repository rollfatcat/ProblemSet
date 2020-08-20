/* 給定Ｔ筆測資，每筆測資包含Ｋ、Ｎ、Ｍ，輸出最接近Ｋ且無法被Ｍ、Ｎ整除的數值？
 * 解題關鍵：無限制背包
 * 因為Ｋ不超過 1e6，枚舉每個狀態(能/不能被整除)。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=1e2;
const int MaxK=1e6;
bool dp[MaxK+1];

int main(){
	int caseT, N, M, K;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d\n%d %d\n",&K,&N,&M);
        // solve()
        fill(dp+1,dp+K+1,0);
        for(int i=0;i<=K;i+=N)
            dp[i]=1;
        for(int i=M;i<=K;i++)
            dp[i]|=dp[i-M];
        while(dp[K] and K>=0) K--;
		(K<0)?puts("good"): printf("%d\n",K);
	}
}