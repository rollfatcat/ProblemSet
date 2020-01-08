/* 給定Ｎ顆大理石，兩種造價的盒子和各自可裝的大理石數量
 * 在『剛好裝滿』的前提下最小化盒子成本
 * Ｎ必須能被兩種盒子可裝的大理石數量的最大公因數整除。
 * 從０個開始枚舉高成本盒子直到大理石數量可以整除低成本盒子容量時便輸出答案，注意盒子的數量不可為負數。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e9;
const int MaxC=2e9;
int main(){
	for(int N,c1,n1,c2,n2;scanf("%d\n",&N) and N>0;){
		scanf("%d %d\n%d %d\n",&c1,&n1,&c2,&n2);
		int GCD=__gcd(n1,n2);
		if(N%GCD){ puts("failed"); continue; }
		int cnt=0;
		if((long)c1*n2>(long)c2*n1){
			for(;N>0 and N%n2;cnt++,N-=n1);
			if(N%n2==0) printf("%d %d\n",cnt,N/n2);
			else puts("failed");
		}else{
			for(;N>0 and N%n1;cnt++,N-=n2);
			if(N%n1==0) printf("%d %d\n",N/n1,cnt);
			else puts("failed");
		}
	}
}