/* 給定Ｎ個城市和Ｍ座橋有Ｑ次的查詢，每次查詢時移除第Ｑi座橋後有幾個"區域"(彼此互不聯通)
 * 題目盲點：如何保證移除指定編號的橋後是否會造成"新區域"，判斷移除時是否為(強聯通)？
 * 解題關鍵：DSU＋離線處理
 * 初始時把"不需要移除的橋"優先聯通起來代表經歷Ｑ次移除後的區域數量。
 * 順向移除＝反正連接，反向新增聯通的橋但輸出時要依據查訊順序所以要利用陣列把先算出來的答案存起來
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
const int MaxM=1e6;
int root[MaxN+1];
int edge[MaxM+1][2];
int qry[MaxM];
int ans[MaxM];
bool on[MaxM]={};

int FindRoot(int x){
	return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
int main(){
	int N, M, Q;
	// input
	scanf("%d %d",&N,&M);
	for(int i=1;i<=M;i+=1)
		scanf("%d %d",&edge[i][0],&edge[i][1]);
	scanf("%d",&Q);
	for(int i=0;i<Q;i+=1){
		scanf("%d",&qry[i]);
		on[ qry[i] ]=1;
	}
	// offline-DSU
	for(int i=1;i<=N;i+=1)
		root[i]=i;
	int cnt=N;
	for(int i=1;i<=M;i+=1)
		if(on[i]==0){
			int Ru=FindRoot(edge[i][0]);
			int Rv=FindRoot(edge[i][1]);
			if(Ru==Rv) continue;
			root[Rv]=Ru;
			cnt-=1;
		}
	ans[Q-1]=cnt;
	for(int i=Q-1; i>=0; ans[--i]=cnt){
		int Ru=FindRoot(edge[ qry[i] ][0]);
		int Rv=FindRoot(edge[ qry[i] ][1]);
		if(Ru==Rv) continue;
		root[Rv]=Ru;
		cnt-=1;
	}
	for(int i=0; i<Q; i+=1)
		printf("%d\n",ans[i]);
}