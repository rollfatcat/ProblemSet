/* 題意：給定Ｔ筆測資，每筆測資輸入數字Ｎ，問有多少個Ｘ進位制時每個位數剛好只有０和１？
 * 核心：分區討論，以 1e3 為分界線，超過 1e3 時可以發現需要討論的最高次方向不可能超過６次方
 *		Ｘ < 1e3，枚舉每個數字判斷轉為Ｘ進位時是否符合要求 
 *      1e3 ≤ Ｘ，需要討論的最高次方向不可能超過６次方，用 BitMask 枚舉每個次方(１)選或(０)不選
 * 				 搜尋是否存在一個大於等於 1e3 的解帶入方程式 ... 帶入值越大對應的值有單調性 ... 二分搜尋
 * 實作：要注意計算時會 overflow 的問題，一但溢位就不需要計算算更高的次方項
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=1e3;
const long MaxN=1e18;
const int loop_limit=1e3;
const int mask_limit=7; // 最高位是６次方

bool func(long N,long B){
	for(; 0<N; N/=B)
		if( 1<N%B )
			return false;
	return true;
}
long f(long B,int nowS,long N){
	int _pow=0;
	__int128 val=1;
	__int128 ret=0;
	for(int last; 0<nowS; nowS^=last){
		last=nowS&-nowS;
		while(_pow<__lg(last)){
			val*=B;
			if( val>N )
				return N<<1;
			_pow++;
		}
		ret+=val;
	}
	return (ret>N)? N<<1: ret;
}
bool BinarySearch(long N,int mask){
	long lo=0;
	long hi=N+1;
	while( lo+1<hi ){
		long md=lo+hi>>1;
		long v=f(md,mask,N);
		if( N==v ){
			return md>=loop_limit;
		}else
			( N>v ? lo: hi)=md;
	}
	return false;
}
int main(){
	int caseT;
	long N;
	
	cin>>caseT;
	while( caseT-->0 ){
		cin>>N;
		int ans=1; 
		for(int base=3; base<loop_limit; base++)
			ans+=func(N,base);
		for(int mask=2; mask<(1<<mask_limit); mask++)
			ans+=BinarySearch(N,mask);
		cout<<ans<<"\n";
	}
}