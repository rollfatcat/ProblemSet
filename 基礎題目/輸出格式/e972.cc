/* 型態轉換( 無精確度問題 )
 * 給定Ｎ元的新台幣、花費Ｍ元後的他國貨幣和哪國貨幣
 * 若不足支付Ｍ元的花費則輸出"No Money"
 * 若剩餘的錢小於0.05 則輸出"0.0"
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	map<char,double> Type;
	Type['T']=1.00;
	Type['U']=30.9;
	Type['J']=0.28;
	Type['E']=34.5;
	
	for(int N,M;scanf("%d\n%d ",&N,&M)!=EOF;){
		char ch=getchar();
		double n=N/Type[ch]-M;
		(n<0.0)? puts("No Money"): printf("%c %.2lf\n",ch,(n<0.05)?0.0:n);
	}
}