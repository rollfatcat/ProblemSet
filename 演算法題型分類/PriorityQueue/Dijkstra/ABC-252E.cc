/* 給定Ｎ個城市和Ｍ條道路，使１號城市到達其他城市的距離總和最小化，輸出應該要建立哪些編號的道路？
 * 題目保證任意２個城市可以直接或間接抵達其他城市
 * 問題盲點：最小化道路的距離總和 ≠ 最小化１號城市到其他城市的距離和
 *         前者是 MST ，後者是 Dijkstra
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e5+1;
const int MaxM=2e5+1;
const int MaxC=1e9;
const long INF=(long)1<<60;
 
struct NODE{
	int v, m; long c;
	NODE(int v=0,long c=0,int m=0):v(v),c(c), m(m){}
	bool operator<(const NODE &rhs)const{ return c>rhs.c; }
} ;
vector<NODE> edge[MaxM];
bool use[MaxM]={};
long dis[MaxN];
 
 
int main(){
	int N, M, a, b, c;
	
	scanf("%d %d",&N,&M);
	for(int m=1; m<=M; m++){
		scanf("%d %d %d",&a,&b,&c);
		edge[a].push_back( NODE(b,c,m) );
		edge[b].push_back( NODE(a,c,m) );
	}
	for(int n=1; n<=N; n++){
		sort(edge[n].begin(),edge[n].end(),[](NODE& lhs,NODE &rhs){ return lhs.c<rhs.c; });
		dis[n]=INF;
	}
	
	dis[1]=0;
	priority_queue<NODE> PQ;
	PQ.push( NODE(1,0) );
	while( PQ.empty()==0 ){
		NODE now=PQ.top(); PQ.pop();
		if( dis[now.v]!=now.c ) continue;
		use[now.m]=1;
		for(NODE rhs: edge[now.v])
			if( rhs.c+now.c<dis[rhs.v]){
				PQ.push( NODE(rhs.v,rhs.c+now.c,rhs.m) );
				dis[rhs.v]=rhs.c+now.c;
			}
	}
	// output
	for(int m=1; m<=M; m++)
		if( use[m] )
			printf("%d ",m);
}