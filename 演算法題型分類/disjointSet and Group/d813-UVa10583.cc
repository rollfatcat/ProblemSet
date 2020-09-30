/* 給定Ｎ位同學(編號１到Ｎ)和Ｍ段關係，輸出不同的宗教個數(群數)？
 * 關係(Ａ,Ｂ) 代表編號Ａ和編號Ｂ同學信奉同一個宗教，不存在關係＝信奉不同宗教
 * 解題關鍵：查並集
 * 注意事項：輸入結束並不是０,０而是 EOF
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=5e4;
int root[MaxN+1];
 
int FindRoot(int x){ 
	return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
int main(){
	int N, M, u, v;
	for(int caseI=1;scanf("%d %d\n",&N,&M)!=EOF;caseI++){
		for(int i=1;i<=N;i++)
      root[i]=i;

		int Group=N;
		while(M-->0){
			scanf("%d %d\n",&u,&v);
			int root_u=FindRoot(u);
			int root_v=FindRoot(v);
			if(root_u==root_v) continue;
			root[root_v]=root_u;
			Group--;
		}
		printf("Case %d: %d\n",caseI,Group);
	}
}