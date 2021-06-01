#include<bits/stdc++.h>
using namespace std;

const int MaxN=50;
const int MaxM=50;
const int MaxT=1e3;
int t[MaxN][MaxM];

int main(){
	int N, M;
	scanf("%d %d",&N,&M);
	for(int r=0; r<N; r+=1)
		for(int c=0; c<M; c+=1)
			scanf("%d",&t[r][c]);
	// boundary case
	for(int r=1; r<N; r+=1)
		t[r][0]+=t[r-1][0];	
	for(int c=1; c<M; c+=1)
		t[0][c]+=t[0][c-1];
	for(int r=1; r<N; r+=1)
		for(int c=1; c<M; c+=1)
			t[r][c]+=max(t[r-1][c],t[r][c-1]);
	printf("%d\n",t[N-1][M-1]);
	
}