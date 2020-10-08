/* 給定Ｎ個景點編號和Ｍ個相鄰的關係，輸出一次行程最多能去玩的景點數？
 * 關係：(Ａ,Ｂ)代表兩個地點相鄰可以並在同一個行程。
 * 解題關鍵：查並集(裸題)
 * 輸出最多數字最多的群。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e6;
const int MaxM=1e5;
int root[MaxN];
int num[MaxN];
 
int FindRoot(int x){ 
	return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
int main(){
	int N, M, u, v;
	while(scanf("%d %d\n",&N,&M)!=EOF){
		/* 初始化 */
    for(int i=0;i<N;i++)
      root[i]=i, num[i]=1;
    /* FIND & UNION */
		int max_num=1;
		while(M-->0){
			scanf("%d %d\n",&u,&v);
			int root_u=FindRoot(u);
			int root_v=FindRoot(v);
			if(root_u==root_v) continue;
			root[root_v]=root_u;
			num[root_u]+=num[root_v];
			max_num=max(max_num,num[root_u]);
		}
		printf("%d\n",max_num);
	}
}