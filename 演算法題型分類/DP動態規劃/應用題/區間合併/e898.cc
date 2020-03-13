/* 題目給定一個數列並逐一合併直到數列中只剩2個數字，問過程中如何合併才能最大化最後的數值？
 * 合併：[x1 x2 x3] → [x1 x3]時 v+=x1*x3
 * 狀態轉移：
 *      DP[L][R]=max(DP[L][M]+DP[M][R])+v[L]*v[R] L<M<R
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxN=1000; // Ｎ≦ 1000
const int MaxV=100;  // 1 ≦Ｖ≦ 100
 
int  num[MaxN];
int memo[MaxN][MaxN]={};
inline int TopDown(int L,int R){
	if(R-L<2) return 0;
	if(memo[L][R]==0){
		for(int M=L+1;M<R;M++)
			memo[L][R]=max(memo[L][R],TopDown(L,M)+TopDown(M,R));
		memo[L][R]+=num[L]*num[R];
	}
	return memo[L][R];
}
 
int main() {
	for(int N;scanf("%d\n",&N)!=EOF;){
		for(int i=0;i<N;i++)
			scanf("%d",&num[i]);
		for(int len=2;len<N;len++)
			for(int st=0,ed=len;ed<N;st++,ed++){
				memo[st][ed]=max(memo[st][ed-1],memo[st+1][ed]);
				for(int M=st+2;M<ed-1;M++)
					memo[st][ed]=max(memo[st][ed],memo[st][M]+memo[M][ed]);
				memo[st][ed]+=num[st]*num[ed];
			}
		printf("%d\n",memo[0][N-1]);
	}
}