/* 給定兩個數字Ａ,Ｂ作為範圍，輸出範圍內所有數字做 AND 位元運算後的數字
 * AND 只有存在一個數字的對應位置位元＝0 輸出數字的對應位元就會是０
 * 只需比對Ａ,Ｂ兩個數字的二進位，從最高位開始比直到出現『同個位置但位元不一樣』的情況。
 * 『同個位置但位元不一樣』＝__lg(A^B)，該位置以前的位數都設定為０做mask過濾。
 */
#include<bits/stdc++.h>
using namespace std;

const unsigned long one=1;
unsigned long mask[64]={}; // mask[i]＝從第i個位置以前的位數都是＝0但第i個位置以後＝１的數字
int main(){
	mask[62]=one<<63;
	for(int i=61;i>=0;i--)
		mask[i]=mask[i+1]>>1|mask[62];
	unsigned long A, B; // Ａ<Ｂ< 2^64
	while(scanf("%lu %lu\n",&A,&B)!=EOF)
		printf("%lu\n",A&mask[__lg(A^B)]);
}