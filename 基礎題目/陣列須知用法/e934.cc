/* 給定一段由'A''C''G''T'構成的 DNA 轉錄為 RNA 片段
 * 等同字元加密問題
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=1000; // 20 ≤ DNA 的字串長 ≤ 1000
char mapped[256];
int main(){
	mapped['T']='A';
	mapped['A']='U';
	mapped['C']='G';
	mapped['G']='C';
	for(char ch;(ch=getchar())!=EOF;)
		putchar( mapped[ch] );
}
