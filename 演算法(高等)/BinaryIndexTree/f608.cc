/* 給定Ｎ個(二維平面)點，玩家只能選擇向右或向上移動，經過指定格子時可以拾取該果實，輸出可以拾取到得最多數量？
 * 問題轉換 : dp[Yi]=max{ dp[Yj] }+1, Yj ≤ Yi
 * 解題關鍵 : Discretize(離散化)＋sort(更新順序)＋BIT(查詢)
 * 排序 : 點座標根據Ｘ值小到大，相同時才考慮Ｙ座標小到大更新
 * 離散化 : Ｙ座標點最多只有 2e5 個但範圍最大達 1e7
 * 查詢 : 查詢當前的Ｙ座標內範圍最大的值+1 並更新，注意 BIT 的使用格子從１開始
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e5;
const int MaxP=1e7;
int ord[MaxN+1];
int BIT[MaxN+1]={};
 
inline int lowbit(int x){ return x&-x; }
int Query(int p,int ans=0){
	for(; p>0; p^=lowbit(p))
		ans=max(ans,BIT[p]);
	return ans;
}
void Update(int p,int N){
	for(int u=p+lowbit(p); u<=N and BIT[p]>BIT[u]; u+=lowbit(u))
		BIT[u]=BIT[p];
}
 
int main(){
	int N;
 
	scanf("%d",&N);
	vector<vector<int>> data(N,vector<int>(2));
	for(int i=0;i<N;i+=1){
		scanf("%d %d",&data[i][0],&data[i][1]);
		ord[i]=data[i][1];
	}
	sort(data.begin(),data.end());
	sort(ord,ord+N);
	int uN=unique(ord,ord+N)-ord;
	int v, p;
	for(int i=0;i<N;i+=1){
		p=lower_bound(ord,ord+uN,data[i][1])-ord+1;
		v=Query(p);
		if( BIT[p]<v+1 ){
			BIT[p]=v+1,
			Update( p, uN );
		}
	}
	printf("%d\n",Query(uN));
}