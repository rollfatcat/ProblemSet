/* 給定一個數列, 極大化不重疊區間的數量
 * 區間的定義：兩端點的數字相同即可, 且重疊的定義中不包含相同端點
 * 動態規劃(最大區間和＋映射表)
 * 最大區間和：到目前位置可包含的最多#區間
 * 映射表：這個數字的前一次出現的位置
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=100;
const int MaxN=1e5+1;
int org[MaxN]; // 1 ≤ Ｎi ≤ 100000
int pre[MaxN];
int dpn[MaxN];

int main(){
	int caseT, N;
	for(scanf("%d\n",&caseT);caseT>0;caseT--){
		scanf("%d\n",&N);
		for(int i=0;i<N;i++){
			scanf("%d",&org[i]);
			pre[org[i]]=-1;
			dpn[i]=0;
		}
		pre[org[0]]=0;
		for(int i=1;i<N;i++){
			if(pre[org[i]]>=0)
				dpn[i]=dpn[pre[org[i]]]+1;
			dpn[i]=max(dpn[i-1],dpn[i]); 
			pre[org[i]]=i; // 更新該數字的前一個位置
		}
		printf("%d\n",dpn[N-1]);
	}
}