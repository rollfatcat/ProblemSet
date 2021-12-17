/* 給定Ｎ個數字(編號１:Ｎ)和Ｑ次的查詢，輸出範圍內數字的種類？
 * 解題關鍵：Offline-Process + BIT(Fenwick Tree) + Greedy
 * Greedy - BIT 紀錄的是每個位置的個數是０還是１，若存在多個相同數值時讓最靠近目前查詢的那個位置為１其餘為０
 * 離線處理：根據右邊界由小到大排序(非莫隊算法，不需要考慮左邊界)
 * 			若要包含這個數字，必須把這個數字中最右邊的位置也涵蓋進去 ... 所以只需要讓該數值最右側位置的個數為１
 * BIT : 目前查詢範圍內有多少個１
 * (1) Sort queries based on r values.
 * (2) Make a Segment Tree for range sum queries [0, n]
 * (3) For each value in input array from left to right:
 * 	   Increment by 1 at current index i in the segment tree.
 *     For current element, if it's been seen before, decrement by 1 in segment tree at it's previous position.
 *     Answer queries ending at current index i, by querying for sum in range [l, r == i].
 *     The idea in short is to keep marking rightward indexes, the latest occurrence of each individual element, 
 *     and setting previous occurrences back to 0. The sum of range would give the count of unique elements.
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=4e5;
const int MaxQ=4e5;
int N, Q;
int BIT[MaxN+1];
int pre[MaxN+1];
int num[MaxN+1];

int qry[MaxQ][2];
int ord[MaxQ];
int ans[MaxQ];
inline int LastBit(int x){ return x&-x; }
void BIT_Upd(int p,int v){
	for( ; p<=N; p+=LastBit(p))
		BIT[p]+=v;
}
int BIT_Qry(int p,int ret=0){
	for( ; p>0; p-=LastBit(p))
		ret+=BIT[p];
	return ret;
}
int main(){
	
	int *last=&BIT[0];
	
	scanf("%d",&N);
	fill(last,last+N+1,0);
	for(int n=1; n<=N; n+=1){
		scanf("%d",&num[n]);
		pre[n]=last[num[n]]; // 紀錄這個數值上一次出現在左邊的哪格位置
		last[num[n]]=n; // 更新該數字出現的位置
	}
	scanf("%d",&Q);
	for(int q=0; q<Q; q+=1)
		scanf("%d %d",&qry[q][0],&qry[q][1]);
	// Offline-Process : 依據右邊界做排序
	iota(ord,ord+Q,0);
	sort(ord,ord+Q,[](const int lhs,const int rhs){
		return qry[lhs][1]<qry[rhs][1]; });
	// sweepline
	fill(BIT,BIT+N+1,0);
	int nR=1;
	for(int q=0; q<Q; q+=1){
		// 讓相同數值的個數盡量向右
		for(; nR<=qry[ord[q]][1]; nR+=1){
			if(pre[nR]>0)
				BIT_Upd(pre[nR],-1);
			BIT_Upd(nR,1);
		}
		ans[ ord[q] ]=BIT_Qry(qry[ord[q]][1])-BIT_Qry(qry[ord[q]][0]-1);
	}
	for(int q=0; q<Q; q+=1)
		printf("%d\n",ans[q]);
}