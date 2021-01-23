/* 給定Ｎ個村莊和Ｍ條村莊間路徑的危險度，最小化從村莊１為起點時到其他編號的村莊危險度總和？
 * 路徑為有向邊，危險度可能為負的且保證路徑不會組成負向環
 * 題目盲點：Dijkstra 無法處理負權重、BellamnFloyed 處理的是 All Pair Shortest Path
 * 		    SPFA( Shortest Path Faster Algorithm ) ... 最糟糕的情況會卡O(Ｎ*Ｍ)
 * 解題關鍵：Topological Sort
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e5;
const int MaxM=2e5;
const int MaxW=11e4;
const long INF=LONG_MAX;
struct NODE{
	int v, c;
	NODE(int v=0,long c=0):v(v),c(c){}
} ;
 
vector<NODE> to[MaxN+1];
long DIS[MaxN+1];
int rem[MaxN+1]={};
 
int main(){
	int N, M, u, v, c;
	scanf("%d %d\n",&N,&M);
 
	for(int i=1;i<=N;i++)
		DIS[i]=INF, rem[i]=0;
	while(M-->0)
		scanf("%d %d %d\n",&u,&v,&c),
		to[u].push_back( NODE(v,c) ),
		rem[v]+=1;
	// 
	queue<int> Q;
	Q.push(1);
	DIS[1]=0;
	while(Q.empty()==0){
		int now=Q.front(); Q.pop();
		for(NODE nxt:to[now]){
			DIS[nxt.v]=min(DIS[nxt.v],DIS[now]+nxt.c);
			rem[nxt.v]-=1;
			if(rem[nxt.v]==0) 
				Q.push(nxt.v);
		}
	}
	long ans=0;
	for(int i=1;i<=N;i++)
		ans+=DIS[i];
	printf("%ld\n",ans);
}