#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxH=INT_MAX;

int hgt[MaxN];
int srt[MaxN];
int org[2][MaxN+1]={};
int BIT[2][MaxN+1]={};

int lowbit(int x){ return x&-x; }
void Update(int k,int p,int v,int& N){
	for(org[k][p]=v; p<=N and BIT[k][p]<v; p+=lowbit(p))
		BIT[k][p]=v;
}
int Query(int k,int p,int ret=0){
	for(; 0<p; p-=lowbit(p))
		ret=max(ret,BIT[k][p]);
	return ret;
}

int main(){
	int N, t, v0, v1;
	
	scanf("%d",&N);
	for(int n=0; n<N; srt[n]=hgt[n], n++)
		scanf("%d",&hgt[n]);
	sort(srt,srt+N);
	for(int n=0; n<N; n++){
		t=lower_bound(srt,srt+N,hgt[n])-srt+1;
		v0=Query(0,t-1)+1;
		v1=Query(1,N-t)+1;
		Update(1,N-t+1,v0,N);
		Update(0,  t  ,v1,N);
	}
	int ans=Query(1,N);
	printf("%d",ans-((ans&1)==0));
}