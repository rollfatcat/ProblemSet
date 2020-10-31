/* 給定Ｎ組對應關係，代表物品 s1[i] 屬於類別 s2[i]
 * 最後給定一個字串將屬於該字串類別的所有物品依照字典序輸出。
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxN=50;
const int MaxL=15+2;
int memo[MaxN];
char s1[MaxN][MaxL];
char s2[MaxN][MaxL];
char tag[MaxL];
inline bool ssEqual(char* sa,char* sb){
	for(int i=0;sa[i]!='\0';i++)
		if(sa[i]!=sb[i])
			return false;
	return strlen(sa)==strlen(sb);
}
inline bool ssComp(int a,int b){
	for(int i=0;s1[a][i]!='\0';i++)
		if(s1[a][i]!=s1[b][i])
			return s1[a][i]<s1[b][i];
	return true;
}
int main(){
	for(int N;scanf("%d\n",&N)!=EOF;){
		// 讀取測資
		for(int i=0;i<N;i++)
			scanf("%s %s\n",s1[i],s2[i]);
		scanf("%s\n",tag);
		// 比對 tag 和 s2 將相同的物品編號抓出來
		int sz=0;
		for(int i=0;i<N;i++)
			if(ssEqual(s2[i],tag))
				memo[sz++]=i;
		// 依照『字典序』編排物品號碼，最後根據排序後的號碼輸出。
		sort(memo,memo+sz,ssComp);
		if(sz==0) puts("No");
		for(int i=0;i<sz;i++)
			puts(s1[memo[i]]);
	}
}