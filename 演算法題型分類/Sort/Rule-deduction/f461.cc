/* 多筆測資，給定Ｎ個數字，任選２個數字差值的總和。
 * 解題關鍵：排序
 * 計算差值時考慮到大減小，針對每個數字計算到的次數(權重)可以發現規律。
 * Ｎ＝５
 * sorted: v0 v1 v2 v3 v4
 * weight: -4 -2  0  2  4
 * Ｎ＝６
 * sorted: v0 v1 v2 v3 v4 v5
 * weight: -5 -3 -1  1  3  5 
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=1e2;
const int MaxN=1e5;
 
int num[MaxN];
int main(){
	int N;
	while(scanf("%d\n",&N)!=EOF){
		for(int i=0;i<N;i++)
			scanf("%d",&num[i]);
		sort(num,num+N);
 
		long w=N-1;
		long ans=0; 
		for(int i=0;i<(N>>1);i++,w-=2)
			ans+=(num[N-1-i]-num[i])*w;
		printf("%ld\n",ans);
	}
}
