/* 給定Ｎ個數字，連續Ｋ個數字中至少挑選一個的條件下，最小化選中數字的總和？
 * 解題關鍵：動態規劃(dynamic program)＋單調列隊(monotonic queue)
 * 狀態定義：dp[n]＝選中第ｎ格時的最小總和
 * 狀態轉移：dp[n]=num[n]+min(dp[n-1],dp[n-2]...,dp[n-K])
 *         需要從第ｎ格往前連續Ｋ個的範圍內挑出最小值做轉移 ... 單調列隊
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxK=1e6;
const int MaxV=1e9;

long dp[MaxN+1]={};
int main(){
	int N, K, v;
	scanf("%d %d",&N,&K);
	
	deque<long> DQ={0};
	dp[0]=0;
	for(int n=1; n<=N; n+=1){
		scanf("%d",&v);
		if( DQ.front()+K<n )
			DQ.pop_front();
		dp[n]=dp[DQ.front()]+v;
		while(DQ.empty()==0 and dp[DQ.back()]>=dp[n])
			DQ.pop_back();
		DQ.push_back(n);
	}
	printf("%ld\n",dp[DQ.front()]);
}