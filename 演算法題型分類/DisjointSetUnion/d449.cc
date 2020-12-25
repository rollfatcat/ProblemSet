/* 給定Ｎ個信件編號(１-Ｎ)和Ｍ次操作，輸出最後有多少種類？
 * 操作 1 x y 代表將信件編號 x y 分成同一類
 * 操作 2 x   代表將信件編號 x 獨立
 * 解題關鍵：DSU
 * 操作１和原始的 DSU Union 一樣
 * 操作２的『獨立』＝ 將 team 和 root 分開處理，create 一個新的 root 並初始化 size。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxM=1e6;
const int MaxN=1e4;

int team[MaxM+1];
int root[MaxM+1];
int size[MaxM+1];
int FindRoot(int x){ return (root[x]==x)?x:root[x]=FindRoot(root[x]); }

int main(){
	int N, M, opt, u, v;
	while(scanf("%d %d\n",&N,&M)!=EOF){
		for(int i=1;i<=N;i++){
			team[i]=root[i]=i, 
			size[i]=1;
		}
		int teamID=N+1;
		int cnt=N;
		while(M-->0){
			scanf("%d",&opt);
			if(opt==1){
				scanf("%d %d\n",&u,&v);
				int Ru=FindRoot(team[u]);
				int Rv=FindRoot(team[v]);
				if(Ru==Rv) continue;
				root[Rv]=Ru;
				size[Ru]+=size[Rv];
				cnt-=1;
			}else{
				scanf("%d\n",&u);
				int Ru=FindRoot(team[u]);
				/* 若獨立時這封信件的種類只有這封時，可以視為這次獨立無效 */
				if(size[Ru]==1) continue;
				size[Ru]-=1;
				cnt+=1;
				team[u]=teamID;
				root[teamID]=teamID;
				size[teamID]=1;
				teamID+=1;
			}
		}
		printf("%d\n",cnt);
	}
}