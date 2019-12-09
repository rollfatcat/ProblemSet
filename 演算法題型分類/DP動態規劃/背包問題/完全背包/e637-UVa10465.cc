// 無限背包問題變形：在最大化空間的前提下最大化物品個數。
#include <bits/stdc++.h>
using namespace std;

const int MaxN=1e4; // 0 < m,n,t < 10000
const int MaxM=1e4;
const int MaxT=1e4;
int rem[MaxT]={};
int cnt[MaxT]={};
int main(){
	int N, M, T;
	while(scanf("%d %d %d",&N,&M,&T)==3){
		for(int i=1;i<=T;i++){
			cnt[i]=i/N;
			rem[i]=i-cnt[i]*N;
		}
		for(int i=M;i<=T;i++)
			if(rem[i]>rem[i-M] or (rem[i]==rem[i-M] and cnt[i-M]+1>cnt[i])){
				cnt[i]=cnt[i-M]+1;
				rem[i]=rem[i-M];
			}
		printf("%d",cnt[T]);
		(rem[T]>0)? printf(" %d\n",rem[T]): printf("\n");
	}
}

