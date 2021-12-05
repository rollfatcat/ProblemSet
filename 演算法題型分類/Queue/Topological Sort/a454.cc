/* 給定Ｎ個事件的處理時間和處理前需要先完成哪些其他的事件，輸出要完成整個專案最少需要多久？
 * 解題關鍵: DAG(Directed Acyclic Graph) ... topological sort
 * 當事件ｉ前的其他事件都完成更新後才做 relax (鬆弛)，鬆弛其他點時只保留最久的時間。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e3;
int cost[MaxN+1];
int memo[MaxN+1];
int need[MaxN+1];
vector<int> to[MaxN+1];

int main(){
	int caseT, N, sz;
	// input & init
	scanf("%d",&caseT);
  while(caseT-->0){
  	scanf("%d",&N);
  	fill(need,need+N+1,0);
  	fill(memo,memo+N+1,0);
  	for(int n=1; n<=N; n+=1){
  		scanf("%d %d",&cost[n],&sz);
  		to[n].resize(sz);
  		for(int i=0; i<sz; i+=1){
  			scanf("%d",&to[n][i]);
  			need[ to[n][i] ]+=1;
  		}
  	}
  	// get all starts
  	queue<int> Q;
  	for(int n=1; n<=N; n+=1)
  		if(need[n]==0){
  			memo[n]=cost[n];
  			Q.push(n);
  		}
  	// update
  	for(; Q.empty()==0; Q.pop()){
  		int now=Q.front();
  		for(int rhs: to[now]){
  			// maintain the longest one
        memo[rhs]=max(memo[rhs],memo[now]+cost[rhs]);
  			need[rhs]-=1;
  			if(need[rhs]==0)
  				Q.push(rhs);
  		}
  	}
  	// 以時間最久的為主
  	int ans=0;
  	for(int n=1; n<=N; n+=1)
  		ans=max(ans,memo[n]);
  	printf("%d\n",ans);
  }
}