/* 給定Ｎ個號碼，求所有號碼的排列(由小到大輸出)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=9; // 1 ≤ N ≤ 9
unsigned int N, num[MaxN], keep[MaxN];
bool use[MaxN]={};

inline void DFS(int depth){
	if(depth==N){
		for(int i=0;i<N;i++)
			printf("%u ",keep[i]);
		putchar('\n');
		return;
	}
	for(int i=0;i<N;i++)
		if(use[i]==0){
			keep[depth]=num[i];
			use[i]=1;
			DFS(depth+1);
			use[i]=0;
		}
}
int main(){
	scanf("%u\n",&N);
	for(int i=0;i<N;i++)
		scanf("%u",&num[i]);
	sort(num,num+N);
	DFS(0);
}