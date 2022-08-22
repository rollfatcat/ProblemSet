/* 給定Ｎ個隕石重量和Ｍ個捕捉器負荷限制，每個捕捉器只能抓取一顆隕石，輸出可以捕捉到最多的隕石重量總和？
 * 解題關鍵：搜尋 / 雙指標
 * 貪婪法，由大到小枚舉每個捕捉器可以抓取到的隕石重量
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxW=1e9;
const int MaxC=1e9;

int w[MaxN];
int c[MaxN];
int main(){
	int N, M;
	scanf("%d %d\n",&N,&M);
	for(int i=0; i<N; i+=1)
		scanf("%d",&w[i]);
	for(int i=0; i<M; i+=1)
		scanf("%d",&c[i]);
	
	sort(w,w+N);
	sort(c,c+M);
	long ans=0;
	for(int p0=N-1, p1=M-1; p0>=0 and p1>=0; p1-=1){
		while(p0>=0 and w[p0]>c[p1])
			p0-=1;
		if(p0>=0)
			ans+=w[p0--];
	}
	printf("%ld\n",ans);
}