/* 動態規劃＋線段樹(單點修改＋區間查詢)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6+1;
const int MaxV=1e9; // -1e9 ≦ v ≦ 1e9


int pos[MaxN]; // 單節點位置對應
long p_seg[3*MaxN];
long n_seg[3*MaxN];
inline long max(long a,long b){ return (a>b)? a:b; }
inline void SetTree(int nL,int nR,int idx){
	p_seg[idx]=n_seg[idx]=-MaxV;
	if(nL==nR){ pos[nL]=idx; return; }
	int nM=nL+nR>>1;
	SetTree(  nL, nM, idx<<1  );
	SetTree(nM+1, nR, idx<<1|1);
}
inline pair<long,long> AskTree(int qL,int qR,int nL,int nR,int idx){
	pair<long,long> out(-MaxV,-MaxV);
	if(qL<=nL and nR<=qR)
		out.first =max(out.first ,p_seg[idx]), 
		out.second=max(out.second,n_seg[idx]);
	else{
		pair<long,long> tmp;
		int nM=nL+nR>>1;
		if(nM>=qL) tmp=AskTree(qL,qR,  nL,nM,idx<<1  ),
							 out.first =max(out.first ,tmp.first ), 
							 out.second=max(out.second,tmp.second);
		if(nM< qR) tmp=AskTree(qL,qR,nM+1,nR,idx<<1|1),
							 out.first =max(out.first ,tmp.first ), 
							 out.second=max(out.second,tmp.second);
	}
	return out;
}
inline void SetLeaf(long v,int now,long* tree){
	for(now=pos[now]; now>=1 and tree[now]<v; now>>=1)
		tree[now]=v;
}
int main(){
	pair<long,long> out;
	int N, D, v, qL, qR;
	
	scanf("%d %d\n",&N,&D);
	SetTree(0,N-1,1);
	
	scanf("%d",&v);
	SetLeaf(v,0,p_seg);
	for(int i=1;i<D;i++){
		scanf("%d",&v);
		out=AskTree(0,i-1,0,N-1,1);
		SetLeaf(out.second+v,i,p_seg);
		SetLeaf(out.first -v,i,n_seg);
	}
	for(int i=D;i<N;i++){
		scanf("%d",&v);
		out=AskTree(i-D,i-1,0,N-1,1);
		SetLeaf(out.second+v,i,p_seg);
		SetLeaf(out.first -v,i,n_seg);
	}
	printf("%ld\n",max(p_seg[1],n_seg[1]));
}
