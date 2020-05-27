/* 給定Ｎ位畢業生的學號依據規則排序後，輸出學院(ID的第８個字元)和學生名字
 * 規則：(1)學院的字母代號Ａ-Ｚ (2)學號開頭第一碼 (3)輸入順序
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e2;
const int MaxL=10+2;
char ID[MaxN][MaxL];
char name[MaxN][MaxL];
int ord[MaxN];

inline bool compare(int a,int b){
	if(ID[a][8]!=ID[b][8]) return ID[a][8]<ID[b][8];
	if(ID[a][0]!=ID[b][0]) return ID[a][0]<ID[b][0];
	return a<b;
}
int main(){
	for(int N;scanf("%d\n",&N)!=EOF;){
		for(int i=0;i<N;i++)
			scanf("%s %s\n",ID[i],name[i]),
			ord[i]=i;
		sort(ord,ord+N,compare);
		for(int i=0;i<N;i++)
			printf("%c:%s\n",ID[ord[i]][8],name[ord[i]]);
	}
}