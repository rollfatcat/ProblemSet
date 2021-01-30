/* 給定一個字串代表簡化過的算式，輸出實作後計算的結果？
 *     f(x)=2x-3
 *   g(x,y)=2x+y-7
 * h(x,y,z)=3x-2y+z
 * 解題關鍵：遞迴＋字串轉換為數字(需要處理負數)
 * 題目盲點：呼叫函數處理多個傳入的參數時，若數個參數也都要等候呼叫函數計算後才能獲得時，呼叫順序為右到左。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=1e3;
const int MaxV=1e3;
char ss[MaxL+2];
long func_F(long x){ return (x<<1)-3; }
long func_G(long x,long y){ return (x<<1)+y-7; }
long func_H(long x,long y,long z){ return x+(x-y<<1)+z; }

long Recursion(){
	scanf("%s",ss);
	if(ss[0]=='f')  
		return func_F(Recursion());
	if(ss[0]=='g'){
		long x=Recursion();
		return func_G(x,Recursion());
	}
	if(ss[0]=='h'){
		long x=Recursion();
		long y=Recursion();
		return func_H(x,y,Recursion());
	}
	long x=0;
	bool neg= ss[0]=='-';
	for(int i=neg; ss[i]!='\0'; i++)
		x=(x<<3)+(x<<1)+ss[i]-'0';
	return (neg)? -x: x;
}
int main(){
	printf("%ld\n",Recursion());
}