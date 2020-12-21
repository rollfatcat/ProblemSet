/* 給定Ｎ個正確答案後，每給予一筆測資算出最多配對的順序(最長子序列)
 * 注意順序性的意義：
 * 3 1 2 4 9 5 10 6 8 7
 * 3＝第一個數字放在數列３的位置，而非正確答案數列第一個數字是３
 * 所以範例測資的正確實際是＝ 2 3 1 4 6 8 10 9 5 7 
 * 解題關鍵：
 * 給定的『正確答案』＝該數字位於數列的位置＝權重(越低越前面)
 * 將 輸入的順序性 轉換為 真正的測資 ，再依序對照 該數字在正確答案數列中的位置 做 LIS。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=20;
int ord[MaxN+1];
int rhs[MaxN+1];
int LIS[MaxN+1];

int main() {
	int N, v, maxL, tag, ans;
	scanf("%d\n",&N);
	/* 第ｉ個答案的順序性(權重) */
	for(int i=1;i<=N;i++)
		scanf("%d",&ord[i]);
	while(scanf("%d",&v)!=EOF){
		/* 根據順序性填入第ｉ個測資 */
		rhs[v]=1;
		for(int i=2;i<=N;i++)
			scanf("%d",&v), rhs[v]=i;
		/* 枚舉第１個測資到第Ｎ個測資。
		 * 將第ｉ個測資轉換為"正確答案中的位置"
		 * 檢查該位置前形成的 LIS 中最長長度+1 就是從頭到目前這個位置的 LIS
		 * 注意：實現Ｎ㏒Ｎ可以透過 RMQ 加速但不能透過 Robinson-Schensted-Knuth Algorithm
		 *      RMQ 可以查詢１到目前位置的區間內 LIS 的最大值
		 *      Robinson-Schensted-Knuth Algorithm 則是依照位置順序給新數字時去更新數列中的數字
		 */
		fill(LIS+1,LIS+N+1,0);
		ans=0;
		for(int i=1;i<=N;i++){
			tag=ord[rhs[i]];
			maxL=0;
			for(int j=1;j<tag;j++)
				maxL=max(maxL,LIS[j]);
			LIS[tag]=maxL+1;
			ans=max(ans,LIS[tag]);
		}
		printf("%d\n",ans);
	}
}