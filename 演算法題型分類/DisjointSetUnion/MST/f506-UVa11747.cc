/* 給定Ｍ條邊和Ｎ個點，形成環的情況下移除權重較大的邊，依照權重輸出小到大輸出被踢除邊的權重。
 * 邊不重複 且 保證每條邊的權重都不同
 * 解題關鍵：DSU-Minimal Spanning Tree(MST)
 * 會被移除的邊＝不屬於能形成 MST 的邊。
 * 做一次 MST 後標記哪些邊是有用到的，沒用到的就是需要輸出的邊。
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxN=1e3;
const int MaxM=25e3;
 
struct EDGE{
	int a, b, v;
	bool operator<(const EDGE &rhs)const{ return v<rhs.v; }
} edge[MaxM];
int root[MaxN];
 
int FindRoot(int x){ 
	return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
 
int main(){
	int N, M;
	while(scanf("%d %d\n",&N,&M)!=EOF){
		for(int i=0;i<M;i++)
			scanf("%d %d %d\n",&edge[i].a,&edge[i].b,&edge[i].v);
 
		sort(edge,edge+M);
		for(int i=0;i<N;i++)
			root[i]=i;
 
		int idx,uN=0;
		bool no_cycle=true;
		for(idx=0;idx<M and uN<N-1;idx++){
			int Ra=FindRoot(edge[idx].a);
			int Rb=FindRoot(edge[idx].b);
			if(Ra==Rb){ 
				printf("%d ",edge[idx].v);
				no_cycle=false;
				continue;
			}
			root[Rb]=Ra;
			uN+=1;
		}
		for(no_cycle&= idx==M; idx<M; idx++)
			printf("%d ",edge[idx].v);
		puts((no_cycle)? "forest": "");
	}
}