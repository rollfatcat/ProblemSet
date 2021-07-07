/* 給定ＮxＮ地圖時，由ｕ一步移動過去ｖ時有ｓ種方法(有向邊)，必須輸出移動Ｋ步時可以從查詢的起點到終點的方法數？
 * 解題關鍵：DynamicProgramming + Binary Exponentiation(快速幂)
 * Status definition : 2D matrix maintain the methods in one step, enumerate all pairs (st, ed)
 * Status transition : matrix multiplication
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=50;
const int MaxS=20;
const int MaxQ=25e2;
const int MaxK=1e7;
const int MOD=5281;
 
int N, K, Q;
int mat[4][MaxN][MaxN];
// matrix multiple
void multiple(int a,int b,int c){
	for(int i=0;i<N;i+=1)
		for(int j=0;j<N;j+=1){
			mat[c][i][j]=0;
			for(int k=0;k<N;k+=1)
				mat[c][i][j]+= mat[a][i][k]*mat[b][k][j];
			mat[c][i][j]%=MOD;	
		}
}
int main(){
	int u, v, s;
	while(scanf("%d %d",&N,&K)!=EOF){
		// init matrix
        for(int r=0;r<N;r+=1){
			fill(mat[0][r],mat[0][r]+N,0);
			fill(mat[2][r],mat[2][r]+N,0);
			mat[2][r][r]=1;
		}
        // matrix status maintain the methods in one step, enumerate all pairs (st, ed)
		while(scanf("%d %d %d",&u,&v,&s) and u>0)
			mat[0][u-1][v-1]=s;
        // BinaryExponentiation(快速幂)
		int p_now=0;
		int p_nxt=1;
		int v_now=2;
		int v_nxt=3;
		if(K&1){
			multiple(v_now,p_now,v_nxt);
			swap(v_now,v_nxt);
		}
		for(K>>=1; K>0; K>>=1){
			multiple(p_now,p_now,p_nxt);
			swap(p_now,p_nxt);
			if(K&1){
				multiple(v_now,p_now,v_nxt);
				swap(v_now,v_nxt);
			}
		}
        // online-query 
		scanf("%d",&Q);
		while(Q-->0){
			scanf("%d %d",&u,&v);
			printf("%d\n",mat[v_now][u-1][v-1]);
		}
	}
}