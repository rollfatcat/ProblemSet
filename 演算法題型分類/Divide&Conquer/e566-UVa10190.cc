/* 給定Ｎ和Ｍ，數列的每個位置代表Ｎ除以Ｍ的次數的商數，只有當Ｎ是Ｍ的某個次方時才輸出整個數列
 * 解題關鍵：
 * 特殊例子：(0,0)(0,1)(1,0)(1,1)視為"Boring!"
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e9;
int main(){
	int N, M;
	while(scanf("%d %d\n",&N,&M)!=EOF){
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