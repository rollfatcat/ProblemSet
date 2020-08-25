/* 給定ＡＢＣ和運算子(AND/OR/XOR)的機制，輸出可能的運算子，若不存在任一個則輸出"IMPOSSIBLE"。
 * 解題關鍵：位元運算
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	int A, B, C;
	scanf("%d %d %d\n",&A,&B,&C);
	/* 將ＡＢＣ根據表格規定轉換為布林值 */
	bool a= A!=0;
	bool b= B!=0;
	bool c= C!=0;
	/* 輸出可能的運算子選項 
	 * 邏輯運算順序優先於位元運算，所以需要括號
	 */
	bool hasAns=0;
	if((a&b) == c){ hasAns=1; puts("AND"); }
	if((a|b) == c){ hasAns=1; puts("OR");  }
	if((a^b) == c){ hasAns=1; puts("XOR"); }
	if(hasAns==0) puts("IMPOSSIBLE");
}

