/* 線段樹練習題, 需支援區間和/區間極值/區間更新
 * 因為必須支援區間更新, 必定要使用『懶惰標記』實現
 * 新增函數：PushDown() / PushUp()
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1000000+5;
const int MaxQ=100000+5;
int A[MaxN];
int X[MaxQ];
int Y[MaxQ];
int Z[MaxQ];
bool C[MaxQ];
int k, m, N, Q;
// Lazy-Update SegmentTree
const int MaxSz=3*MaxN; // 最保險是4倍的空間
int qL, qR, qV, Sumv;
int Max_seg[MaxSz]={};
int Min_seg[MaxSz]={};
int Sum_seg[MaxSz]={};
bool LazyTag[MaxSz]={};
 
inline void gen_dat(){
  for(int i=k+1; i<=max(Q,N); i++)
    A[i]=( A[i-2]*97 + A[i-1]*3 )%m+1;
  for(int i=1,j=max(Q,N); i<=Q; i++,j--){
    C[i]=A[i]&1;
    X[i]=( A[i]+A[j] )%N+1;
    Y[i]=X[i]+ ( (A[i]<<3)+(A[j]<<5)+m )%( N-X[i]+1 );
    if(C[i]==0) Z[i]=( (A[i]<<3)+(A[j]<<5) )%m+1;
  }
}
 
inline void PushDown(int nL,int nR,int now,int nM){
	Max_seg[now<<1]=Max_seg[now<<1|1]=Max_seg[now];
	Min_seg[now<<1]=Min_seg[now<<1|1]=Min_seg[now];
	Sum_seg[now<<1]=Max_seg[now]*(nM-nL+1);
	Sum_seg[now<<1|1]=Max_seg[now]*(nR-nM);
	LazyTag[now<<1]=LazyTag[now<<1|1]=1;
	LazyTag[now]=0;
}
inline void PushUp(int now){
	Max_seg[now]=max(Max_seg[now<<1],Max_seg[now<<1|1]);
	Min_seg[now]=min(Min_seg[now<<1],Min_seg[now<<1|1]);
	Sum_seg[now]=Sum_seg[now<<1]+Sum_seg[now<<1|1];
}
inline void BuildTree(int nL,int nR,int now){
	if(nL==nR){
		Max_seg[now]=Min_seg[now]=Sum_seg[now]=A[nL]; return;
	}
	int nM=nL+nR>>1;
	BuildTree(  nL,nM,  now<<1);
	BuildTree(nM+1,nR,now<<1|1);
	PushUp(now);
}
inline void Update(int nL,int nR,int now){
	int nM=nL+nR>>1;
	if(nR>nL and LazyTag[now])
		PushDown(nL,nR,now,nM);
	if(qL<=nL and nR<=qR){ 
		LazyTag[now]=1;
		Max_seg[now]=Min_seg[now]=qV;
		Sum_seg[now]=qV*(nR-nL+1);
		return; 
	}
	if(qL<=nM) Update(  nL,nM,  now<<1);
	if(qR> nM) Update(nM+1,nR,now<<1|1);
	PushUp(now);
}
inline pair<int,int> Query(int nL,int nR,int now){
	int nM=nL+nR>>1;
	if(nR>nL and LazyTag[now])
		PushDown(nL,nR,now,nM);
	if(qL<=nL and nR<=qR){ 
		Sumv+=Sum_seg[now];
		return make_pair(Max_seg[now],Min_seg[now]); 
	}
	if(qR<=nM) return Query(  nL,nM,  now<<1);
	if(qL> nM) return Query(nM+1,nR,now<<1|1);
	pair<int,int> Lout=Query(  nL,nM,  now<<1);
	pair<int,int> Rout=Query(nM+1,nR,now<<1|1);
	return make_pair(max(Lout.first ,Rout.first ),
									 min(Lout.second,Rout.second));
}
 
int main(){
	scanf("%d %d",&k,&m);
	for(int i=1;i<=k;i++)
		scanf("%d",&A[i]);
	scanf("%d %d",&N,&Q);
 
	gen_dat();
	BuildTree(1,N,1);
	for(int Qid=1;Qid<=Q;Qid++){
		if( C[Qid] ){
			qL=X[Qid],
			qR=Y[Qid],
			Sumv=0;
			pair<int,int> out=Query(1,N,1);
			printf("%d %d\n",Sumv%m,out.first-out.second);
		} else
			qL=X[Qid],
			qR=Y[Qid],
			qV=Z[Qid],
			Update(1,N,1);
	}
}