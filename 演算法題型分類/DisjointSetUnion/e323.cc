/* 給定奶酪的高度Ｈ和半徑是Ｒ的Ｎ個三維的圓中心點座標形成的中空圓球，輸出是否可以透過中空的圓球從下面抵達上面？
 * 兩個圓球或是圓球與上下平線的連通條件為 相交 或是 相切
 * 解題關鍵：DisjointSetUnion( 連通＝connection )
 * 實作細節：座標雖然可以用 int 紀錄，但在計算兩點之間的距離時需要 unsigned long 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=20;
const int MaxN=1e3;
const int MaxR=1e9;

int node[MaxN][3];
int root[MaxN+2];
int FindRoot(int x){
	return root[x]==x ? x: root[x]=FindRoot(root[x]); }
void Union(int a,int b){
	int Ra=FindRoot(a);
	int Rb=FindRoot(b);
	if(Ra==Rb) return;
	root[Rb]=Ra;
}
unsigned long DIS(long dx,long dy,long dz){ return (unsigned long)(dx*dx)+(unsigned long)(dy*dy)+(unsigned long)(dz*dz); }
bool way(int a,int b,unsigned long R){
	return DIS(node[a][0]-node[b][0],node[a][1]-node[b][1],node[a][2]-node[b][2])<=(R*R<<2); }
int main(){
	int caseT, N, H, R;
	
	scanf("%d",&caseT);
	while(caseT-->0){
		scanf("%d %d %d",&N,&H,&R);
		for(int i=0;i<N;i+=1)
			scanf("%d %d %d",&node[i][0],&node[i][1],&node[i][2]);
		//
		for(int i=0;i<=N+1;i+=1)
			root[i]=i;
		for(int i=0;i<N and FindRoot(N)!=FindRoot(N+1);i+=1){
			if(node[i][2]<=R) 
				Union(N,i);
			if(node[i][2]>=H-R) 
				Union(N+1,i);
			for(int j=i-1; j>=0; j-=1)
				if( way(i,j,R) )
					Union(i,j);
		}
		//
		puts( FindRoot(N)==FindRoot(N+1)? "Yes":"No" );
	}
}