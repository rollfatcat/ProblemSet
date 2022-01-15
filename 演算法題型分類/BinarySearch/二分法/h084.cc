#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5; 
const int MaxK=5e4; 
const int MaxH=1e9;

int N, K;
int hgt[MaxN];
int prS[MaxN]; // prS[n] = 往後(右)數連續(包含這跟木板)
int num[MaxK];

bool check(int Hm,int n=N-1){
	prS[n]= hgt[n]>=Hm;
	for(n-=1; n>=0; n-=1)
		prS[n]=(hgt[n]>=Hm)?prS[n+1]+1: 0;
	n=0;
	for(int k=0; k<K; k+=1){
		while(n<N and prS[n]<num[k])
			n+=prS[n]+1;
		if(n>=N) return false;
		n+=num[k];
	}
	return true;
}
int main(){
	scanf("%d %d",&N,&K);
	for(int n=0; n<N; n+=1)
		scanf("%d",&hgt[n]);
	for(int k=0; k<K; k+=1)
		scanf("%d",&num[k]);
	int L=1;
	int R=MaxH;
	int ans;
	while(L<=R){
		int M=L+R>>1;
		if( check(M) ){
			ans=M;
			L=M+1;
		}else
			R=M-1;
	}
	printf("%d",ans);
}
