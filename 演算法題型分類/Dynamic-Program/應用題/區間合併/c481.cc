/* 給定(一維的)Ｎ格顏色作為目標，輸出最好需要著色幾次才能從"白紙"畫成目標的顏色？
 * 著色：一筆畫把連續的格子塗上相同顏色,並且覆蓋過原先塗在格子上的顏色
 * 解題關鍵：動態規劃(區間合併系列)的 Bottom-Up 形式
 *      所有狀態：dp[左邊界][右邊界]=區間內最少的著色次數
 *      狀態轉移：
 *          左邊界==右邊界，代表格子數=1 至少要著色１次
 *          左邊界!=右邊界，考慮"一筆畫的延伸特性"
 *               (1)最右邊的格子顏色＝最右邊往左一格顏色一樣 (2)最右和最左邊格子顏色相同時 著色次數不變
 *               (3)其他，枚舉中間位置分成左右兩邊找出總和最小的著色次數。
 *      注意事項：TopDown 時可以枚舉左右兩邊界但 Bottom-Up時需要確保"子問題"的狀態已經更新完成所以要枚舉的方式
 *              改為枚舉寬度和左邊界，而右邊界可以透過兩者推算出(枚舉左右邊界是無法確保子問題狀態已解決)。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=20;
const int MaxN=2e2;
const int MaxM=2e2;
const int INF=1<<30;

int color[MaxN];
int dp[MaxN][MaxN];
/* TopDown(20%) */
int DP_ReCursive(int nL,int nR){
	if(nL==nR){ dp[nL][nR]=1; return 1; }
	if(color[nL]==color[nR] or color[nR]==color[nR-1])
		dp[nL][nR]=DP_ReCursive(nL,nR-1);
	else{
		dp[nL][nR]=INF;
		for(int pvt=nL; pvt<nR; pvt++)
			dp[nL][nR]=min(dp[nL][nR],DP_ReCursive(nL,pvt)+DP_ReCursive(pvt+1,nR));
	}
	return dp[nL][nR];
}
int main(){
	int caseT, N, M;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d\n",&N,&M);
		for(int i=0;i<N;i++){
			scanf("%d",&color[i]);
			dp[i][i]=1;
		}
		for(int w=2;w<=N;w++)
			for(int nL=0,nR=nL+w-1; nR<N; nL++,nR++)
				if(color[nL]==color[nR] or color[nR-1]==color[nR])
					dp[nL][nR]=dp[nL][nR-1];
				else{
					dp[nL][nR]=INF;
					for(int nM=nL; nM<nR; nM++)
						dp[nL][nR]=min(dp[nL][nR],dp[nL][nM]+dp[nM+1][nR]);
				}
		printf("%d\n",dp[0][N-1]);
		
	}
}