#include<bits/stdc++.h>
using namespace std;

const int MaxT=5e2;
const int MaxN=1e3;
const int MaxA=1e6;

int N, num[MaxN];
bool check(int x,int rem){
	for(int day, n=N-1; 0<=n; n-=1){
		if(x==0) return false;
		day=num[n]/x+(num[n]%x>0);
		if(rem<day) return false;
		rem-=day;
		x--;
	}
	return true;
}

int main(){
	int caseT;
	
	scanf("%d",&caseT);
	while(caseT-->0){
		scanf("%d",&N);
		for(int n=0; n<N; n+=1)
			scanf("%d",&num[n]);
		sort(num,num+N);
		int nL=1;
		int nR=MaxA;
		int ans;
		while(nL<=nR){
			int nM=nL+nR>>1;
			if(check(nM,nM)){
				ans=nM;
				nR=nM-1;
			}else
				nL=nM+1;
		}
		printf("%d\n",ans);
	}
}