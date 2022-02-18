#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e5;
const int MaxQ=1e5;
const int MaxA=1e3;
const int MaxK=1e9;

int num[MaxN+1];
int BIT[MaxN+1]={};
int lowbit(int x){ return x&-x; }
int Qry(int p,int ret=0){
	for(; p>0; p-=lowbit(p))
		ret+=BIT[p];
	return ret;
}
/*
void Upd(int p,int v){
	for(; p<=N; p+=lowbit(p))
		BIT[p]+=v;
}
*/
int main(){
	int N, Q, o, p, v, k;
	
	scanf("%d %d",&N,&Q);
	for(int n=1; n<=N; n+=1){
		scanf("%d",&num[n]);
		for(int p=n; p<=N; p+=lowbit(p))
			BIT[p]+=num[n];
	}
	
	while(Q-->0){
		scanf("%d",&o);
		if(o==1){
			scanf("%d %d",&p,&v);
			// BIT update
			for(int n=p; n<=N; n+=lowbit(n))
				BIT[n]+=v-num[p];
			num[p]=v;
		}else{// Binary_Search
			scanf("%d",&k);
			int ans=N+1;
			int nL=1;
			int nR=N;
			while(nL<=nR){
				int nM=nL+nR>>1;
				if( Qry(nM)>=k ){
					nR=nM-1;
					ans=nM;
				}else
					nL=nM+1;
			}
			(ans==N+1)? puts("meh"): printf("%d\n",ans);
		}
	}
}