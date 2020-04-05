/* 標準無限制背包模板題
 * 給定Ｎ(Ｎ≦100)問可以用整數組合出總和為Ｎ的方法數。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=100; // 1≦Ｎ≦100
int cnt[MaxN]={1};
int main(){
	int N; 
	scanf("%d\n",&N);
	for(int i=1;i<=N;i++)
		for(int j=i;j<=N;j++)
			cnt[j]+=cnt[j-i];
	printf("%d\n",cnt[N]);
}
