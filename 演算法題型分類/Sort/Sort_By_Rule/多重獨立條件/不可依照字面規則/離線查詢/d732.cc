/* 給定Ｎ個嚴格遞增的數字(數字不重複)和Ｋ次查詢。
 * 每次給定一個數字Ａi 輸出在數列中的位置(開始位置從１開始算)，若不存在則輸出０。
 * 解題關鍵：離線查詢
 * 若查詢的數字由小到大時可以做線性搜尋(兩個數列各自維護指標指向最前面的數字，類似d478)。
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxN=1e5;
const int MaxK=1e5;
int num[MaxN];
int qry[MaxK];
int ord[MaxK];
int ans[MaxK];

bool compare(int a,int b){ return qry[a]<qry[b]; }
int main(){
	int N, K;
    scanf("%d %d\n",&N,&K);
	for(int i=0;i<N;i++)
		scanf("%d",&num[i]);
    for(int i=0;i<K;i++)
  	    scanf("%d",&qry[i]),
	    ord[i]=i;
    sort(ord,ord+K,compare);
	for(int p1=0,p2=0; p1<N and p2<K;){
		if( qry[ ord[p1] ]<num[p2] )
			ans[ ord[p1++] ]=0;
		else if( qry[ ord[p1] ]==num[p2] )
			ans[ ord[p1++] ]=p2+1;
		else
			p2++;
	}
	for(int i=0;i<K;i++)
		printf("%d\n",ans[i]);
}