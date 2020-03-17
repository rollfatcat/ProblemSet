/* 循環小數＝出現過已紀錄的餘數
 * 輸出循環的部分(若超過50位則只輸出前50位＋"...")
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxL=50; 
int memo[2][MaxL+2], L;
inline int InQ(int x){
	for(int i=x-1;i>=0;i--)
		if(memo[1][x]==memo[1][i])
			return i;
	return -1;
}
int main(){
	int caseT, A, B, now, pre;
	scanf("%d\n",&caseT);
	while(scanf("%d %d\n",&A,&B)!=EOF){
		printf("%d.",A/B);
		memo[1][0]=A%B;
		for(L=0;(pre=InQ(L))==-1 and L<50;L++){
			now=10*memo[1][L],
			memo[0][L  ]=now/B,
			memo[1][L+1]=now%B;
		}
		for(int i=0;i<pre;i++)
			printf("%d",memo[0][i]);
		putchar('(');
		for(int i=pre;i<L;i++)
			printf("%d",memo[0][i]);
		if(L==50 and memo[1][L]>0) printf("...");
		puts(")");
	}
 
}