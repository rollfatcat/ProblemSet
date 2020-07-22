/* 給定１０００個物品的重量、需求度和最大的乘載力，最大化可獲得的需求度？
 * 麻煩處：題目並未在一開始給定物品的數量，只有說明"第一行記錄所有物品的重量"。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
const int MaxLoad=1e6+1;
int data[MaxN][2];
int dp[MaxLoad]={};

int main(){
	int Load, N=0;
	char ss[12];
	/* 輸入的第一行同時判斷物品的數量，格式必定為"數字＋字元"，只需判斷字元為換行 */
	while(scanf("%d",&data[N++][0]) and getchar()!='\n');
	for(int i=0;i<N;i++)
		scanf("%d",&data[i][1]);
	scanf("%d\n",&Load);
	for(int i=0;i<N;i++)
		for(int j=Load;j>=data[i][0];j--)
			dp[j]=max(dp[j],dp[j-data[i][0]]+data[i][1]);
	printf("%d\n",dp[Load]);
}