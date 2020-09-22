/* 給定一個"字母順序"和一個字串(只有大寫字母)後
 * 詢問若依給定的字母序排序後的字串中第pos個位置的字母是？
 * 二分搜尋法(不需要，字母最多26個)＋區間和
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxL=5e6;
int srt[26], cnt[26]={};
char ord[30]; // 最多26個不重複的大寫字母
int main(){
	scanf("%s\n",ord);
	for(char ch;(ch=getchar())!='\n';)
		cnt[ch-'A']++;
	int L=strlen(ord);
	srt[0]=cnt[ord[0]-'A'];
	for(int i=1;ord[i]!='\0';i++)
		srt[i]=cnt[ord[i]-'A']+srt[i-1];
 
	int Q, pos;
	for(scanf("%d\n",&Q); Q; Q--)
		scanf("%d\n",&pos),
		printf("%c\n",ord[upper_bound(srt,srt+L,pos-1)-srt]);
}
/*
ZAD
ZZZZZAAAADDD
3
1
6
12
 */