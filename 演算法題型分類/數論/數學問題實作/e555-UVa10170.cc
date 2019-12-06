/*  數學問題：利用梯形公式推算 x
 *	給定S, D,  求 x*(x+1)/2 - S*(S-1)/2 ≥ D 時的 x？
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxS=1e4;
const long MaxD=1e15;
int main(){
	int S;
	long D, x;
	while(scanf("%ld %ld\n",&S,&D)==2){
		D=D+(S*(S-1)>>1)<<1;
		x=sqrt(D);
		printf("%ld\n",x+(x*(x+1)<D));
	}
}