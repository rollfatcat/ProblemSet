/* 給定維度Ｄ切割Ｃ次時可以產生的空間數
 * 枚舉Ｄ=1,2,3...時可以發現狀態轉移的規律
 *   Ｃ | 1  2  3  4  5
 * Ｄ=1 | 2  3  4  5  6
 * Ｄ=2 | 2  4  7 11 16
 * Ｄ=3 | 2  4  8 15 26
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
const int MaxD=50;
const int MaxC=50;

long dpv[MaxD+1][MaxC+1]={};
int main(){
	for(int D=1;D<=MaxD;D++)
		dpv[1][D]=D+1;
	for(int D=2;D<=MaxD;D++)
		for(int C=1;C<=MaxC;C++)
			dpv[D][C]=(D>=C)? ((long)1<<C): dpv[D][C-1]+dpv[D-1][C-1];
	
	for(int Q; scanf("%d\n",&Q)!=EOF;){
		for(int D,C;Q--;)
			scanf("%d %d\n",&D,&C),
			printf("%ld\n",dpv[D][C]);
	}
}
