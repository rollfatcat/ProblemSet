/* 難題：理解矩陣乘法的"代價"，決定什麼時候採用逐項計算較優
 * 求數列第Ｋ項的數字？
 * 該數列是仿費波那契數列：第Ｋ項的數值＝由前Ｎ項的和，初始化的Ｎ項都是１
 * 當Ｋ極大時 ＝ 快速幂的矩陣乘法，但矩陣乘法的時間是Ｎ^3
 */
#include<bits/stdc++.h>
using namespace std;

const int M=1e9+7;
const int MaxT=1e4;
const int MaxN=30;
const long MaxK=(long)1<<50;

long mat[31][50][30][30]={};
long kpt[2][30][30];
long dpv[MaxN];

inline long lowbit(long x){ return x&-x; } 
inline long FastMul(int N,long K,long ans=0){
	memset(kpt,0,sizeof(kpt));
	for(int i=0;i<N;i++)
		kpt[0][i][i]=1;
	bool pre=0, now=1;
	for(long P;K>0;K^=P){
		P=lowbit(K);
		for(int x=0;x<N;x++)
			for(int y=0;y<N;y++){
				kpt[now][x][y]=0;
				for(int t=0;t<N;t++)
					kpt[now][x][y]=(kpt[now][x][y]+kpt[pre][x][t]*mat[N][__lg(P)][t][y])%M;
			}
		swap(pre,now);
	}
	for(int i=0;i<N;i++)
		ans+=kpt[pre][0][i];
	return ans%M;
}
inline long OneByOne(int N,long K){
	dpv[0]=N;
	for(int i=1;i<=N;i++)
		dpv[i]=1;
	int t=N+2, p1=0;
	for(int p2=1;t<=K;t++,p1=p2,p2=(p2+1)%(N+1)){
		dpv[p2]=((dpv[p1]<<1)-dpv[p2])%M;
		if(dpv[p2]<0) dpv[p2]+=M;
	}
	return dpv[p1];
}
int main(){
	for(int N=2;N<=MaxN;N++){
		mat[N][0][0][0]=1;
		for(int i=1;i<N;i++)
			mat[N][0][0][i]=mat[N][0][i][i-1]=1;
		for(int P=1;P<50;P++)
			for(int x=0;x<N;x++)
				for(int y=0;y<N;y++)
					for(int t=0;t<N;t++)
						mat[N][P][x][y]=(mat[N][P][x][y]+mat[N][P-1][x][t]*mat[N][P-1][t][y])%M;
	}
	
	int T, N;
	long K, ans;
	scanf("%d\n",&T);
	while(T--){
		scanf("%d %ld\n",&N,&K);
		(K<=N)? puts("1"):printf("%ld\n",(__builtin_popcountll(K)*N*N*N<K)? FastMul(N,K-N): OneByOne(N,K));
	}
}