/* 給定Ｎ個點和Ｍ條雙向邊，輸出在完全圖(組合內的點彼此都有一條線連在一起)，點數最多是多少？
 * 解題關鍵：暴力法枚舉每個點(選或不選)組合＋狀態壓縮( 用一個整數描述和點Ａ相連的所有邊 )
 * 
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=22;
const int MaxM=250; // 21*11=231
int N, maxG;
int to[MaxN+1];
 
void Recursive(int InG_S,int st,int nowG){
	maxG=max(maxG,nowG);
	for(int i=st;i<=N;i++)
		if( (to[i]&InG_S) == InG_S)
			Recursive(InG_S|(1<<i),i+1,nowG+1);
}
 
int main(){
	int M, u, v;
	while(scanf("%d %d\n",&N,&M)!=EOF){
		for(int i=1;i<=N;i++) 
			to[i]=1<<i;
		while(M-->0){
			scanf("%d %d\n",&u,&v);
			to[u]|= 1<<v;
			to[v]|= 1<<u;
		}
		maxG=0;
		for(int i=1;i<=N;i++)
			Recursive(1<<i,i+1,1);
		printf("%d\n",maxG);
	}
}