/* 
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e4;
int root[MaxN+1];
 
int FindRoot(int x){ 
	return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
int main(){
	int N, M, u, v;
	while(scanf("%d %d\n",&N,&M)!=EOF){
		for(int i=0;i<=N;i++)
      root[i]=i;
 
		int Group=N+1;
		int root_u, root_v;
		while(M-->0){
			scanf("%d",&u);
			root_u=FindRoot(u);
			while(getchar()==' '){
				scanf("%d",&v);
				root_v=FindRoot(v);
				if(root_u==root_v) continue;
				root[root_v]=root_u;
				Group--;
			}
		}
 
		scanf("%d",&M);
		root_u=FindRoot(0);
		while(M-->0){
			scanf("%d",&v);
			root_v=FindRoot(v);
			if(root_u==root_v) continue;
			root[root_v]=root_u;
			Group--;
		}
		printf("%d\n",Group);
	}
}