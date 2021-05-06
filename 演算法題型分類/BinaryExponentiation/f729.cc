/* 給定十進位制的Ａ,八進位制的Ｂ, 輸出 A^B(mod 1e9+7)
 * 解題關鍵：費馬小定理＋快速幂次
 * 題目給定的Ｂ最大值為 700 位數，可以透過費馬小定理降低次方 ... A^(P-1)≡1(mod P) if P is prime
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=1e5;
const int MaxA=INT_MAX;
const int MaxB_L=700;
const int MOD=1e9+7;
 
int PowerMOD(char* ss,long out=0){
	for(; *ss!='\0'; ss++)
		out=( (out<<3)+ *ss-'0' )%(MOD-1);
	return out;
}
int main(){
	int caseT, B;
	long A, ans;
	char Bss[MaxB_L+2];
 
 
	scanf("%d",&caseT);
	while(caseT-->0){
		scanf("%ld %s",&A,Bss);
		A%=MOD;
		B=PowerMOD(Bss);
		ans=(B&1)? A: 1;
		for(B>>=1; B>0; B>>=1){
			A=A*A%MOD;
			if(B&1)
				ans=ans*A%MOD;
		}
		printf("%ld\n",ans);
	}
}