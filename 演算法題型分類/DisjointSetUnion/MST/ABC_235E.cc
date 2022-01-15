#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxQ=2e5;

struct EDGE{
	int a, b, c, o;
	EDGE(int a=0,int b=0,int c=0,int o=0):a(a),b(b),c(c),o(o){}
	bool operator<(const EDGE &rhs)const{
		return c<rhs.c; }
} edge[MaxN+MaxQ];
bool ans[MaxQ];
int root[MaxN+1];
int FindRoot(int x){
	return (root[x]==x)? x: root[x]=FindRoot(root[x]); }

int main(){
	int N, M, Q, a, b, c;
	
	scanf("%d %d %d",&N,&M,&Q);
	for(int m=0; m<M; m+=1){
		scanf("%d %d %d",&a,&b,&c);
		edge[Q+m]=EDGE(a,b,c,Q);
	}
	for(int q=0; q<Q; q+=1){
		scanf("%d %d %d",&a,&b,&c);
		edge[q]=EDGE(a,b,c,q);
	}
	sort(edge,edge+M+Q);
	iota(root,root+N+1,0);
	for(int q=0; q<M+Q; q+=1){
		int Ra=FindRoot(edge[q].a);
		int Rb=FindRoot(edge[q].b);
		if(edge[q].o<Q){
			ans[edge[q].o]= Ra!=Rb;
		}else if(edge[q].o==Q and Ra!=Rb){
			root[Rb]=Ra;
		}
	}
	for(int q=0; q<Q; q+=1)
		puts( (ans[q])?"Yes":"No");
}