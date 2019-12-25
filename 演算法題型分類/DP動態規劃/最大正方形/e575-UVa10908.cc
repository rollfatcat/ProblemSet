/* 找尋最大正方形(方形內的字元必須相同)：標準動態規劃題
 * 只有當現在這格的字元和左上/左/上三格的字元相同時才做狀態轉移
 * 但題目要求是『輸出以(i,j)為中心構成的最大正方形邊長』
 * 透過動態規劃算出的最大正方形紀錄在該方形的最右下角,必須轉換為紀錄在中心點(i,j)：從右下角往左上的方向根據最大正方形邊長更新即可。
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxCaseT=20;
const int MaxQ=20;
const int MaxN=100;
const int MaxM=100;

int main(){
	int caseT;
	int N, M, Q;
	int ans[MaxM][MaxN];
	int maxS[MaxM][MaxN];
	char maps[MaxM][MaxN];
		
	scanf("%d",&caseT);
	while(caseT--){
		scanf("%d %d %d",&M,&N,&Q);
		printf("%d %d %d\n",M,N,Q);
		for(int i=0;i<M;i++)
			scanf("%s",maps[i]);
		//
		for(int i=0;i<N;i++)
			maxS[0][i]=ans[0][i]=1;
		for(int i=0;i<M;i++)
			maxS[i][0]=ans[i][0]=1;
		for(int i=1;i<M;i++)
			for(int j=1;j<N;j++){
				maxS[i][j]=(maps[i][j]==maps[i-1][j-1] and maps[i][j]==maps[i-1][j] and maps[i][j]==maps[i][j-1])? min(maxS[i-1][j-1],min(maxS[i-1][j],maxS[i][j-1]))+1: 1;
				for(int k=1;k<=maxS[i][j];k+=2)
					ans[i-(k>>1)][j-(k>>1)]=k;
			}
		// 根據輸入的格子, 輸出最大方形邊長
		for(int x,y;Q>0;Q--)
			scanf("%d %d",&x,&y),
			printf("%d\n",ans[x][y]);
	}
}