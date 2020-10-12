/* 給定２個字串代表密文和明文，若符合一對一映射的加密方式根據輸入的新密文字串做還原？
 * 解題關鍵：陣列實作 HashTable 概念
 * 密文映射的明文字元必須是一對一對應且２６個字母都必須有所對應。
 * 第一次對應時直接紀錄到 HashTable 且 對應到的字元也必須沒被用過
 * 若已經紀錄時則核對和原本紀錄的字元不同 或 字元重複對應時都視為對應失敗輸出"Failed"。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=100;
char ss[2][MaxL+2];
char mapc[128];
bool use[128];

int main(){
	while(scanf("%s\n%s\n",ss[0],ss[1])!=EOF){
		memset(mapc,0,sizeof(mapc));
		memset(use ,0,sizeof(use));
		bool overwrite=0;
		int ch_cnt=0;
		for(int i=0;ss[0][i]!='\0';i++)
			if(mapc[ss[0][i]]==0 and use[ss[1][i]]==0){
				mapc[ss[0][i]]=ss[1][i];
				use[ss[1][i]]=1;
				ch_cnt++;
			}else if(mapc[ss[0][i]]!=ss[1][i] or 
			        (mapc[ss[0][i]]==0 and use[ss[1][i]]) ){
				overwrite=1;
				break;
			}
		scanf("%s\n",ss[0]);
		
		if(overwrite or ch_cnt<26){ puts("Failed"); continue; }
		for(int i=0;ss[0][i]!='\0';i++)
			putchar(mapc[ss[0][i]]);
		putchar('\n');
	}
}
