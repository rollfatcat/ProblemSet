/* 給定Ｎ組的資料(T,X,A)代表在時間Ｔ時位置Ｘ會出現隻大小為Ａ的 Snuke ，透過移動最多可以抓獲大小多少的 Snuke
 * Takahashi 一開始會從第０號的坑道出發，切換到相鄰的坑道需要至少一單位的時間
 * 解題關鍵：動態規劃
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxT=1e5;
const int MaxX=4;
const int MaxA=1e9;
long dp[MaxT+1][MaxX+1]={};
int main(){
	int N, t, x, a;
	long v;
	
	scanf("%d",&N);
	while(N-->0){
		scanf("%d %d %d",&t,&x,&a);
		if(t<x) continue; // sample 2 的 output = 0 ... 受限於出發時只能在第０坑道的限制
		dp[t][x]+=a;
	}
	for(t=1; t<=MaxT; t++)
		for(x=0; x<=4; x++){
			v=dp[t-1][x];
			if(0<x) v=max(v,dp[t-1][x-1]);
			if(x<4) v=max(v,dp[t-1][x+1]);
			dp[t][x]+=v;
		}
	v=dp[MaxT][0];
	for(x=1; x<=4; x++)
		v=max(v,dp[MaxT][x]);
	printf("%ld",v);
}