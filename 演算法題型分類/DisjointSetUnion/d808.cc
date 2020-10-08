/* 給定Ｎ個部落住民和每位住民的同部落好友，輸出部落總數和最大部落的人數？
 * 解題關鍵：查並集
 * 注意事項：測資給定的方式類似 one_cycle，但題目並未保證且實測後確實非 one_cycle
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e6;
int root[MaxN+1];
int  num[MaxN+1];
 
int FindRoot(int x){ 
	return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
int main(){
	int N, M;
	while(scanf("%d\n",&N)!=EOF){
		for(int i=1;i<=N;i++)
      root[i]=i, num[i]=1;
 
		int Group=N;
		int max_num=1;
		for(int v, u=1;u<=N;u++){
			scanf("%d",&v);
			int root_u=FindRoot(u);
			int root_v=FindRoot(v);
			if(root_u==root_v) continue;
			root[root_v]=root_u;
			num[root_u]+=num[root_v];
			max_num=max(max_num,num[root_u]);
			Group--;
		}
		printf("%d %d\n",Group,max_num);
	}
}