#include<bits/stdc++.h>
using namespace std;

const int MaxN=200000;
const int MaxQ=200000;
long PreSum[MaxN+1]; // 序列中的數字，其中數字的絕對值不會超過1e9

int main(){
	int N, Q;
	scanf("%d",&N);
	PreSum[0]=0;
	for(int i=1;i<=N;i++)
		scanf("%ld",&PreSum[i]),
		PreSum[i]+=PreSum[i-1];
	scanf("%d",&Q);
	for(int L, R;Q>0;Q--)
		scanf("%d %d",&L,&R),
		printf("%ld\n",PreSum[R]-PreSum[L-1]);
	
}