/* 給定Ｑ次查詢，輸出(ｎ,ｍ)區間內最長的循環長度
 * sopf(x)是ｘ的質因數總和，而循環長度則是對於 sopf 函數進行迭代的次數 直到sopf(x)＝x 。
 * 根據sopf(x)是ｘ的質因數總和，可以判斷ｘ是質數時循環長度＝1 且 spof(x) ≦ x(除了４例外)。
 * 換句話說，計算ｘ時 spof(x)循環長度必定已經算過，ｘ不為質數時循環長度＝spof(x)的循環長度+1。
 * 因為查詢的範圍極大，可以利用線段樹改善。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e5;
int psum[MaxN+1]={};
int leaf[MaxN+1];
int cycl[MaxN*3];
int caseT, n, m, ans;

inline void NewSegTree(int nL,int nR,int idx){
	if(nL==nR){ 
		leaf[nL]=idx;
		cycl[idx]=(psum[nL]==nL)? 1: cycl[ leaf[psum[nL]] ]+1; 
		return;
	}
	int nM=nL+nR>>1;
	NewSegTree(  nL,nM,  idx<<1);
	NewSegTree(nM+1,nR,idx<<1|1);
	cycl[idx]=max(cycl[idx<<1],cycl[idx<<1|1]);
}
inline int QuerySeg(int nL,int nR,int idx){
	if(n<=nL and nR<=m) return cycl[idx];
	int nM=nL+nR>>1;
	if(m<=nM) return QuerySeg(  nL,nM,  idx<<1);
	if(nM<n)  return QuerySeg(nM+1,nR,idx<<1|1);
	return max(QuerySeg(nL,nM,idx<<1),QuerySeg(nM+1,nR,idx<<1|1));
}
int main(){
	for(int i=4;i<=MaxN;i+=2)
		for(int j=i; (j&1)==0; j>>=1)
			psum[i]+=2;
	for(int i=3;i<=MaxN;i+=2)
		if(psum[i]==0)
			for(int j=i; j<=MaxN; j+=i)
				for(int k=j; (k%i)==0; k/=i)
					psum[j]+=i;
					
	NewSegTree(1,MaxN,1);
	
	scanf("%d\n",&caseT);
	for(int caseI=1;caseI<=caseT;caseI++){
		scanf("%d %d\n",&n,&m);
		if(n>m) swap(n,m);
		printf("Case #%d:\n%d\n",caseI,QuerySeg(1,MaxN,1));
	}
}