#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxM=2e5;
const int MaxW=1e2;
const int MaxT=1e2;

int prS[MaxN+1]={};
int num[MaxN+1];
int main(){
	int N, M, s, f, w;
	
	scanf("%d %d",&N,&M);
	while(M-->0){
		scanf("%d %d %d",&s,&f,&w);
		prS[s-1]+=w;
		prS[ f ]-=w;
	}
	for(int i=0;i<N;i+=1)
		scanf("%d",&num[i]);
	
	for(int i=1;i<N;i+=1)
		prS[i]+=prS[i-1];
	sort(num,num+N);
	sort(prS,prS+N);
	long ans=0;
	for(int i=0;i<N;i+=1)
		ans+=(long)num[N-1-i]*prS[i];
	printf("%ld",ans);
}