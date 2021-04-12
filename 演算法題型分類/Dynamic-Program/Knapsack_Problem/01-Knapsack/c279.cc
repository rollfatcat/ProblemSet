/* 給定Ｎ輸出可以拆成最多個相異的質數和？
 * 解題關鍵：01-knapsack problem
 * 注意：１無法拆解為任意個質數和，輸出-1
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e4;
bool notp[MaxN+1]={};
int  cnt[MaxN+1]={0,-1,1};
int main(){
	int N;
	scanf("%d\n",&N);
	
	for(int i=2;i<=N;i+=2)
		notp[i]=1;
	for(int i=3; i<=N; i+=2){
		if(notp[i]) continue;
		for(int j=i*i; j<=N; j+=i) 
			notp[j]=1;
		for(int j=N; j>=i; j-=1)
			if(cnt[j-i]+1>cnt[j])
				cnt[j]=cnt[j-i]+1;
	}
	printf("%d\n",cnt[N]);
}