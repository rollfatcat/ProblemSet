/* 給定Ｃ個點和Ｓ條無向路徑，查詢Ｑ次
 * 給定的無向路徑(Ｃ1,Ｃ2,d)代表兩點間的噪音分貝，
 * 查詢會給定兩點，輸出最小化路徑上需要忍受最大分貝的負荷程度(可能存在無法抵達時則輸出"no path")。
 * Minimal Spanning Tree( Kruskal )
 * 將路徑依照噪音分貝由小到大排序，每次選取當前最小噪音的路徑。
 * 因為這條新加入路徑讓屬於不同群體的兩端點形成連通時代表分屬該路徑的噪音分貝是兩端點的最低承受度。 
 * 並歸類為同一群體。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxC=1e2;
const int MaxS=1e3;
const int MaxQ=1e4;

struct EDGE{
	int a, b, v;
} edge[MaxS];
int root[MaxC+1];
int cost[MaxC+1][MaxC+1];
vector<int> mebr[MaxC+1];

bool compare(EDGE a,EDGE b){ return a.v<b.v; }
int FindRoot(int x){ 
	return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
int main(){
	int C, S, Q, a, b;
	for(int caseI=1;scanf("%d %d %d\n",&C,&S,&Q) and C>0;caseI++){
		for(int i=1;i<=C;i++){
			fill(cost[i],cost[i]+C+1,INT_MAX);
			cost[i][i]=0;
			root[i]=i;
			mebr[i].assign(1,i);
		}
		for(int i=0;i<S;i++)
			scanf("%d %d %d\n",&edge[i].a,&edge[i].b,&edge[i].v);
		sort(edge,edge+S,compare);
		for(int i=0,e=0;i<S;i++){
			int Ra=FindRoot(edge[i].a);
			int Rb=FindRoot(edge[i].b);
			if(Ra==Rb) continue;
			for(int ca: mebr[Ra])
				for(int cb: mebr[Rb])
					cost[ca][cb]=cost[cb][ca]=edge[i].v;
			
			root[Rb]=Ra;
			for(int cb: mebr[Rb])
				mebr[Ra].push_back(cb);
			if(++e==C-1)
				break;
		}
		printf("Case #%d\n",caseI);
		while(Q-->0)
			scanf("%d %d\n",&a,&b),
			(cost[a][b]==INT_MAX)? puts("no path"): printf("%d\n",cost[a][b]);
		putchar('\n');
	}
} 
