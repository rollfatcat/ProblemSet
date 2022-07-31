/* 題目給定Ａ陣列的前ｋ個數字和，透過 gen_dat() 產生完整測資的Ｎ個數字和Ｑ個操作
 * 操作分為(1)０ｘｙ代表把ｘ這格位置的數字改為ｙ (2)１ｘｙ代表Ａ陣列中位置ｘ到位置ｙ的總和
 * 題目要求：單點更新和區間總和查詢
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6+5;
const int MaxQ=1e5+5;
int BIT[MaxN]={};
int A[MaxN];
bool C[MaxQ];
int X[MaxQ];
int Y[MaxQ];
int k, m, N, Q;

void gen_dat(){
	for(int i=k+1; i<=max(Q,N); i++ )
		A[i]=( A[i-2]*97 + A[i-1]*3 )%m+1;
	for(int i=1,j=max(Q,N); i<=Q; i++,j--){
		C[i]= A[i]&1;
		X[i]=(A[i]+A[j])%N+1;
		Y[i]=(C[i])? X[i]+( (A[i]<<3)+(A[j]<<5)+m )%( N-X[i]+1 ): ((A[i]<<3)+(A[j]<<5))%m+1;
	}
}
// 二進位的ｘ最後一個是１的位元
int lowbit(int x){ return x&-x; }
int Query(int p,int ret=0){
	for(; 0<p; p-=lowbit(p))
		ret+= BIT[p];
	return ret;
}
void Update(int p,int v){
	for(A[p]+=v; p<=N; p+=lowbit(p))
		BIT[p]+=v;
}
int main(){
	cin>>k>>m;
	for(int i=1; i<=k; i++)
		cin>>A[i];
	cin>>N>>Q;
	gen_dat();
	// Build Tree
	for(int n=1; n<=N; n++){
		Update(n,A[n]);
		A[n]>>=1;
	}
	// 根據要求操作
	for(int q=1; q<=Q; q++){
		if( C[q]==0 ){
			Update(X[q],Y[q]-A[X[q]]);
		}else{
			if(X[q]>Y[q]) swap(X[q],Y[q]);
			cout<< ( Query(Y[q])-Query(X[q]-1) )%m <<'\n';
		}
	}
}