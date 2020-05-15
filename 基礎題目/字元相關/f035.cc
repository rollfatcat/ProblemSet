/* 給定一行"字串"(包含換行符號)
 * 輸出對應字串中每個字元的 ASCii Code
 * 注意：測資結果包含 ^J( ASCii＝10 )，應該是用編輯器結束編輯時的文件結尾字元
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=50;
char ch;
int main(){
	char ch=getchar(); printf("%d",ch);
	while((ch=getchar())!=EOF and ch!=10)
		printf("_%d",ch);
	putchar('\n');
}