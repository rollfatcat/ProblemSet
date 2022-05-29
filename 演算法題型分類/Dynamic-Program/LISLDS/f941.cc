/* 給定一個長度 1e8 個由１,２,３組成的序列，輸出最長的非嚴格地增子序列
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=1e8;
int dp[4]={};
int main(){
	char c;
	while( (c=getchar())!='\n' ){
		c-='0';
		dp[c]+=1;
		for(int i=c+1; i<=3; i+=1)
			dp[i]=max(dp[i],dp[i-1]);
	}
	printf("%d\n",dp[3]);
}