/* 給定一張無向圖Ｇ(Ｎ個點和Ｍ條無向邊)，若題目給定的圖可以作為二分圖分割則輸出需要塗黑的最少點數？
 * 解題關鍵：DSU on 二分圖分割
 * 相鄰的點＝設定為敵對關係，若過程中有衝突＝無法形成二分圖
 * 窮舉每一群(敵我)取人數最多的那群後把敵我兩群合併為一，避免重複計算
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e5;
const int MaxM=1e6;
int root[MaxN<<1|1];
int size[MaxN+1];
 
int FindRoot(int x){ 
	return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
int main(){
	int N, M, u, v;
	while(scanf("%d %d\n",&N,&M)!=EOF){
		/* 初始化 */
		for(int i=1;i<=N;i++){
			root[i]=i;
			root[N+i]=N+i;
			size[i]=0;
		}
		bool safe=1;
		while(M-->0){
			scanf("%d %d\n",&u,&v);
			int Ru=FindRoot(u);
			int Rv=FindRoot(v);
			int Eu=FindRoot(u+N);
			int Ev=FindRoot(v+N);
			if(Ru==Ev){ continue; }
			if(Ru==Rv){ safe=0; break; }
			if(Ev>Ru) swap(Ev,Ru); root[Ru]=Ev;
			if(Eu>Rv) swap(Eu,Rv); root[Rv]=Eu;
		}
		while(M-->0)
			scanf("%d %d\n",&u,&v);
		if(safe==0){ puts("0"); continue; }
		/* 設定完所有關係，確認不存在矛盾(可以拆解為二分圖後統計每一群的人數) */
		for(int i=1;i<=N;i++)
			size[FindRoot(i)]+=1;
		/* 窮舉每一群(敵我)取人數最多的那群後把敵我兩群合併為一，群避免重複計算 */
		int cnt=0; 
		for(int ths=1; ths<=N; ths++)
			if(FindRoot(ths)==ths){
				int rhs=FindRoot(ths+N);
				cnt+=min(size[ths],size[rhs]);
				root[rhs]=ths;
			}
		printf("%d\n",cnt);
	}
}