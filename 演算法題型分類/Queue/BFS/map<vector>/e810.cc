/* 給定Ｎ個點、Ｍ個邊和起點/終點，問路徑上最大成本的最小化是多少？
 * Ｍinimal Spanning Tree（ＭST解），兩點連通＝兩點屬於同一群
 * 將每個邊依照cost由低到高排序，依次選取確認兩個端點是否屬於同一"群"
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e2;
const int MaxM=125e3;
const int MaxW=5e4;

struct EDGE{ 
	int a,b,v; 
	EDGE(int a=0,int b=0,int v=0):a(a),b(b),v(v){}
	bool operator<(const EDGE &rhs)const{ return v<rhs.v; }
} edge[MaxM];
int Grp[MaxN];

inline int GetRoot(int x){
	if(Grp[x]!=x) Grp[x]=GetRoot(Grp[x]); return Grp[x];
}
int main(){
	int N, M, st, ed, idx;
	while(scanf("%d %d\n",&N,&M)!=EOF){
		for(int i=0;i<M;i++)
			scanf("%d %d %d\n",&edge[i].a,&edge[i].b,&edge[i].v);
		scanf("%d %d\n",&st,&ed);
		for(int i=0;i<N;i++)
			Grp[i]=i;
		sort(edge,edge+M);
		for(idx=0;idx<M;idx++){
			int fa=GetRoot(edge[idx].a);
			int fb=GetRoot(edge[idx].b);
			if(fa==fb) continue;
			Grp[fb]=fa;
			if( GetRoot(st)==GetRoot(ed)) break;
		}
		printf("%d\n",(idx<M)? edge[idx].v: -1);
	}
}
