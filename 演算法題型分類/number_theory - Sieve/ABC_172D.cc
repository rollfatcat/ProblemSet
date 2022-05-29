/* 給定Ｎ，輸出 ∑Ｎ×f(Ｎ)，f(Ｎ)為Ｎ的因數個數
 * 解題關鍵：篩法
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e7;
int main(){
	int N;
	long ans=0;
	
	scanf("%d",&N);
	for(int n=1; n<=N; n++)
		for(int p=n; p<=N; p+=n)
			ans+=p;
	printf("%ld",ans);
}