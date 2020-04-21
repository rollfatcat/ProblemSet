/* 模擬吃東西和花費的過程，輸出格式需要依照"剩餘的錢"和"已經用餐時間"對應的字串。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e2;
const int cost[2]={32,55};
const char ss[2][20]={"eats an Apple pie","drinks a Corn soup"};
int main(){
	int N; // 0 ≤ N ≤ 500
	int M; // 0 < M ≤ 60
	int T, K;
	while(scanf("%d %d %d\n",&N,&M,&K)!=EOF){
		for(T=0; N>=cost[K]; K^=1,T+=M){
			N-=cost[K];
			printf("%d: Wayne %s, and now he ",T,ss[K]);
			if(N==0) puts("doesn't have money.");
			else{ (N==1)? puts("has 1 dollar."):printf("has %d dollars.\n",N); }
		}
		if(T==0) puts("Wayne can't eat and drink.");
	}
}
