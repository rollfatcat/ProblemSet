/* 給定Ｎ個人進入和離開直播間的時間點，並保證同一時間點只會有一人進入/離開，輸出同時間最多在線觀看人數？
 * 解題關鍵：排序：入點和出點視為+1/-1
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e5;
int num[2][MaxN];
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i+=1)
		scanf("%d %d",&num[0][i],&num[1][i]);
	sort(num[0],num[0]+N);
	sort(num[1],num[1]+N);
 
	int ans=1;
	int cnt=1;
	int clk=num[0][0];
	for(int p0=1,p1=0; p0<N;)
		if(num[0][p0]<num[1][p1]){
			p0+=1;
			cnt+=1;
			ans=max(ans,cnt);
		}else{
			p1+=1;
			cnt-=1;
		}
	printf("%d\n",ans);
}
