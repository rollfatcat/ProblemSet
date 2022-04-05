/* 給定Ｎ本書及Ｋ個員工(１≦ Ｋ ≦ Ｎ ≦ 500)，在限制下，輸出每位店員分到的頁數(用'/'隔開)？
 * 限制：(1)同本書的頁數只能分配給同位店員 (2)在不超過最大限制的前提下越後面店員分配到的頁數越多
 * 解題關鍵：二分法
 * 我們用二分搜尋找出每個人的工作量(頁數)的上限，(題目要求工作量越少越好，但如果太少就需要>Ｋ個員工)。
 * 此外如果有多組解的情況，idx 越大的員工所分配的書要盡量的多，因此分配書的時候 idx 從後面開始，
 * 但注意分配時每個人至少要有一本書，因此如果(剩下的書 ≦ 剩下的人)，就算那個人還沒分完，也要直接換下一個人。
 * 注意問題：右邊界(上限)的型態是long，因為全部頁數加總是 5e9 且輸出格式很難(建議直接給學生Codes)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=500;
const int MaxA=1e7;
int N, K;
int num[MaxN];

inline bool challenge(long testR){
	int cnt=K-1;
	long rem=testR;
	for(int i=0;i<N;i++){
		if(rem<num[i]){
			if(cnt==0)
				return false;
			cnt--;
			rem=testR;
		}
		rem-=num[i];
	}
	return true;
}
int main(){
	int caseT;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d\n",&N,&K);
		for(int i=0;i<N;i++)
			scanf("%d",&num[i]);
		/* 左邊界(下限)：店員至少能處理所有頁數當中頁數最多的那本書
     * 右邊界(上限)：將所有書頁分配給同一位店員
     * 每本書最多是 1e7 ，書最多 500 本，頁數總和＝5e9
     */
		long nL=0;
		long nR=0;
		for(int i=0;i<N;i++){
			nL=(nL>num[i])? nL: num[i];
			nR+=num[i];
		}
		/* 二分法 */
		long ans_rem;
		while(nL<=nR){
			long nM=nL+nR>>1;
			if( challenge(nM) )
				nR=nM-1, ans_rem=nM;
			else
				nL=nM+1;
		}
		/* 根據題目要求分配書本：至少每人一本書且越後面的店員分配到的頁數越多(不超過限制的前提) */
		vector<vector<int>> output;
		int idx; long rem=0;
    for(idx=N-1;idx>=0 and idx>=K;idx--)
			if(rem<num[idx]){
				K--;
				output.push_back(vector<int>(1,num[idx]));
				rem=ans_rem-num[idx];
			}else{
				rem-=num[idx];
				output.back().push_back(num[idx]);
			}
    /* 保證每位店員都能分配到一本書 */
		while(idx>=0)
			output.push_back(vector<int>(1,num[idx--]));
		
    printf("%d",output.back().back());
		for(int j=output.back().size()-2;j>=0;j--)
			printf(" %d",output.back()[j]);
		for(int i=output.size()-2;i>=0;i--){
			printf(" /");
			for(int j=output[i].size()-1;j>=0;j--)
				printf(" %d",output[i][j]);
		}
		putchar('\n');
	}
}