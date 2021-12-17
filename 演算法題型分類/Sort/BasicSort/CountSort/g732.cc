/* 給定Ｎ(Ｎ保證是奇數)個數字(數值不超過500)，輸出中位數是多少？
 * 解題關鍵：counting sort
 */
#include<iostream>
using namespace std;

const int MaxN=5e6;
const int MaxS=5e2;
int cnt[MaxS+1]={};
int main(){
	int N, v, n;
	
	scanf("%d",&N);
	for(n=0; n<N; n+=1){
		scanf("%d",&v);
		cnt[v]+=1;
	}
	N=(N>>1)+1;
	for(n=0; n<=MaxS and cnt[n]<N; n+=1)
		N-=cnt[n];
	printf("%d",n);
}