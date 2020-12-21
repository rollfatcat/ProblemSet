/* 動態規劃的入門題(將計算過的狀態用陣列紀錄起來)
 * 給定Ｎ和遞迴規則後，問值？
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e6;
int F[MaxN+1]={};
inline int DP(int x){
	if(F[x]==0)
		F[x]=(x&1)? DP(x+1)+DP(x-1) : DP(x>>1);
	return F[x];
}
int main(){
	for(int t=1;t<=MaxN;t<<=1)
		F[t]=1;
	int N;
	scanf("%d\n",&N);
	printf("%d\n",DP(N));
}