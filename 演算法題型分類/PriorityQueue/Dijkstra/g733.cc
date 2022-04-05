/* 給定Ｎ個點和２種類型路線的邊(雙向)，最多轉乘一次時從Ｓ抵達Ｅ的最少費用？
 * 狀態定義：抵達點的編號/ 走過來的路線類型/ 剩餘的轉乘次數/ 費用
 * 狀態轉移：根據抵達該編號時的路線類型 和 選擇的路線 決定 剩餘的轉乘次數
 * Dijkstra : 優先根據最低成本展開
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
const int MaxE=1e5;
const int MaxC=1e2;
const int INF=1<<30;

int dp[MaxN][2][2]; // #node x #route x #time
struct EDGE{
	int n, v;
	EDGE(int n=0,int v=0):n(n),v(v){}
} ;
vector<EDGE> to[MaxN][2];

struct STATUS{
	int n, v;
	bool w, t;
	STATUS(int n=0,int v=0,bool w=0,bool t=0):n(n),v(v),w(w),t(t){}
	bool operator<(const STATUS rhs)const{ return v>rhs.v; }
} now, nxt;

int main(){
	int N, M1, M2, S, E;
	int u, v, c;
	
	scanf("%d %d %d\n",&N,&M1,&M2);
	while(M1-->0){
		scanf("%d %d %d\n",&u,&v,&c);
		to[u][0].push_back(EDGE(v,c));
		to[v][0].push_back(EDGE(u,c));
	}
	while(M2-->0){
		scanf("%d %d %d\n",&u,&v,&c);
		to[u][1].push_back(EDGE(v,c));
		to[v][1].push_back(EDGE(u,c));
	}
	scanf("%d %d\n",&S,&E);
	// init
	for(int n=0; n<N; n++)
		dp[n][0][0]=dp[n][0][1]=dp[n][1][0]=dp[n][1][1]=INF;
	dp[S][0][0]=dp[S][0][1]=dp[S][1][0]=dp[S][1][1]=0;
	priority_queue<STATUS> PQ;
	PQ.push(STATUS(S,0,0,1));
	PQ.push(STATUS(S,0,1,1));
	// Dijkstra
	while(!PQ.empty()){
		now=PQ.top(); PQ.pop();
		if(now.n==E) break;
		if(dp[now.n][now.w][now.t]!=now.v) continue;
		if(now.t or now.w==0)// 還有轉乘次數可以消耗 或 路線類型都是０
			for(EDGE one: to[now.n][0])
				if(dp[one.n][0][now.t-now.w]>now.v+one.v){
					dp[one.n][0][now.t-now.w]=now.v+one.v;
					PQ.push(STATUS(one.n,now.v+one.v,0,now.t-now.w));
				}
		if(now.t or now.w)// 還有轉乘次數可以消耗 或 路線類型都是１
			for(EDGE one: to[now.n][1])
				if(dp[one.n][1][now.t==now.w]>now.v+one.v){
					dp[one.n][1][now.t==now.w]=now.v+one.v;
					PQ.push(STATUS(one.n,now.v+one.v,1,now.t==now.w));
				}	
	}
	// output
	int ans=min(dp[E][0][0],dp[E][0][1]);
	ans=min(min(dp[E][1][0],dp[E][1][1]),ans);
	printf("%d",ans);
}