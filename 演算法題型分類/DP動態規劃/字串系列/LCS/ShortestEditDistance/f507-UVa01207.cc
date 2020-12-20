/* 給定２個字串Ｓ和Ｔ，至少需要經過幾次操作後才能讓字串Ｓ變成字串Ｔ？
 * 操作包含３種：刪除字元/ 新增字元 /字元轉換
 * 解題關鍵：DynamicProgramming-最短編集距離(標準模板題型，每種操作的代價都一樣)
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxL=1039;
char ss[2][MaxL+2];
 
int L[2];
int dp[2][MaxL+2];
int main(){
	while(scanf("%d %s\n",&L[0],ss[0])!=EOF){
		scanf("%d %s\n",&L[1],ss[1]);
 
		bool pre=1, now=0;
		for(int i=0;i<=L[0];i++) 
			dp[now][i]=i;
		for(int i=0;i<L[1];i++){
			swap(pre,now);
			dp[now][0]=i+1;
			for(int j=0;j<L[0];j++)
				dp[now][j+1]=min(min(dp[pre][j+1],dp[now][j])+1,
				                     dp[pre][j]+(ss[0][j]!=ss[1][i]));
		}
		printf("%d\n",dp[now][L[0]]);
	}
}