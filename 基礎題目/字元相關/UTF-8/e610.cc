/* 給定一個 HyperLink，請將當中的 Unicode 亂碼轉為 UTF-8 編碼輸出
 * 解題關鍵：格式轉換
 * 抓到'%'時根據後面兩個字元組合的１６進位判斷
 *      轉換後的字碼小於０( SignBit=1 )代表這個為 UTF-8 格式開頭的格式："％ＸＸ％ＸＸ％ＸＸ"
 *                否則直接依據 ASCii 轉換代表的字元
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxL=1e4;
char ss[MaxL];
char word[4]={};
int CharToInt(char c){ return (c<='9')? c-'0': c-'A'+10; }
int main(){
 
	while(scanf("%s",ss)!=EOF){
		int idx=0;
		while(idx<strlen(ss)){
			if(ss[idx]!='%'){ putchar(ss[idx++]); continue; }
			word[0]= (CharToInt(ss[idx+1])<<4) |CharToInt(ss[idx+2]);
			if( word[0]>=0 ){ putchar(word[0]); idx+=3; continue; }
			word[1]= (CharToInt(ss[idx+4])<<4) |CharToInt(ss[idx+5]);
			word[2]= (CharToInt(ss[idx+7])<<4) |CharToInt(ss[idx+8]);
			printf("%s",word);
			idx+=9;
		}
		putchar('\n');
	}
}