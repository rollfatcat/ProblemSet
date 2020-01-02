/* 標準 Minimal Spanning Tree 題目(Kruskal)
 * 題目雖然未提及城市的數量, 但路徑的城市以大寫字母代表＝數量≦26
 * 輸出時需要按照字典序, 意味著路徑排序時考量順序：費用,起點,終點
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=30;
struct PATH{
	int fr, to, v;
	PATH(int f=0,int t=0,int v=0):fr(f),to(t),v(v){}
	bool operator<(const PATH &rhs)const{
		if( v!=rhs.v)  return v<rhs.v;
		if(fr!=rhs.fr) return fr<rhs.fr;
		return to<rhs.to;
	}
};
vector<int> pat(MaxN);
inline int Find(int x){
	return (pat[x]!=x)?  pat[x]=Find(pat[x]): pat[x];
}

int main(){
	int caseT;
	int N;
	int cost;
	char ch;
	scanf("%d\n",&caseT);
	for(int caseI=1;caseI<=caseT;caseI++){
		scanf("%d\n",&N);
		vector<PATH> path;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				scanf("%d",&cost);
				if(i<j and cost)  path.push_back(PATH(i,j,cost));
				if(j<N-1) scanf("%c",&ch);
			}
		}
		sort(path.begin(),path.end());
		//
		for(int i=0;i<N;i++) 
			pat[i]=i;
		int cnt=0;
		printf("Case %d:\n",caseI);
		for(PATH now:path){
			int Pf=Find(now.fr);
			int Pt=Find(now.to);
			if(Pf==Pt) continue;
			printf("%c-%c %d\n",now.fr+'A',now.to+'A',now.v);
			pat[Pt]=Pf;
			if(++cnt==N-1) break;
		}
	
	}
}