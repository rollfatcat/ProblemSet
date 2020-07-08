/* 給定Ｎ個房間的點數和Ｑ次點數要求，輸出最後會待在哪個房間？
 * 題解核心："環狀"前綴和＋二分法
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxQ=2e4;
long preS[MaxN+1];
int main(){
	int N, Q, v;
	scanf("%d %d\n",&N,&Q);
	
	preS[0]=0;
	for(int i=1;i<=N;i++)
		scanf("%d",&v),
		preS[i]=preS[i-1]+v;
	int pos=1;
	while(Q--){
		scanf("%d",&v);
		if(v>preS[N]-preS[pos-1])
			v-= preS[N]-preS[pos-1], pos=1;
		pos=lower_bound(preS,preS+N+1,preS[pos-1]+v)-preS;
        pos=(pos==N)? 1:pos+1;
	}
	printf("%d\n",pos);
}
