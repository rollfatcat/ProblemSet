/* 輸入第Ｎ組黃金比例
 * 黃金比例＝費波納契數列
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=45;
int dp[MaxN+1]={1,1};
int main(){
	int N;
	scanf("%d\n",&N);
	for(int i=2;i<=N;i++)
		dp[i]=dp[i-1]+dp[i-2];
	printf("%d:%d\n",dp[N-1],dp[N]);
}