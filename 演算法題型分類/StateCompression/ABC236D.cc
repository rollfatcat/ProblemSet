#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=8<<1;
const int MaxA=1<<30;

int N, ans=0;
int mat[MaxN][MaxN];
/* 枚舉：一次挑２個數字，time complexity = 16*14*12*10*8*6*4*2 = 1e7 */
void func(int S,int v){
	if(S==0){ ans=max(ans,v); return; }
	int pb, pa=S&-S; 
	for(int Sb=S^pa; Sb>0; Sb^=pb){
		pb=Sb&-Sb;
		func(S^pa^pb,v^mat[__lg(pa)][__lg(pb)]);
	}
}
int main(){
	// input
	scanf("%d",&N); N<<=1;
	for(int a=0; a<N; a+=1)
		for(int b=a+1; b<N; b+=1){
			scanf("%d",&mat[a][b]);
			mat[b][a]=mat[a][b];
		}
	// brute-force
	func((1<<N)-1,0);
	printf("%d",ans);
}