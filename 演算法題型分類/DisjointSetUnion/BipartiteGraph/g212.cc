/*
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxP=2e5;
int root[MaxN+1<<1];
int  cnt[MaxN+1<<1][2];
int FindRoot(int x){
	return root[x]==x? x: root[x]=FindRoot(root[x]); }
void Union(int a,int b,long& ans){
	int Ra=FindRoot(a);
	int Rb=FindRoot(b);
	if(Ra==Rb) return;
	ans-=(long)cnt[Ra][0]*cnt[Ra][1]+(long)cnt[Rb][0]*cnt[Rb][1];
	root[Rb]=Ra;
	cnt[Ra][0]+= cnt[Rb][0];
	cnt[Ra][1]+= cnt[Rb][1];
	ans+=(long)cnt[Ra][0]*cnt[Ra][1];
}
int main(){
	// init
	for(int i=1;i<=MaxN;i+=1){
		root[i]=i;  root[i+MaxN]=i+MaxN;
		cnt[i][0]=1; cnt[i+MaxN][0]=0;
		cnt[i][1]=0; cnt[i+MaxN][1]=1;
	}
	int N, x, y;
	long ans=0;
	scanf("%d",&N);
	for(int i=0;i<N;i+=1){
		scanf("%d %d",&x,&y);
		Union(x,y+MaxN,ans);
		printf("%ld\n",ans);
	}
}