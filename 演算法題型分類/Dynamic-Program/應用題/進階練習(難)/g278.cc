/* 給定Ｎ個美食編號(１≤ａ≤ 1e5)和Ｋ位委員，輸出所有委員加起來能嚐到最多的美食個數？
 * 每位委員會選擇一段連續的攤位試吃，而每個人都不想要吃到同一種自己曾經吃過的美食。
 * 		因此一位委員所選到的範圍不能有同一種美食重複出現 ... 區間內的美食編號不能重複出現
 * 解題盲點：選擇前Ｋ長的區間累加 ... 無法保證區段是不重疊
 * 需要先計算第Ｎ格往左邊搜尋時能延伸到的位置 : pvt[Ｎ]
 * 狀態定義： dp[Ｋ][Ｎ]=有Ｋ位委員且目前位置是Ｎ
 * 狀態轉移： dp[Ｋ][Ｎ]=max(dp[Ｋ][Ｎ-1],dp[Ｋ-1][pvt[Ｎ]]+Ｎ-pvt[Ｎ])
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxK=20;
const int MaxA=1e5;

int num[MaxN+1]={};
int pvt[MaxN+1]; // extend from most left 
int pre[MaxA+1]={};
int dp[MaxK+1][MaxN+1]={};
int main(){
	int N, K, p=0;
	
	scanf("%d %d",&N,&K);
	num[0];
	for(int i=1; i<=N; i+=1){
		scanf("%d",&num[i]);
		// find the previous
		while( p<=pre[num[i]] )
			pre[ num[p++] ]=0;
		pre[num[i]]=i;
		pvt[i]=p-1;
	}
	
	for(int i=1; i<=N; i+=1)
		for(int k=K; k>0; k-=1)
			dp[k][i]=max(dp[k][i-1],dp[k-1][pvt[i]]+i-pvt[i]);
			
	printf("%d\n",dp[K][N]);
}
/*
num= 1 7 1 3 1 4 4 2 7 4
pvt= 0 0 1 1 3 3 6 6 6 7
k=0  0 0 0 0 0 0 0 0 0 0
k=1  1 2 2 3 3 3 3 3 3 3
k=2  x x 3 4 4 5 5 5 6 6
k=3  x x x x 5 6 6 7 8 8
*/