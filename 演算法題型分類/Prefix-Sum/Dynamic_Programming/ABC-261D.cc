/* 投擲硬幣Ｎ次、每一次硬幣正面時可以贏得的獎金和Ｍ個連勝紅利(Ｃ,Ｙ)，最大化可以獲得的獎金
 * 連勝紅利(Ｃ,Ｙ)：連勝到第Ｃ次時可以額外獲得獎金Ｙ，題目保證每次的Ｃ都不重複
 * 解題關鍵：動態規劃 + 前綴和
 * 狀態定義：dp[n] = 第１次到第ｎ次的投擲後可獲得的最大獎金
 * 狀態轉移：dp[n] = Σ win[n:i] + Σ bonus[1:n+1-i] + dp[i-2]
 * 前綴和：win 和 bonus 的部分都屬於區間和
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=5e3;
long  num[MaxN+1];
long  dp[MaxN+1]={};
long stp[MaxN]={};
int main(){
	int N, M, c;
	
	scanf("%d %d",&N,&M);
	for(int n=1; n<=N; n++)
		scanf("%ld",&num[n]);
	for(int m=0; m<M; m++){
		scanf("%d",&c);
		scanf("%ld",&stp[c-1]);
	}
	//
	dp[1]=num[1]+stp[0];
	for(int n=2; n<=N; n++){
		long ret=dp[n-1];
		long prS=0;
		for(int c=0; c<n-1; c++){
			prS+= num[n-c]+stp[c];
			ret=max(ret,prS+dp[n-2-c]);
		}
		dp[n]=max(ret,prS+num[1]+stp[n-1]);
	}
	printf("%ld ",dp[N]);
}