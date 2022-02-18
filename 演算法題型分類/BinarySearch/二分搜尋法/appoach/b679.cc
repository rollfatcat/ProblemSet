/* 題目給定Ｎ，輸出高度Ｈ(Ｎ)時滿足Ｈ*(Ｈ+1)/2 ≧ Ｎ
 * 題目保證"高度" ≦ INT_MAX，反推Ｎ ≦ LONG_MAX
 * 解題關鍵：數學公式推導(Ｈ太大，不可能建表做二分搜尋)
 * Ｈ*(Ｈ+1) ≧ 2Ｎ，又因為計算時會乘以２，所以Ｎ的型態必須宣告為 unsigned long 避免溢位
 */
#include<bits/stdc++.h>
using namespace std;

const long MaxN=LONG_MAX;
int main(){
	unsigned long N;
	while(scanf("%lu\n",&N)!=EOF)	
		printf("%d\n",(int)ceil(sqrt(2*N)-0.5));
}