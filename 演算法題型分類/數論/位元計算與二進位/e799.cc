/* 給定Ｒ、Ｃ、指定字元和Ｒ個數字
 * 將每個數字轉換為二進制的Ｃ位數，若該位數的值＝０輸出'.'否則指定字元
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxR=62;
const int MaxC=62;
int main(){
	int R, C;
	char ch;
	
	scanf("%d %d\n",&R,&C);
	ch=getchar();
	for(long v;R--;){
		scanf("%ld",&v);
		for(long mask=(long)1<<C-1; mask>0;mask>>=1)
			putchar( (v&mask)? ch:'.' ),
			putchar( (mask>1)? ' ':'\n');
	}
}