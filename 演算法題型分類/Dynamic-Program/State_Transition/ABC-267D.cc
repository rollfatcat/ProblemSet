/* 給定Ｎ個數字當中(必須)選出Ｍ個，輸出Ｍ個數字最大的「加權」總合？
 * 必須選擇Ｍ個數字 ... 所以當所有數字都是負的時候初始化設定為 LONG_MIN
 * 解題關鍵：動態規劃
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e3;
const int MaxA=2e5;
const long INF=-1e18;
long dp[MaxN+1][MaxN+1]={};
int main(){
	int N, M, v;
	// input
	cin>>N>>M;
	for(int n=0; n<=N; n++){
		dp[n][0]=0;
		for(int m=1; m<=M; m++)
			dp[n][m]=INF;
	}
	for(int n=1; n<=N; n++){
		cin>>v;
		for(int m=1; m<=min(n,M); m++)
			dp[n][m]=max(dp[n-1][m],dp[n-1][m-1]+v*m);
	}
	cout<<dp[N][M];
}