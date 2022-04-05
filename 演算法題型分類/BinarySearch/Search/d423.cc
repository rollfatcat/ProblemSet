/* 給定Ｎ代表某個階乘的質因數的個數前綴和，若該階乘存在則輸出數字否則輸出"Not possible."
 * 解題關鍵：sieve＋質因數分解＋前綴和＋二分搜尋法
 * 問題點：題目給的Ｎ並非代表質因數前綴和的涵蓋的範圍，需確保能判斷 1e7+1 範圍內的質數(假設每個數都質數時)。
 * 基於上述要求建表的質數範圍為 sqrt(1e7+1)，建表後從２開始枚舉做質因數分解。
 * 因為階乘的特性質因數個數就是前綴和：fac(N!)=fac(N)+fac( (N-1)! )
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxK=1e7+1;
int cnt[MaxK+1]={}; // cnt[x] = x 的質因數個數
int main(){
	// sieve: factorial
	for(int n=2; n<=MaxK; n++){
		if( cnt[n]>0 ) continue;
		for(long p=1; n*p<=MaxK; p++){
			cnt[n*p]++;
			for(int v=p; v%n==0; v/=n)
				cnt[n*p]++;
		}
	}
	for(int n=3; n<=MaxK; n++)
		cnt[n]+=cnt[n-1];
	//
	int K, tag;
	for(int caseI=1; scanf("%d",&K) and K>=0; caseI++){
		tag=lower_bound(cnt,cnt+MaxK+1,K)-cnt;
		printf("Case %d: ",caseI);
		(cnt[tag]==K)? printf("%d!\n",tag): puts("Not possible.");
	}
}