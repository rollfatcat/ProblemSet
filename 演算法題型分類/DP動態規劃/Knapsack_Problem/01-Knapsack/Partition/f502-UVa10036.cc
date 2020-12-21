/* Ｎ個數字透過調整正負號的方式做加總，總和的值能否被Ｋ整除？
 * 問題線索：0 ≦ Ｋ ≦ 100，能否被Ｋ整除只需要考慮單個數字模Ｋ的餘數( 負的調整回正數 )
 * 解題關鍵：01背包的變形題-分堆問題(動態規劃)＋滾動陣列
 * 每個數字非正即負，所以前一次狀態的數字轉移為現在狀態的數字時有２種可能：加上該數字 或是 扣除該數字
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e4;
const int MaxK=1e2;
const int MaxV=1e4;
 
bool dp[2][MaxK];
int main(){
	int caseT, N, K, v;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d\n",&N,&K);
 
		bool pre=1, now=0;
		fill(dp[0],dp[0]+K,0); dp[0][0]=1;
		while(N-->0){
			scanf("%d",&v);
			v=(v<0)? K+v%K: v%K;
 
			swap(pre,now);
			fill(dp[now],dp[now]+K,0);
			for(int i=0;i<K-v;i++)
				dp[now][i+v]|=dp[pre][i];
			for(int i=K-v;i<K;i++)
				dp[now][i+v-K]|=dp[pre][i];
			for(int i=v;i<K;i++)
				dp[now][i-v]|=dp[pre][i];
			for(int i=0;i<v;i++)
				dp[now][i-v+K]|=dp[pre][i];
		}
		puts((dp[now][0])?"Divisible":"Not divisible");
	}
}