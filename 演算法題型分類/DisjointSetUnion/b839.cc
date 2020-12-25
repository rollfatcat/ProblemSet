/* 給定Ｎ個字串，若２個字串相似視為同一個種類，輸出成員數最多種類的成員個數？
 * 相似：兩個字串的 LCS 長度大於等於 兩個字串長度較短的一半
 * 解題關鍵：DSU + LCS
 * 枚舉任意２個字串，若２者並非同一個群體但相似時就做 Union
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=3;
const int MaxN=50;
const int MaxL=50;

char ss[MaxN][MaxL+2];
int dp[2][MaxL+2];
int root[MaxN];
int size[MaxN];
int FindRoot(int x){ 
	return (root[x]==x)? x:root[x]=FindRoot(root[x]);  }
bool has_relation(int a,int b){
	int La=strlen(ss[a]);
	int Lb=strlen(ss[b]);
	for(int i=0;i<=La;i++)
		dp[0][i]=0;
	bool now=0, pre=1;
	for(int i=0; i<Lb; i++){
		swap(now,pre);
		for(int j=0; j<La; j++)
			dp[now][j+1]=max( max(dp[pre][j+1],dp[now][j]),dp[pre][j]+(ss[b][i]==ss[a][j]) );
	}
	return min(La,Lb)<=(dp[now][La]<<1);
}

int main(){
	int caseT, N;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d\n",&N);
		for(int u=0; u<N; u++)
			root[u]=u, 
      size[u]=1;
		int maxSize=0;
		for(int u=0; u<N; u++){
			scanf("%s\n",ss[u]);
			for(int v=0; v<u; v++){
				int Ru=FindRoot(u);
				int Rv=FindRoot(v);
				if( Ru!=Rv and has_relation(u,v) )
					root[Rv]=Ru, 
					size[Ru]+=size[Rv],
					maxSize=max(maxSize,size[Ru]);
			}
		}
		printf("%d\n",maxSize);
	}
}