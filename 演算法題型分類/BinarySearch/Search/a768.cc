/* 給定Ｎ個不重複的邊長，輸出任選３邊剛好可以形成直角三角形的組合數量？
 * 解題關鍵：二分搜尋法的STL：binary_search ( 200ms )
 * 枚舉較短的２條邊長，搜尋數列中是否存在最長邊的邊長(兩邊平方值的和)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=3e3;
long len[MaxN];
long sqr[MaxN];
int main(){
	int N;
	scanf("%d\n",&N);
	for(int i=0;i<N;i++)
		scanf("%ld",&len[i]);
	sort(len,len+N);
	for(int i=0;i<N;i++)
		sqr[i]=len[i]*len[i];
	
	int ans=0;
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			ans+= binary_search(sqr,sqr+N,sqr[i]+sqr[j]) ;
	printf("%d\n",ans);
}