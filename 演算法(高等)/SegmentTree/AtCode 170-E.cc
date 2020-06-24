/* 題目連結：https://atcoder.jp/contests/abc170/tasks/abc170_e
 * 給定Ｎ個嬰兒和Ｑ次的轉換，Ｎ個嬰兒的重要度和初始化時屬於哪一個幼稚園
 * 每轉換時會給定Ｃ Ｄ代表第Ｃ位嬰兒交由第Ｄ個幼稚園後輸出目前的"平衡度"？
 * 平衡度＝在所有招收到嬰兒的幼稚園中最小的重要度，該幼稚園內的代表＝重要度最大的嬰兒。
 * PriorityQueue＋SegmentTree＋LazyUpdate概念
 * PriorityQueue：維護每個幼稚園內重要度最大的"嬰兒編號"，
 * SegmentTree  ：查詢所有幼稚園中最小重要度的"嬰兒編號"
 * LazyUpdate   ：轉換時"理論上"需要將嬰兒的號碼加入到新的幼稚園並移除舊有的幼稚園，
 *                前者可以利用 PQ.push()完成但在後者無法隨意從已經建立的PQ順序內移除某個數字。
 *                既然無法"立刻"移除就只要保證"不影響該幼稚園最大重要度"的前提下忽略 並 搭配陣列紀錄該嬰兒號碼"已經屬於其他幼稚園"，
 *                更新該幼稚園的最大重要度時確保 PQ.top() 的嬰兒確實屬於該幼稚園即可。
 * 轉換時該嬰兒的"舊幼稚園"和"新幼稚園"的最大重要度可能會受影響，所以兩者都需要做更新。
 * 細節：實作時紀錄的是"嬰兒編號"，但ＰＱ的順序是由重要度決定。
 * 
 */
#include<bits/stdc++.h>
using namespace std;

const int INF=1<<30;
const int MaxN=2e5;
const int MaxQ=2e5;

int rate[MaxN+1];
int whos[MaxN+1];
struct COMP{ bool operator()(const int& a, const int& b){ return rate[a]<rate[b]; }};
priority_queue<int,vector<int>,COMP> PQ[MaxN+1];

int minv[3*MaxN];
int ToLeaf[3*MaxN];
inline void NewSegTree(int nL,int nR,int idx){
	if(nL==nR){ 
		ToLeaf[nL]=idx; 
		minv[idx]=(PQ[nL].empty())? 0:PQ[nL].top(); 
		return; 
	}
	int nM=nL+nR>>1;
	NewSegTree(  nL,nM,  idx<<1);
	NewSegTree(nM+1,nR,idx<<1|1);
	minv[idx]=(rate[minv[idx<<1]]<rate[minv[idx<<1|1]])? minv[idx<<1]: minv[idx<<1|1];
}

int main(){
	int N, Q;
	int baby, new_whos, old_whos;
	scanf("%d %d\n",&N,&Q);
	
	for(int i=1;i<=N;i++)
		scanf("%d %d\n",&rate[i],&whos[i]),
		PQ[whos[i]].push(i);
		
	whos[0]=0, rate[0]=INF;	
	NewSegTree(1,MaxN,1);
	
	while(Q--){
		scanf("%d %d\n",&baby,&new_whos);
		
		old_whos=whos[baby];
		whos[baby]=new_whos;
		
		while(PQ[old_whos].empty()==0 and whos[ PQ[old_whos].top() ]!=old_whos) PQ[old_whos].pop();
		minv[ ToLeaf[old_whos] ]=(PQ[old_whos].empty())? 0: PQ[old_whos].top();
		for(int now=ToLeaf[old_whos], nxt=now>>1; nxt>0; now=nxt,nxt>>=1)
			minv[nxt]=(rate[minv[nxt<<1]]<rate[minv[nxt<<1|1]])? minv[nxt<<1]: minv[nxt<<1|1];
		
		PQ[new_whos].push(baby);
		minv[ ToLeaf[new_whos] ]=PQ[new_whos].top();
		for(int now=ToLeaf[new_whos], nxt=now>>1; nxt>0; now=nxt,nxt>>=1)
			minv[nxt]=(rate[minv[nxt<<1]]<rate[minv[nxt<<1|1]])? minv[nxt<<1]: minv[nxt<<1|1];
		printf("%d\n",rate[minv[1]]);
	}
}