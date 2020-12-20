/* 經典分堆問題：轉換為01背包問題
 * 能否用Ｎ個數字組合出總合一半的數值(若為奇數必定不能分成等值的兩組)
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxN=20;
const int MaxM=200;
int num[MaxN];
int DP[MaxN*MaxM/2+1];
int main() {
	int caseT, N, M, sum;
	char ch;
	scanf("%d\n",&caseT);
	while(caseT--){
		for(sum=N=0;scanf("%d%c",&M,&ch)==2 and ch==' ';sum+=M)
			num[N++]=M;
		num[N++]=M, sum+=M;
		
		if(sum&1){ puts("NO"); continue; }
		sum>>=1;
		fill(DP,DP+sum+1,0);
		for(int i=0;i<N;i++)
			for(int j=sum;j>=num[i];j--)
				DP[j]=max(DP[j],DP[j-num[i]]+num[i]);
		puts((DP[sum]==sum)?"YES":"NO");
	}
}