// 將線段樹處理的RMQ問題(支援區間修改)轉成BIT處理方式
/* 模板詳解：https://www.cnblogs.com/dilthey/p/9366491.html#c
 * 引入「差分」的概念：
 * sum[x]=segma(org[i])+(x+1)*segma(delta[i])-segma(delta[i]*i)，1 ≤ i ≤ x
 * 維護三個前綴和：org[i]/ delta[i]/ delta[i]*i
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e5;
const int MaxQ=5e5;
const int MaxV=32767;
const int MaxK=1e3;

int N, Q, o, L, R, K;
long prS[MaxN+2]={};
long  di[MaxN+2]={};
long dii[MaxN+2]={};

int lowbit(int x){ return x&-x; }
void Update(long BIT[],int p,long v){
	for(; p<=N; p+=lowbit(p))
		BIT[p]+=v;
}
long Query(long BIT[],int p,long ret=0){
	for(; 0<p; p-=lowbit(p))
		ret+= BIT[p];
	return ret;
}

int main(){
	scanf("%d",&N);
	for(int n=1; n<=N; n++){
		scanf("%ld",&prS[n]);
		prS[n]+=prS[n-1];
	}
	scanf("%d",&Q);
	while(Q-->0){
		scanf("%d %d %d",&o,&L,&R);
		if( o==1 ){ // Update
			scanf("%d",&K);
			Update( di,  L, K);
			Update(dii,  L, K*L);
			Update( di,R+1,-K);
			Update(dii,R+1,-K*(R+1));
		}else{ // Query
			long ans=prS[R]-prS[L-1];
			//long ans=0;
			ans+=(R+1)*Query(di, R )-Query(dii, R );
			ans-=    L*Query(di,L-1)-Query(dii,L-1);
			printf("%ld\n",ans);
		}
	}
}