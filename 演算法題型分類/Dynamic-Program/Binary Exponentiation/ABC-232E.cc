#include<bits/stdc++.h>
using namespace std;
 
const int MaxR=1e9;
const int MaxC=1e9;
const int MaxK=1e6;
const int MOD=998244353;
long dp[MaxK+1][4]={};// center, same_row, same_col, others; 
int main(){
	int R, C, K;
	int x1, y1, x2, y2;
	
	scanf("%d %d %d",&R,&C,&K);
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	
	dp[0][0]=1;
	for(int k=1; k<=K; k+=1){
		dp[k][0]=( (R-1)*dp[k-1][1]+(C-1)*dp[k-1][2] )%MOD;
  		dp[k][1]=( dp[k-1][0]+(R-2)*dp[k-1][1]+(C-1)*dp[k-1][3] )%MOD;
  		dp[k][2]=( dp[k-1][0]+(C-2)*dp[k-1][2]+(R-1)*dp[k-1][3] )%MOD;
		dp[k][3]=( dp[k-1][1]+dp[k-1][2]+(R+C-4)*dp[k-1][3] )%MOD;
	}
	printf("%ld",dp[K][ (x1!=x2)| (y1!=y2)<<1 ]);
}