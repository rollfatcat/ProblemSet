/* 給定Ｎ朵香菇，並依照規定沿途採集(不可回頭)，輸出最多能採集的數量？
 * 規定：一旦採了Ｇ香菇就不能再採Ｒ香菇 並且 一旦採了Ｂ香菇就不能再採Ｇ香菇和Ｒ香菇
 * 解題關鍵：枚舉狀態( 最後採到的香菇(Ｒ/Ｇ/Ｂ)會影響到下一次能夠採集的狀態 )
 */
#include<bits/stdc++.h>
using namespace std;
#define R 0
#define G 1
#define B 2

const int MaxN=5e4+1;
const int MaxS=3;
int dp[MaxN][MaxS];
char ss[MaxN];

int main(){
  dp[0][R]=dp[0][G]=dp[0][B]=0;
  for(int N;scanf("%d\n%s\n",&N,ss)!=EOF;){
	  for(int i=0;ss[i]!='\0';i++){
	  	dp[i+1][R]=               dp[i][R]+(ss[i]=='r');
	  	dp[i+1][G]=max(dp[i+1][R],dp[i][G]+(ss[i]=='g'));
	  	dp[i+1][B]=max(dp[i+1][G],dp[i][B]+(ss[i]=='b'));
	  }
	  printf("%d\n",dp[N][B]);
  }
}