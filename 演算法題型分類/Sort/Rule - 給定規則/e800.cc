/* 給定Ｎ部影片的名稱、觀看人數、影片長度、平均觀看時間、相關度。
 * 依據受歡迎程度(觀看人數×平均觀看時間÷影片長度×相關度)大到小輸出影片名稱
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxN=50;
char name[MaxN][20]; // 字串長度不超過15
int P[MaxN];
int L[MaxN];
int W[MaxN];
int R[MaxN];
int ord[MaxN];

inline bool compare(int a,int b){
	long va=(long)P[a]*W[a]*L[b]*R[a];
	long vb=(long)P[b]*W[b]*L[a]*R[b];
	return (va==vb)? a<b: va>vb;
}
int main(){
	for(int N;scanf("%d\n",&N)!=EOF;){
		for(int i=0;i<N;i++)
			scanf("%s %d %d %d %d\n",name[i],&P[i],&L[i],&W[i],&R[i]),
			ord[i]=i;
		sort(ord,ord+N,compare);
		for(int i=0;i<N;i++)
			printf("%s\n",name[ord[i]]);
	}
}