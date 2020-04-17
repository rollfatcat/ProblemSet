/* 給定正確答案後，要求算出最多match的位置
 * 注意題目給數字時代表的意義：
 * 3 1 2 4 9 5 10 6 8 7
 * 3＝第一個數字放在數列３的位置，而非正確答案數列第一個數字是３
 * 所以範例測資的正確實際是＝ 2 3 1 4 6 8 10 9 5 7 
 * 解法：
 * 給定的『正確答案』＝該數字位於數列的位置＝權重(越低越前面)
 * 先將 輸入的數字 轉換為 真正的數列 後依序對照 正確答案數列的位置 做 LIS。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=20+2;
int ord[MaxN];
int num[MaxN];
int cnt[MaxN];

int main(){
	int N, x, maxCnt;
	
	scanf("%d\n",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&ord[i]);
	
	while(scanf("%d",&x)!=EOF){
		num[x]=0;
		for(int i=1;i<N;i++)
			scanf("%d",&x), num[x]=i;
		
		fill(cnt+1,cnt+N+1,0);
		maxCnt=0;
		for(int i=1;i<=N;i++){
			x=ord[ num[i] ];
			for(int j=x-1;j>=0;j--)
				cnt[x]=max(cnt[x],cnt[j]+1);
			maxCnt=max(maxCnt,cnt[x]);
		}
		printf("%d\n",maxCnt);
	}
}
