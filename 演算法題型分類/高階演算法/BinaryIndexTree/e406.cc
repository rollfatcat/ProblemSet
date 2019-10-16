#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1000000+5;
const int MaxQ=100000+5;
 
int BIT[MaxN]={};
int A[MaxN];
int X[MaxQ];
int Y[MaxQ];
bool C[MaxQ];
 
int k, m, N, Q;
inline int lowbit(int x){ return x&-x; }
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
inline int QuerySum(int pos,int out=0){
	for(int idx=pos;idx>0;idx-=lowbit(idx))
		out+=BIT[idx];
	return out;
}
int main(){
	scanf("%d %d",&k,&m);
	for(int i=1;i<=k;i++)
		scanf("%d",&A[i]);
	scanf("%d %d",&N,&Q);
	gen_dat();
	// BuildTree();
	for(int i=1;i<=N;i++)
		for(int x=i;x<=N;x+=lowbit(x))
			BIT[x]+=A[i];
	//
	for(int Qid=1;Qid<=Q;Qid++){
		if(C[Qid]){
			printf("%d\n",(QuerySum(Y[Qid])-QuerySum(X[Qid]-1))%m);
		}else{
			int diff=Y[Qid]-A[X[Qid]];
			for(int x=X[Qid];x<=N;x+=lowbit(x))
				BIT[x]+=diff;
			A[X[Qid]]+=diff;
		}
	}
}