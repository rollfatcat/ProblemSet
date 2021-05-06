/* 給定前序順序的數列，輸出最小和最大的樹值？
 * 樹值定義：目前節點的分數+max( Left_subtree, Right_subtree )
 * 解題關鍵：動態規劃-區間合併 且 MaxN=1e3 ... 只能 Bottom-Up
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e3;
const int MaxV=1e9;
const long INF=1e15;
long dp[MaxN][MaxN];

int main(){
	int N;
	long maxv=0;
	scanf("%d",&N);
	for(int i=0; i<N; i+=1){
		scanf("%ld",&dp[i][i]);
		maxv+=dp[i][i];
	}
    // BottomUp
	for(int L=N-2; L>=0; L-=1){
		for(int R=L+1; R<N; R+=1){
			dp[L][R]=dp[L+1][R];
			for(int M=L+1; M<R; M+=1)
				dp[L][R]=min(dp[L][R],max(dp[L+1][M],dp[M+1][R]));
			dp[L][R]+=dp[L][L];
		}
	}
	printf("%ld %ld\n",dp[0][N-1],maxv);
}