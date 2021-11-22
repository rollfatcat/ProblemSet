/* 給定Ｎ個數字，在最多只能連續選取Ｋ個數字時，輸出最大化選中數字的總和
 * 解題關鍵：排除法＋動態規劃＋Monotone Queue
 * 最多只能連續選取Ｋ個時的最大化總和＝從Ｋ+1個中必須選擇一個數字問最小化的總和
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
	
	long prS=0;
	deque<long> DQ={0};
	dp[0]=0;
	for(int n=1; n<=N; n+=1){
		scanf("%d",&v);
		prS+=v;
		dp[n]=dp[DQ.front()]+v;
		while(DQ.empty()==0 and dp[DQ.back()]>=dp[n])
			DQ.pop_back();
		DQ.push_back(n);
		if( DQ.front()+K<n )
			DQ.pop_front();
	}
	printf("%ld\n",prS-dp[DQ.front()]);
}