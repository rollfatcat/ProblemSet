// 給定一個數列, 輸出查詢的數字是否在數列中, 若存在則輸出第一個出現的位置(從1開始算)
#include<bits/stdc++.h>
using namespace std;

const int MaxQ=1e4;
const int MaxN=1e4; 
int org[MaxN];   // 題目保證輸入數字皆 ≦ 1e4

int main(){
	int N, Q;
	for(int caseN=1;scanf("%d %d",&N,&Q) and N;caseN++){
		for(int i=0;i<N;i++)
			scanf("%d",&org[i]);
		sort(org,org+N);
		printf("CASE# %d:\n",caseN);
		for(int target, tag;Q--;)
			scanf("%d",&target),
			tag=lower_bound(org,org+N,target)-org,
			(target==org[tag])?
			printf("%d found at %d\n",target,tag+1):
			printf("%d not found\n",target);
	}
}