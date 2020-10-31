/* 給定Ｎ個人的位置和孤單評測值，若任意２個人的距離大於Ｋ則這２個人會產生孤獨感(評測值的乘積)，輸出孤獨感的總和？
 * 解題關鍵：ScanLine(Sorted)+TwoPointers＋PreFixSum
 * ScanLine : 枚舉任意２個人的組合估算相間距離是否大於Ｋ＝從左到右掃描一遍，只須考慮自己左邊的其他點就好。
 * 			  題目給定的位置保證由小到大
 */

#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=5;
const int MaxN=2e6;
const int MaxK=1e9;

int pos[MaxN+1];
int prS[MaxN+1]; // −1000 ≤ wi ≤ 1000 ... -2e9 ≤ prS[i] ≤ 2e9
int main(){
  prS[0]=0;
	
	int caseT, N, K;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d\n",&N,&K);
		for(int i=1;i<=N;i++) 
			scanf("%d",&pos[i]);
		for(int i=1;i<=N;i++) 
			scanf("%d",&prS[i]), 
			prS[i]+=prS[i-1];
		
		int pvt=1, now=2;
		long ans=0;
		for(; pos[now]-pos[pvt]<=K; now++);
		for(; now<=N; now++){
			for(; pos[now]-pos[pvt]>K; pvt++);
			ans+=(long)(prS[now]-prS[now-1])*prS[pvt-1];
		}
		printf("%ld\n",ans);
	}
}