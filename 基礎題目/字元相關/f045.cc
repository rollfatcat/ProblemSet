/* 給定一組數字(９位數)，每個位數中選出最大和次大的２個數字(ｄ1,ｄ2)
 * d1×d1＋d2×d2＝(末三碼組成的百位數) 則輸出"Good Moring!" 否則"SPY!"
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=9;
char ss[MaxL+2];
int main(){
	while(scanf("%s\n",ss)!=EOF){
		int check=100*(ss[6]-'0')+10*(ss[7]-'0')+ss[8]-'0';
		sort(ss,ss+9);
		puts( ((ss[7]-'0')*(ss[7]-'0')+(ss[8]-'0')*(ss[8]-'0')==check)? "Good Morning!":"SPY!");
	}
}