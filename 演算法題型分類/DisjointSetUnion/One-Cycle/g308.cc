/* 給定Ｎ個格子(下個傳送點)和是否有放置食物，由Ｔ格出發時輸出路徑上可以獲得的最多食物？
 * 解題關鍵：需要判斷抵達的位置是否已經走過 ... memoization
 * 陣列儲存“狀態定義”
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
int nxt[MaxN];
int food[MaxN];// ０=沒有食物，１=有食物，-1=已經走過
int main(){
	int N, S;
	
	scanf("%d %d",&N,&S);
	for(int i=0;i<N;i+=1)
		scanf("%d",&nxt[i]);
	for(int i=0;i<N;i+=1)
		scanf("%d",&food[i]);
	int ans=0;
	for(; food[S]!=-1; S=nxt[S]){
		ans+=food[S];
		food[S]=-1;
	}
	printf("%d\n",ans);
}

