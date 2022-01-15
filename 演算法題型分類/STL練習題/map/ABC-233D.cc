#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxA=1e9;
const long MaxK=1e15;
long prS[MaxN+1];
int main(){
	int N, v;
	long K;
	prS[0]=0;
	
	scanf("%d %ld",&N,&K);
	for(int n=1; n<=N; n+=1){
		scanf("%d",&v);
		prS[n]=prS[n-1]+v;
	}
	
	long ans=0;
	map<long,int> memo;
	memo[prS[N]]=1;
	for(int n=N-1; n>=0; n-=1){
		ans+= memo[ prS[n]+K ];
		memo[prS[n]]+=1;
	}
	printf("%ld\n",ans);
}