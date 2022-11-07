/* 給定Ｎ段長度，從(０,０)出發每一步必須走給定的長度而且相鄰２步間必須保持垂直，問能否走到指定位置(Er, Ec)
 * 陷阱：乍看之下以為是 BFS ，但其實是把Ｒ,Ｃ視為２個互不干擾的維度，且對於Ｎ段長度拆分成２群
 * 解題核心：下一步移動時要和現在方向呈現 90 度 = Ｎ段的長度分成２群
 * 實作細節：第一部限制只能朝右移動 A0 ，所以導致第１步一定是影響Ｒ，再來是Ｃ，之後就交替影響 
 * 進階版：如果不限制第一步的方向時代表最終指定位置的判斷也得考慮Ｒ,Ｃ相反的情況
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e3;
const int MaxA=10;
const int MaxR=1e4;
const int MaxC=1e4;
 
bitset< MaxR+MaxA+1<<1 > dpR; // -10010 : 10010
bitset< MaxC+MaxA+1<<1 > dpC;
bool func(int r,int c){
	return dpR[MaxR+MaxA+r] & dpC[MaxR+MaxA+c] ;
}
int main(){
	int N, Er, Ec, A;
	
	cin>>N>>Er>>Ec>>A;
	dpR[ MaxR+MaxA+A ]=dpC[ MaxC+MaxA ]=1;
	for(int n=1; n<N; n++){
		cin>>A;
		if( n&1 )
			dpC= (dpC<<A)|(dpC>>A);
		else
			dpR= (dpR<<A)|(dpR>>A);
	}
	cout<< ( func(Er,Ec) ? "Yes": "No" );
}