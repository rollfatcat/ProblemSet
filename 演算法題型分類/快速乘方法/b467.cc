/* Ｎ個組員繞成一圈，每次順時針位移Ｍ個位置，問位移10^Ｋ次後第Ｘ位成員在幾號位子？
 * 每次位移Ｍ格時可以發現只要發生Ｎ次就會回到原來的位置(Ｎ個一循環)
 * 10^Ｋ 模Ｎ：快速幂次
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxK=1e9;
int main(){
	int N, M, K, X;
	scanf("%d %d %d %d\n",&N,&M,&K,&X);
	long cycle=1, base=10%N;
	for(;K>0;K>>=1,base=base*base%N)
		if(K&1)
			cycle=(cycle*base)%N;
	printf("%d\n",(X+M*cycle)%N);
}