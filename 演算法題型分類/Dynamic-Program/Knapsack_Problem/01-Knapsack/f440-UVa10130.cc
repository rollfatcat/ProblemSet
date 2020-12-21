/* 給定Ｎ種商品的價值和重量、Ｇ個人可以帶走的最大負重，輸出所有人能帶走的最大價值總合？
 * 限制：每個人每種商品最多只能拿一個，但負重限制內可以帶多種不同商品
 * 解題關鍵：０１-Knapsaack
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=1e3;
const int MaxN=1e3;
const int MaxG=1e2;
const int MaxCover=30;
int dp[MaxCover+1]={};
int main(){
	int caseT, N, G, w, v;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d\n",&N);
		fill(dp,dp+MaxCover+1,0);
		for(int i=0;i<N;i++){
			scanf("%d %d\n",&v,&w);
			for(int j=MaxCover; j>=w; j--)
				dp[j]=max(dp[j],dp[j-w]+v);
		}
		int ans=0;
		scanf("%d\n",&G);
		while(G-->0){
			scanf("%d\n",&w);
			ans+=dp[w];
        }
		printf("%d\n",ans);
	}
}