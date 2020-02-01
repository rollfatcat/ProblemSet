/* 給定Ｓ, 將Ｓ轉換為一段連續整數的和(起始的數字最小化)
 * Ｓ＝Ｘ+...+Ｙ＝(Ｘ+Ｙ)*(Ｘ-Ｙ+1)/2
 * 枚舉2Ｓ的因數，暴力法從sqrt(2Ｓ)開始測試且觀察兩數可以得知：(Ｘ+Ｙ,Ｘ-Ｙ+1)必定是一奇一偶，
 * 只要符合上述兩條件的(Ｘ-Ｙ+1)必定就是最大的數字，找到後反推(Ｘ,Ｙ)。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e9;
int main(){
	for(int N;scanf("%d",&N) and N>0;){
		N<<=1;
		int now=sqrt(N), rhs;
		for(;N%now or ((rhs=N/now)&1)==(now&1);now--);
		printf("%d = %d + ... + %d\n",N>>1,(rhs-now+1)>>1,(rhs+now-1)>>1);
	}
}
