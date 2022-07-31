/* 給定數列長度Ｎ，每個位置可以從１到Ｍ當中選擇，但相鄰的數字
 * 解題關鍵：動態規劃(滾動陣列) + 前綴和
 * 狀態定義：dp[n][m] = 第ｎ個位置時選擇數字ｍ的方法數
 * 狀態轉移：dp[n][m] = Σ dp[n-1][1:m-K] + Σ dp[n-1][m+K:N]
 * 轉移時只需要保留第ｎ-1 次的方法數
 * 前綴和：dp[n-1][1:m-K] 和 dp[n-1][m+K:N] 都屬於區間和
 * 特殊例子：Ｋ=０時，dp[n-1][m] 會重複加到 ... 答案為 M^K
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e3;
const int MaxM=5e3;
const int MOD=998244353;
long dp[2][MaxM+1]={};
long add(long v){ return (v>=MOD)? v-MOD: (v<0)?v+MOD: v;}
int main(){
	long N, M, K;
	cin>>N>>M>>K;
	if(K==0){
		K=M;
		for(int n=1; n<N; n++)
			K=K*M%MOD;
		printf("%ld",K);
		return 0;
	}
	iota(dp[0],dp[0]+1+M,0);
	bool pre=1;
	bool now=0;
	for(int n=1; n<N; n++){
		swap(pre,now);
		for(int m=1; m<=M; m++){
			dp[now][m]=0;
			if(m>K)    
				dp[now][m]=add(dp[now][m]+dp[pre][m-K]);
			if(m+K<=M)
				dp[now][m]=add(dp[now][m]+dp[pre][M]-dp[pre][m+K-1]);
			dp[now][m]=add(dp[now][m]+dp[now][m-1]);
		}
	}
	printf("\n%ld",dp[now][M]);
}