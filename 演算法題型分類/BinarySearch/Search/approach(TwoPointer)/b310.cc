/* 給定Ｎ個數字和 threshold Ｍ，輸出最少需要多少個"連續"數字的和可以大於等於Ｍ？若不存在則輸出指定字串
 * 解題關鍵：TwoPointer
 * 固定尾端時在維持數字和大於等於Ｍ的前提下盡量縮小區間長度。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int INF=1<<30;
int num[MaxN];
int main(){
	int N, M;
	scanf("%d %d\n",&N,&M);
	
	int ansL=INF, sumv=0; 
	for(int front=0, back=0; back<N; back++){
		scanf("%d",&num[back]);
		sumv+=num[back];
		while(sumv>=M){
			ansL=min(ansL,back-front+1);
			sumv-=num[front++];
		}
	}
	(ansL==INF)? puts("GGGGGZ"): printf("%d\n",ansL);
}