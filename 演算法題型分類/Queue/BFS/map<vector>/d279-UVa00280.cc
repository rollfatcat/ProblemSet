/* 給定Ｎ個點(編號１-Ｎ)和節點間的"有向"邊，之後輸入Ｑ個起點時輸出該起點出發無法抵達的節點編號。
 * 有向邊：該列的第一個數字代表有向邊的起點，之後的其他數字(不包括０)代表源自該起點有向邊的終點
 * 解題關鍵：BFS / DFS
 * 每次給定起點後做BFS，遊遍有向邊可以抵達的其他節點。
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, Q, from, to, start;
	while(scanf("%d\n",&N)!=EOF and N>0){
		vector<int> edge[N+1];
		while(scanf("%d",&from)!=EOF and from>0)
			while(scanf("%d",&to)!=EOF and to>0)
				edge[from].push_back(to);
		scanf("%d",&Q);
		while(Q-->0){
			scanf("%d",&start);
			vector<bool> vis(N+1);
			int cnt=N;
			/* BFS 走地圖 */
			queue<int> Q;
			for(int to:edge[start])
				Q.push(to);
			while(Q.empty()==0){
				int now=Q.front(); Q.pop();
				if(vis[now]) continue;
				vis[now]=1;
				cnt--;
				for(int to:edge[now])
					if(vis[to]==0)
						Q.push(to);
			}
			printf("%d",cnt);
			for(int i=1;i<=N;i++)
				if(vis[i]==0)
					printf(" %d",i);
			putchar('\n');
		}
	}
}

