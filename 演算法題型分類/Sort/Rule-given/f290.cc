/* 給定Ｎ位士兵的防禦力，依據攻擊力小到大排序(相同時依據防禦力小到大)？
 * 解題關鍵：Sort＋BucketSort
 * 額外資訊：防禦力 ≦ 10000＝攻擊力 ≦ 20000
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e6;
const int MaxP=1e4;
int num[MaxN];
vector<int> bucket[20001];
 
int main(){
	int N;
	/* 測資輸入 */
    scanf("%d\n",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&num[i]);
    /* 枚舉計算第ｉ位士兵的攻擊力(取ｉ-1 和ｉ+1位士兵的防禦力)，
     * 記錄到屬於該攻擊力的 bucket，bucket內儲存的是該士兵的防禦力。
     */
	bucket[num[0]].push_back(num[0]);
	bucket[num[N-1]].push_back(num[N-1]);
	for(int i=1;i<N-1;i++)
		bucket[num[i-1]+num[i+1]].push_back(num[i]);
	/* 枚舉攻擊力小到大的 bucket，根據 bucket 內儲存的防禦力排序後輸出 */
	for(int i=0;i<=20000;i++)
		if(bucket[i].size()){
			sort(bucket[i].begin(),bucket[i].end());
			for(int x:bucket[i])
				printf("%d %d\n",i,x);
		}
}