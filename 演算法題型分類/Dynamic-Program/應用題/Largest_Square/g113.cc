#include<bits/stdc++.h>
using namespace std;

const int MaxL=300+1;
const int MaxN=1e5;
int cnt[MaxL][MaxL][MaxL]={};
int len[MaxL][MaxL][MaxL]={};
int min_len(int a,int b,int c){
	return min(
		min( min(len[a-1][b-1][c],len[a][b][c-1]),
	       min(len[a-1][b][c-1],len[a][b-1][c])),
	  min( min(len[a][b-1][c-1],len[a-1][b][c]),len[a-1][b-1][c-1]) );
}
int main(){
	int A, B, C, N, x, y, z;
	
	scanf("%d %d %d %d",&A,&B,&C,&N);
	for(int a=1;a<=A;a+=1)
		for(int b=1;b<=B;b+=1)
			for(int c=1;c<=C;c+=1)
				len[a][b][c]=1;
	for(int i=0;i<N;i+=1){
		scanf("%d %d %d",&x,&y,&z);
		len[x][y][z]=0;
	}
	// dp
	for(int a=1;a<=A;a+=1)
		for(int b=1;b<=B;b+=1)
			for(int c=1;c<=C;c+=1){
				if(len[a][b][c]==1)
					len[a][b][c]=min_len(a,b,c)+1;
				cnt[a][b][c]=len[a][b][c]+cnt[a-1][b][c]+cnt[a][b-1][c]+cnt[a][b][c-1]-cnt[a-1][b-1][c]-cnt[a-1][b][c-1]-cnt[a][b-1][c-1]+cnt[a-1][b-1][c-1];
			}
	printf("%d\n",cnt[A][B][C]);
}

