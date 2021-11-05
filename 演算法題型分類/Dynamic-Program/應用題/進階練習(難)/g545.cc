/* 給定一個字串序列S，將所有的 '?' 替換成 '[' 或 ']'，請計算出有幾種組合符合括號序列
 * 解題關鍵：DP
 * 狀態定義：dp[x]= 左括號還多出 x 個時的組合數
 * 狀態轉移：根據目前的字串討論
 *      ss[p]=='[' ,  dp[now]=dp[pre+1]
 *      ss[p]==']' ,  dp[now]=dp[pre-1]
 *      ss[p]=='?' ,  dp[now]=dp[pre-1]+dp[pre+1]
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e3;
const int MOD=1e9+7;
char ss[MaxN+2];
int dp[MaxN]={1};

int main(){
	int N;
	scanf("%d %s",&N,ss);
	N>>=1;
	for(int p=0; ss[p]!='\0'; p+=1){
		if(ss[p]=='['){
			for(int i=N-1; i>=0; i-=1)
				dp[i+1]=dp[i];
			dp[0]=0;
		}
		if(ss[p]==']'){
			for(int i=1; i<=N; i+=1)
				dp[i-1]=dp[i];
			dp[N]=0;
		}
		if(ss[p]=='?'){
			vector<int> tmp(N+1);
			for(int i=N-1; i>=0; i-=1)
				tmp[i+1]=dp[i];
			for(int i=1; i<=N; i+=1)
				tmp[i-1]=(tmp[i-1]+dp[i])%MOD;
			for(int i=0; i<=N; i+=1)
				dp[i]=tmp[i];
		}
	}
	printf("%d\n",dp[0]);
}