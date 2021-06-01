/* 給定Ｎ位士兵的身高，將士兵依照身高低到高排序，每次喊到號碼的士兵要報出隊伍內自己左右鄰兵的號碼後出列(離開隊伍)。
 * 題目保證：士兵的編號１-Ｎ且每位士兵的身高都不一樣
 * 解題關鍵：Sort＋DSU
 * 		題目輸入的是士兵編號，模擬時編號要依照身高排序，所以要做反向映射(編號 → 隊伍位置)
 * 		離開隊伍的士兵＝這個編號指到左側的編號 root 和右側 root ，利用" DSU 連通"的概念應用到"移除"  
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=3e5;
int num[MaxN+1];
int ord[MaxN+1];
int rvs[MaxN+1];
int Lrt[MaxN+1];
int Rrt[MaxN+1];
 
 
bool compare(int a,int b){ return num[a]<num[b]; }
int FindRoot(int x,int *root){
	return (root[x]==x)? x: root[x]=FindRoot(root[x],root); }
 
int main(){
	int N, Q, v;
	scanf("%d %d\n",&N,&Q);
 
	for(int i=1;i<=N;i++){
		scanf("%d",&num[i]);
		ord[i]=Lrt[i]=Rrt[i]=i; // init for Sort & DSU 
	}	 
	sort(ord+1,ord+N+1,compare); // sort by height
	for(int i=1;i<=N;i++) // reverse mapping : ID to pos in array
		rvs[ ord[i] ]=i;
 
	while(Q-->0){
		scanf("%d\n",&v);
		v=rvs[v];
		int Lroot=FindRoot(v-1,Lrt);	
		int Rroot=FindRoot(v+1,Rrt);
		printf("%d %d %d\n",v,ord[Lroot],ord[Rroot]);
		Lrt[v]=Lroot;
		Rrt[v]=Rroot;
	}
}