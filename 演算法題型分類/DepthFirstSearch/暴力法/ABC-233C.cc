#include<bits/stdc++.h>
using namespace std;

const int MaxPL=1e5;
const int MaxA=1e9;
const long MaxX=1e18;

vector<vector<int>> num;
void DFS(int depth,long v,int& ans){
	if(depth==-1){ 
		ans+= v==1; 
		return;
	}
	for(int rhs: num[depth])
		if(v%rhs==0)
			DFS(depth-1,v/rhs,ans);
}
int main(){
	int N, C;
	long X;
	
	scanf("%d %ld",&N,&X);
	num.resize(N);
	for(int n=0; n<N; n+=1){
		scanf("%d",&C);
		num[n].resize(C);
		for(int c=0; c<C; c+=1)
			scanf("%d",&num[n][c]);
	}
	int ans=0;
	DFS(N-1,X,ans);
	printf("%d",ans);
}