/* 給定Ｎ種壽司的價格和Ｑ位客人願意負擔的「最低價格」，輸出所有客人的出價總和
 * 解題關鍵：二分搜尋法
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
int num[MaxN+1];
int main(){
	int N, Q, v;
	
	scanf("%d %d",&N,&Q);
	for(int n=0; n<N; n+=1)
		scanf("%d",&num[n]);
	sort(num,num+N);
	num[N]=0;
	long ans=0;
	while(Q-->0){
		scanf("%d",&v);
		ans+=*lower_bound(num,num+N,v);
	}
	printf("%ld",ans);
}