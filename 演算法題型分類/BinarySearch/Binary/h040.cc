/* 給定Ｎ次的鼓勵值，每次鼓勵可以恢復 ⌊𝑉𝑡−1×𝑚𝑖𝑛(𝑙𝑜𝑔2(𝐹𝑡 + 1),30)/30⌋，輸出最初的體力值設定 
 * 解題關鍵：二分法
 * 題目盲點：搜尋範圍最大是 INT_MAX，注意計算中間值時的加法會 overflow
 * 			題目涉及到浮點數運算(𝑙𝑜𝑔2)，需要最小化計算次數 ... 避免每次二分時都得重複計算
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=4e4;
const int MaxQ=1e2;
const int MaxF=2e9;
const int MaxK=2e9;
int N, Q, K;
double F[MaxN];
bool check(long v,int rem){
	for(int n=0; n<N; n+=1){
		v=v*F[n]/30;
		if(v==0) return false;
		if(rem<=v) return true;
		rem-=v;
	}
	return false;
}
int main(){
	
	scanf("%d",&N);
	for(int Fn,n=0; n<N; n+=1){
		scanf("%d",&Fn);
        // 取 log2 為底的次方項要保留小數點( 不可使用__lg(x) )
		F[n]=min(log2(Fn+1),30.00);
	}
	scanf("%d",&Q);
	while(Q-->0){
		scanf("%d",&K);
		long L=1;
		long R=K;
		long ans;
		while(L<=R){
			long M=L+R>>1;
			if( K<=M or check(M,K-M) ){
				ans=M;
				R=M-1;
			}else
				L=M+1;
		}
		printf("%ld\n",ans);
	}
}