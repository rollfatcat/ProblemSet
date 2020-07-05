/* 給定一個數列有Ｎ個數字和Ｑ次查詢
 * 每次查詢有兩個數字代表範圍，輸出範圍內的最大值和最小值差？
 * 觀察Ｑ=2e5 可以理解使用線段樹處理。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e4;
const int MaxQ=2e5;
const int INF=1<<30;

int N, Q, qL, qR;
int maxv[MaxN*3];
int minv[MaxN*3];

inline void NewSegTree(int nL,int nR,int idx){
	if(nL==nR){
		scanf("%d\n",&maxv[idx]); minv[idx]=maxv[idx]; return; }
	int nM=nL+nR>>1;
	NewSegTree(  nL,nM,  idx<<1);
	NewSegTree(nM+1,nR,idx<<1|1);
	maxv[idx]=max(maxv[idx<<1],maxv[idx<<1|1]);
	minv[idx]=min(minv[idx<<1],minv[idx<<1|1]);	
} 
inline pair<int,int>QueryTree(int nL,int nR,int idx){
	if(qL<=nL and nR<=qR) return make_pair(maxv[idx],minv[idx]);
	int nM=nL+nR>>1;
	pair<int,int> sub_out, out=make_pair(0,INF);
	if(qL<=nM) 
		sub_out=QueryTree(  nL,nM,  idx<<1),
		out.first =max(out.first, sub_out.first ),
		out.second=min(out.second,sub_out.second);
	if(nM<qR ) 
		sub_out=QueryTree(nM+1,nR,idx<<1|1),
		out.first =max(out.first, sub_out.first ),
		out.second=min(out.second,sub_out.second);
	return out;
}
int main(){
  scanf("%d %d\n",&N,&Q);
  NewSegTree(1,N,1);
  while(Q--){
  	scanf("%d %d\n",&qL,&qR);
  	pair<int,int> out=QueryTree(1,N,1);
  	printf("%d\n",out.first-out.second);
  }
}