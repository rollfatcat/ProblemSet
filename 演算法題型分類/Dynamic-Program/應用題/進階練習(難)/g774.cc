/* 給定Ｎ+Ｍ個班級中速度最快的男生和女生的跑步時間，按照題目的限制組出最快的接力隊伍？
 * 限制：每個班級只能推派一位形成Ｎ位男生和Ｍ位女生的隊伍
 * 解題關鍵：動態規劃，依序考慮第ｎ+ｍ班級要選擇推派男生還是女生
 * 狀態定義：dp[n][m] = ｎ位男生和ｍ位女生的最短時間組合
 * 狀態轉移：dp[n][m]=min(dp[n-1][m]+num[n+m][0],dp[n][m-1]+num[n+m][1]);;
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e3;
const int MaxV=1e4;
int num[MaxN<<1|1][2];
int dp[MaxN+1][MaxN+1];
int main(){
	int N, M;
	
	scanf("%d %d",&N,&M);
	for(int n=1; n<=N+M; n+=1)
		scanf("%d %d",&num[n][0],&num[n][1]);
	// init set
	dp[0][0]=0;
	for(int n=1; n<=N; n+=1)
		dp[n][0]=dp[n-1][0]+num[n][0];
	for(int m=1; m<=M; m+=1)
		dp[0][m]=dp[0][m-1]+num[m][1];
	for(int n=1; n<=N; n+=1)
		for(int m=1; m<=M; m+=1)
			dp[n][m]=min(dp[n-1][m]+num[n+m][0],dp[n][m-1]+num[n+m][1]);
	printf("%d",dp[N][M]);
}