#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=200;
int root[MaxN<<1|1];
 
int FindRoot(int x){ return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
 
int main(){
	int N, M, u, v;
	while(scanf("%d\n",&N) and N>0){
		scanf("%d\n",&M);
		for(int i=1;i<=N;i++){
			root[i]=i;
			root[N+i]=N+i;
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
		puts((safe)?"BICOLORABLE.":"NOT BICOLORABLE.");
	}
}