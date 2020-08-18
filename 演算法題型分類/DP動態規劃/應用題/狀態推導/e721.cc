/* 給定Ｎ個價值不超過 500 的寶物，在遵守規則的前提下輸出能獲得的最大總價值？
 * 規則：選定價值Ｖ的寶物後就不能挑選價值Ｖ-1和Ｖ+1的寶物＝價值相鄰的寶物不能都選
 * 解題關鍵：CountingSort＋動態規劃，枚舉每種價值的寶物選或不選並記錄兩種狀態
 * 所有狀態：價值１-５００ × 選/不選(或是滾動陣列：選或不選)
 * 狀態轉移：
 *      不選代表從價值Ｖ-1的兩個狀態中選擇較高者，                dp[v][0]=max(dp[v-1][0],dp[v-1][1])
 *      必選代表從價值Ｖ-1的只能是不選並加上 cnt[Ｖ]個價值Ｖ的寶物，dp[v][1]=dp[v-1]+v*cnt[v]
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxV=5e2;
const int MaxN=1e4;
int cnt[MaxV+1]={};
int dpv[MaxV+1][2]={};
int main(){
	int N, v;
	scanf("%d\n",&N);
	while(N-->0)
		scanf("%d",&v),
		cnt[v]++;
	dpv[1][1]=cnt[1];
	for(int i=2;i<=MaxV;i++)
		dpv[i][0]=max(dpv[i-1][0],dpv[i-1][1]),
		dpv[i][1]=dpv[i-1][0]+i*cnt[i];
	printf("%d\n",max(dpv[MaxV][0],dpv[MaxV][1]));
}