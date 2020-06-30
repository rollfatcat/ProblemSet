/* 給定Ｑ次查詢，輸出(ｎ,ｍ)區間內最長的循環長度
 * sopf(x)是ｘ的質因數總和，而循環長度則是對於 sopf 函數進行迭代的次數 直到sopf(x)＝x 。
 * 根據sopf(x)是ｘ的質因數總和，可以判斷ｘ是質數時循環長度＝1 且 spof(x) ≦ x(除了４例外)。
 * 換句話說，計算ｘ時 spof(x)循環長度必定已經算過，ｘ不為質數時循環長度＝spof(x)的循環長度+1。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e5;
const int MaxQ=150;
int psum[MaxN+1]={};
int cycl[MaxN+1];

int main(){
	for(int i=4;i<=MaxN;i+=2)
		for(int j=i; (j&1)==0; j>>=1)
			psum[i]+=2;
	for(int i=3;i<=MaxN;i+=2)
		if(psum[i]==0)
			for(int j=i; j<=MaxN; j+=i)
				for(int k=j; (k%i)==0; k/=i)
					psum[j]+=i;
	for(int i=2;i<=MaxN;i++)
		cycl[i]=(psum[i]==i)? 1:cycl[psum[i]]+1;
	
	int Q, n, m, ans; 
	scanf("%d\n",&Q);
	for(int Qid=1;Qid<=Q;Qid++){
		scanf("%d %d\n",&n,&m);
		if(n>m) swap(n,m);
		ans=cycl[n];
		for(int i=n+1;i<=m;i++)
			ans=max(ans,cycl[i]);
		printf("Case #%d:\n%d\n",Qid,ans);
	}
}