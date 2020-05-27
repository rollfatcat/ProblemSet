/* 給定一個字串判斷是不是迴文？
 * 迴文的定義：前後字串呈現鏡像對稱且字串長度＝偶數
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=5e2;
char ss[MaxL+2];
int main(){
	while(scanf("%s\n",ss)!=EOF){
		int L=strlen(ss);
		if(L&1){ puts("NO");continue; }
		bool IsPalindrome=1;
		for(int i=0;i<(L>>1);i++)
			IsPalindrome&= ss[i]==ss[L-1-i];
		puts((IsPalindrome)?"YES":"NO");
		if(IsPalindrome){
			for(int i=0;i<(L>>1);i++)
				putchar(ss[i]);
			putchar('\n');
		}
	}
}