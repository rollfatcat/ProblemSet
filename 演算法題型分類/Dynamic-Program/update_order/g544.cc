/* 提供 N 種配料，員工必須由左至右移動(不可返回)經過配料時可以選擇不拿或拿取一份配料。
 * 選擇的過程中不能連續選取"相同屬性"的配料，目標是最大化所有配料加總的分數
 * 解題關鍵：DP + set/ segment_tree
 * 狀態定義：最後選取的屬性分數時累加最多的分數
 * 狀態轉移：dp[ attr(i) ]=max( dp[j] )+num[i], j≠attr(i)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxS=1e3;
const int MaxK=1e3;
int num[MaxN];
int main(){
	int N, K;
	
	scanf("%d %d",&N,&K);
	for(int i=0; i<N; i+=1)
		scanf("%d",&num[i]);
	
	int ans=0;
	int nowK, preK=0;
	int max_v=0;
	for(int i=0;i<N;i+=1){
		scanf("%d",&nowK);
		if(preK!=nowK){
			ans+=max_v;
			preK=nowK;
			max_v=num[i];
		}else
			max_v=max(max_v,num[i]);
	}
	printf("%d\n",ans+max_v);
}