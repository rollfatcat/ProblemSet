/* 給定１６進位的字串：Ｕ＋ｘｘｘｘ，輸出３格字元代表該字串的２進位和其代表的字元。
 */
#include<bits/stdc++.h>
using namespace std;

int CharToInt(char c){ return (c<='9')? c-'0': c-'A'+10; }
/* BitMask確認該位元是否為１ */
void IntToBit(int v){ 
	for(int i=7;i>=0;i--)
		putchar( (1<<i & v )? '1':'0' );
}
char ss[10];
char Bnum[4];
int main(){
	/* 格式：Ｕ＋ｘｘｘｘ ： ｘ的每個字元都是１６進位制 */
    while(scanf("%s\n",ss)!=EOF){
		Bnum[0]=CharToInt(ss[2]);
		Bnum[1]=CharToInt(ss[3]);
		Bnum[2]=CharToInt(ss[4]);
		Bnum[3]=CharToInt(ss[5]);
		/* 轉換為 UTF-8，每３個字元描述一個 wchar */
		Bnum[0]=(14<<4)|Bnum[0];
		Bnum[1]=(1<<7)|(Bnum[1]<<2)|(Bnum[2]>>2);
		Bnum[2]=(1<<7)|((Bnum[2]&3)<<4)|Bnum[3];
		Bnum[3]='\0';
		/* 輸出每個字元的２進位 */
		IntToBit(Bnum[0]); putchar(' ');
		IntToBit(Bnum[1]); putchar(' ');
		IntToBit(Bnum[2]); putchar('\n');
		/* 依照 UTF-8 方式輸出字元(字串) */
		printf("%s\n",Bnum);
	}
}


