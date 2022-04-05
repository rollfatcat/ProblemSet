/* 與 基地台 是相同問題
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxV=1e4;
const int INF=1<<30;
int v[MaxN];
int N, K;

inline bool IsSafe(int nowv){
	int rem=nowv, cnt=1;
	for(int i=0;i<N;i++){
		if(rem<v[i]){
			if(++cnt>K)
				return false; 
			rem=nowv;
		}
		rem-=v[i];
	}
	return cnt<=K;
}
int main(){
	scanf("%d %d\n",&N,&K);
	int nL=0, nR=0;
	for(int i=0;i<N;i++){
		scanf("%d",&v[i]);
		nL=max(nL,v[i]);
		nR+=v[i];
	}
	for(int nM;nL<nR;(IsSafe(nM))? nR=nM: nL=nM+1)
		nM=nL+nR>>1;
	printf("%d\n",nL);
}