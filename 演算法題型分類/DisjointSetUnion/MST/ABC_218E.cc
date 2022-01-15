#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e5; // N = #vertex
const int MaxM=2e5; // M = #edge
const int MaxC=1e9;
 
struct EDGE{ int a, b, c; }edge[MaxM];
bool compare(EDGE lhs, EDGE rhs){
	return lhs.c<rhs.c; }
 
int root[MaxN+1];
int FindRoot(int x){
	return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
bool Union(int a,int b){
	int Ra=FindRoot(a);
	int Rb=FindRoot(b);
	if(Ra==Rb) return false;// a 和 b 屬於同一個 group
	root[Rb]=Ra;
	return true; // a 和 b 不屬於同一個 group
}
 
int main(){
	int N, M; //
 
	cin>>N>>M;
	for(int m=0; m<M; m+=1)
		cin>>edge[m].a>>edge[m].b>>edge[m].c;
	// sort by c
	sort(edge,edge+M,compare);
 
	// DSU for MST
	// init for DSU
	for(int n=1; n<=N; n+=1)
		root[n]=n;
	// DSU
	long ans=0;
	for(int m=0; m<M; m+=1)
		if( Union(edge[m].a,edge[m].b)==0 and 0<edge[m].c)
			ans+=edge[m].c;
 
	cout<<ans<<'\n';
 
}