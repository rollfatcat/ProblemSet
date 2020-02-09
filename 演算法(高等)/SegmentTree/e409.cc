/* 線段樹練習題, 支援區間極值(差)和單點更新
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1000000+5;
const int MaxQ=100000+5;
 
int Max_seg[MaxN<<2]={};
int Min_seg[MaxN<<2]={};
int A[MaxN];
int X[MaxQ];
int Y[MaxQ];
bool C[MaxQ];
 
int k, m, N, Q;
int qL, qR, qV;
inline void gen_dat(){
  for(int i=k+1; i<=max(Q,N); i++)
    A[i]=( A[i-2]*97+A[i-1]*3 )%m+1;
  for(int i=1,j=max(Q,N); i<=Q; i++,j--){
    C[i]=A[i]&1;
    X[i]=(A[i]+A[j])%N+1;
    Y[i]=(C[i])? X[i]+( (A[i]<<3)+(A[j]<<5)+m )%( N-X[i]+1 ):
    						     +( (A[i]<<3)+(A[j]<<5) )%m+1;
  }
}
inline void BuildTree(int nL,int nR,int idx){
	if(nL==nR){ Max_seg[idx]=Min_seg[idx]=A[nL]; return; }
	int nM=nL+nR>>1, Lson=idx<<1, Rson=Lson|1;
	BuildTree(  nL,nM,Lson);
	BuildTree(nM+1,nR,Rson);
	Max_seg[idx]=max(Max_seg[Lson],Max_seg[Rson]);
	Min_seg[idx]=min(Min_seg[Lson],Min_seg[Rson]);
}
inline void UpdateNode(int nL,int nR,int idx){
	if(nL==nR){ Max_seg[idx]=Min_seg[idx]=qR; return; }
	int nM=nL+nR>>1, Lson=idx<<1, Rson=Lson|1;
	(qL<=nM)? UpdateNode(nL,nM,Lson): UpdateNode(nM+1,nR,Rson);
	Max_seg[idx]=max(Max_seg[Lson],Max_seg[Rson]);
	Min_seg[idx]=min(Min_seg[Lson],Min_seg[Rson]);
}
inline pair<int,int> Query(int nL,int nR,int idx){
	if(qL<=nL and nR<=qR) 
		return make_pair(Max_seg[idx],Min_seg[idx]);
	int nM=nL+nR>>1, Lson=idx<<1, Rson=Lson|1;
	if(qR<=nM) return Query(  nL,nM,Lson);
	if(qL> nM) return Query(nM+1,nR,Rson);
	
	pair<int,int> Lout=Query(  nL,nM,Lson);
	pair<int,int> Rout=Query(nM+1,nR,Rson);
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
		if( C[Qid] ){ // 區間極值差
			qL=X[Qid], 
			qR=Y[Qid];
			pair<int,int> out=Query(1,N,1);
			printf("%d\n",out.first-out.second);
		}else // 單點更新
			qL=X[Qid], 
			qR=Y[Qid],
			UpdateNode(1,N,1);
	}
}