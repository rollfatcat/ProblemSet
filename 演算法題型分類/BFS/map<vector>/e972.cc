/* Floyd Warshall Algorithm：
 * https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/ 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e2;
const int MaxQ=2e4;

bool to[MaxN][MaxN];
int main(){
	for(int N,M,Q;scanf("%d %d %d\n",&N,&M,&Q)!=EOF;){
		memset(to,0,sizeof(to));
		for(int u,v;M--;to[u][v]=1)
			scanf("%d %d\n",&u,&v);
		for(int md=0;md<N;md++)
			for(int st=0;st<N;st++)
				for(int ed=0;ed<N;ed++)
					to[st][ed]|= to[st][md]&to[md][ed];
		for(int u,v;Q--;puts( to[u][v]? "YES":"NO" ))
			scanf("%d %d\n",&u,&v);
	}
}