#include<bits/stdc++.h>
using namespace std;

const long MaxN=1e18;
const int MOD=998244353; // prime number

long FastExp(long B,long P,long MOD){
	long ret=(P&1)? B: 1;
	for(P>>=1; P>0; P>>=1){
		B=B*B%MOD;
		if(P&1)
			ret=ret*B%MOD;
	}
	return ret;
}
int main(){
	long N, K, M;
	
	scanf("%ld %ld %ld",&N,&K,&M);
	// output : M^(K^N) 
	M=M% MOD; // if M is multiple of MOD 
	K=K%(MOD-1);
	if(M==0){ printf("0"); return 0; }
	if(K==0){ printf("1"); return 0; }
	printf("%ld",FastExp(M,FastExp(K,N,MOD-1),MOD));
}