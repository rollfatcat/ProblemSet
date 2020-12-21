//經典難題
//解法：(1)先跑一次 不經過城堡的Floyed(題目規定有穿鞋不可經過城堡)(目的方便之後能判斷魔法鞋能"一步"到達的村莊距離)
//		  (2)跑Dijkstra 第一個找到可回到終點的就是答案(紀錄 D[到第n個村莊最短距離][還剩下幾次可以使用魔法鞋]是一個二維陣列)
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x7f7f7f7f
int A,B,M,L,K,N;
int dis[105][105];
struct nn{int n,k,v;};
struct comp{bool operator()(nn i,nn j){return i.v>j.v;}};
void Floyed();
int Dijkstra();
int main(void){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&A,&B,&M,&L,&K);
		N=A+B;
		memset(dis,0x7f,sizeof(dis));
		for(int i=1;i<=N;i++)
			dis[i][i]=0;
		for(int u,v,l; M--;)
			scanf("%d%d%d",&u,&v,&l),	dis[u][v]=dis[v][u]=l;
		Floyed();
		printf("%d\n",Dijkstra());
	}
}

void Floyed(){
	for(int k=1;k<=A;k++) //不經過Castle的更新  by Floyed-Wall
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
int Dijkstra(){
	int i,j,k;
	//D[到第n個村莊最短距離][還剩下幾次可以使用魔法鞋]
	vector<vector<int> >DP(N+1);//二維陣列處理
	for(i=1;i<N;i++)
		DP[i].resize(K+1,INF);
	DP[N].resize(K+1,0);
	priority_queue<nn,vector<nn>,comp> PQ;
	PQ.push(nn{N,K,0});
	while(!PQ.empty()){
		nn now=PQ.top();	PQ.pop();
		if(now.n==1)//PriorityQueue的特性 在沒有複邊的情況下 第一個輸出即是答案
			return now.v;
		for(i=1;i<=N;i++){
			if(dis[now.n][i]<=L && now.k && DP[i][now.k-1]>now.v)//消耗一次魔法鞋 在魔法鞋能抵達的範圍村莊去更新距離
				DP[i][now.k-1]=now.v,
				PQ.push(nn{i,now.k-1,now.v});
			if(DP[i][now.k]>now.v+dis[now.n][i])//不消耗魔法鞋 繼續跑
				DP[i][now.k]=now.v+dis[now.n][i],
				PQ.push(nn{i,now.k,DP[i][now.k]});
		}
	}
	return -1;//基本上不會發生 這題保證有答案
}
