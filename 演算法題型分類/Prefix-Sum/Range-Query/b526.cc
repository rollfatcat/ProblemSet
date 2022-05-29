/* 給定Ｎ個人和Ｍ次的口令，一開始Ｎ個人是站著的而每次口令時區間內的人會改變狀態(蹲站互換)，輸出最後站著的人數？
 * 解題關鍵：類似前綴和的消除概念＋排序
 * 套用線段樹的 Lazy-Evaluation 做模擬(X)，但觀察"改變行為"後可以發現只需要排序即可。
 * 狀態只有２種，換句話說同一個人最終是否改變狀態只要確定能夠影響到他的命令數有幾個。
 * ToDo(qL,qR)＝(1,qL-1)+(1,qR)，可以視為(1,qL-1)改變一次且(1,qR)再改變一次，因為(1,qL-1)的狀態被消除
 */

#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e9;
const int MaxM=1e5;
int num[MaxM<<1];
 
int main(){
	int N, M;
	scanf("%d %d\n",&N,&M);
	for(int i=0;i<M;i++)
		scanf("%d %d\n",&num[i<<1],&num[i<<1|1]),
		num[i<<1]-=1;
	sort(num,num+(M<<1));
 
	int ans=N;
	for(int i=0;i<(M<<1);i++)
		ans+= (i&1)? -num[i]+1: num[i];
	printf("%d\n",ans);
}