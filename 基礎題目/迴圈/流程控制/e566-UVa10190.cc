/* 根據題目要求, 只有當數字是某個數字的Ｎ次方時才輸出整個數列
 * Special Case：(0,0)(0,1)(1,0)(1,1)視為"Boring!"
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2000000000;
int main(){
	int N, M;
	while(scanf("%d %d\n",&N,&M)==2){
		if(N<=1 or M<=1){ puts("Boring!"); continue; }
		vector<int> Q={N};
		for( ;N%M==0 and N>1;N/=M)
			Q.push_back(N/M);
		if(N>1){ puts("Boring!"); continue; }
		for(int x:Q)
			printf("%d ",x);
		putchar('\n');
	}
}