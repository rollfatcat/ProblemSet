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

const int INF=1<<30;
const int MaxC=1e2;
const int MaxS=1e3;
const int MaxQ=1e4;
struct PATH{
	int a, b, v;
	PATH(int a=0,int b=0,int v=0):a(a),b(b),v(v){}
	bool operator<(const PATH &rhs)const{ return v<rhs.v; }
}path[MaxS];

int root[MaxC+1];
int load[MaxC+1][MaxC+1];
vector<int> mebr[MaxC+1];

int GetRoot(int x){ return (root[x]==x)? x: GetRoot(root[x]); }
int main(){
  int C, S, N, Q;
  for(int caseI=1;scanf("%d %d %d\n",&C,&S,&Q) and C; caseI++){
    for(int i=1;i<=C;i++){
    	root[i]=i, mebr[i].assign(1,i);
    	for(int j=1;j<=C;j++)
    		load[i][j]=INF;
    }
    for(int i=0;i<S;i++)
      scanf("%d %d %d\n",&path[i].a,&path[i].b,&path[i].v);
    sort(path,path+S);
    N=0;
    for(int i=0;i<S;i++){
    	int Ra=GetRoot(path[i].a);
    	int Rb=GetRoot(path[i].b);
    	if(Ra==Rb) continue;
    	root[Rb]=Ra;
    	for(int b:mebr[Rb])
    		for(int a:mebr[Ra])
    			load[a][b]=load[b][a]=path[i].v;
    	for(int b:mebr[Rb])
    		mebr[Ra].emplace_back(b);
    	if(N++==C-1) break;
    }
    if(caseI>1) putchar('\n');
    printf("Case #%d\n",caseI);
    for(int a,b;Q--;)
      scanf("%d %d\n",&a,&b),
      (load[a][b]==INF)?puts("no path"):printf("%d\n",load[a][b]);
  }
}