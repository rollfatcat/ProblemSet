/* 給定Ｎ個不同編號的Ｍ面骰子(點數為１到Ｍ)，總和為Ｋ的方法數？
 * 解題關鍵：動態規劃 + 滾動陣列
 * 狀態定義：dp[n][x] = ｎ顆骰子時點數和ｘ的方法數
 * 狀態轉移：dp[n][x] = sum( dp[n-1][x-m] ), 1 ≤ m ≤ 6
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=50;
const int MaxM=50;
const int MOD=998244353;
int add(int a,int b){ return (a+b>=MOD)? a+b-MOD: a+b; }

int dp[2][2501];
int main(){
	int N, M, K;
	bool pre=1;
	bool now=0;
	
	scanf("%d %d %d",&N,&M,&K);
	dp[0][0]=1;
	for(int n=1; n<=N; n++){
		swap(pre,now);
		fill(dp[now],dp[now]+2501,0);
		for(int v=n-1; v<=M*(n-1); v++)
			for(int m=1; m<=M; m++)
				dp[now][v+m]=add(dp[now][v+m],dp[pre][v]);
	}
	// output
	int ans=0;
	for(int v=0; v<=K; v++)
		ans=add(ans,dp[now][v]);
	printf("%d",ans);
}