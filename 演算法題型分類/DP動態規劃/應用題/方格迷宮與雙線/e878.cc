/* 動態規劃題：最大連續區間和＋方向限制的路線
 * 題目給定一個二維陣列，規定移動方式只能向右和向下，但可以任選起點和終點，問路線上最大的數值和？
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=3001; // ３≤ｎ,ｍ≤ ３000 
int cont[MaxN][MaxN];
int best[MaxN][MaxN];
int main(){
 
	int N, M, v;
	scanf("%d %d\n",&N,&M);
	for(int i=0;i<=N;i++) cont[i][0]=best[i][0]=0;
	for(int i=0;i<=M;i++) cont[0][i]=best[0][i]=0;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
			scanf("%d",&v);
			cont[i][j]=max(0,max(cont[i-1][j],cont[i][j-1]))+v;
			best[i][j]=max(cont[i][j],max(best[i-1][j],best[i][j-1]));
	}
	printf("%d\n",best[N][M]);
}
/* === input 2 ===
3 5 
5 -8 5 2 4  
1 1 -9 1 -2  
2 -9 3 -3 9
 */