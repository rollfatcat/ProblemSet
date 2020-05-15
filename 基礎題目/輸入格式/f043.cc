/* 給定兩個數字Ｒ,Ａ 輸出Ｒ+Ｂ=Ａ的格式,Ｒ≤Ｂ
 * 當Ａ＝Ｒ時, Ａ=Ａ-３
 * 題目保證Ｒ≤Ａ, Ｒ≤ 2147483648( 2^31, 剛好超過 int 上限 )
 */
#include<bits/stdc++.h>
using namespace std;

const long MaxR=2147483648;
int main(){
	for(long A,B,R;scanf("%ld %ld\n",&A,&R)!=EOF;){
		if(A==R) R-=3;
		B=A-R;
		if(R>B) swap(R,B);
		printf("%ld+%ld=%ld\n",R,B,A);
	}
}
