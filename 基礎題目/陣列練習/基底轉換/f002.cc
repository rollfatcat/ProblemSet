/* 輸入保證，所有數字序號和字母序號對應的數字序號均 ≤ 2e9
 * 給定Ｎ筆測資，當輸入的字串是(大寫)字母構成依『字典序』轉換為數字，否則反之。
 * 字典序：A, B, C, ..., Z, AA, AB, ..., ZZ, AAA...，順序的起始位置為１
 * 類似將10進位改為26進位，但因為從１開始所以模26時要注意。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=1e3;
const char STR[30]="ZABCDEFGHIJKLMNOPQRSTUVWXY";
char ss[20];
int main(){
	int caseT, v, L;
	scanf("%d\n",&caseT);
	while(caseT--){
		scanf("%s\n",ss); 
		v=0;
		if('A'<=ss[0] and ss[0]<='Z'){
			for(int i=0;ss[i]!='\0';i++)
				v=26*v+(ss[i]-'A'+1);
			printf("%d\n",v);
		}else{
			for(int i=0;ss[i]!='\0';i++)
				v=10*v+(ss[i]-'0');
			for(L=0;v>0;L++){
				ss[L]=STR[v%26];
				v=v/26-(v%26==0);
			}
			for(L--;L>=0;L--)
				putchar(ss[L]);
			putchar('\n');
		}
	}
}