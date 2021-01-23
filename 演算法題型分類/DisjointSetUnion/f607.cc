/* 給定Ｎ個切點座標和順序，每次裁切的成本為當前線段長度，輸出過程當中的成本總和？
 * 題目盲點：BinarySearchTree worst-case
 *      依照題目給予的"規則"根據順序模擬切點，並找到該線段左右端點做累加 ... O(n^2)。
 *      需要知道已經存在的切點當中 最大且小於 cut[i] 的座標和最小且大於 cut[i] 的座標，之後將該節點加入切點的集合中。
 * 解題關鍵： Discretization + DSU
 *      離散化處理切點座標
 *      照順序的切點＝反順序的連接，DSU尋找當下切點的左右端點
 *      計算完後將該節點右 root 指向右側端點的 root，左 root 指向左側端點的 root
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxL=1e7;

int cut[MaxN+2];
int pos[MaxN+2];
int Lrt[MaxN+2];
int Rrt[MaxN+2];
int FindRoot(int x,int* root){
	return (root[x]==x)? x: root[x]=FindRoot(root[x],root);
}
int main(){
	int N, L, p, o;
	scanf("%d %d\n",&N,&L);
	
	for(int i=1;i<=N;i++){
		scanf("%d %d\n",&p,&o);
		pos[i]=cut[o]=p;
		Lrt[i]=Rrt[i]=i; // init for DSU
	}
	
	sort(pos+1,pos+N+1); // for Discretization
	pos[0]=0;   Lrt[0]=Rrt[0]=0; 
	pos[N+1]=L; Lrt[N+1]=Rrt[N+1]=N+1;
	long ansL=0;
	for(int i=N; i>0; i--){
		p=lower_bound(pos,pos+N+1,cut[i])-pos; // 離散化
		int toL=FindRoot(p-1,Lrt); // 找到目前節點"左側"
		int toR=FindRoot(p+1,Rrt); // 找到目前節點"右側"
		ansL+= pos[toR]-pos[toL];  // 計算「因為這個節點存在前」的左右邊界，轉換為離散化前的真實座標
		Lrt[p]=toL; // 將目前節點連接給他左端點的"root"
		Rrt[p]=toR; // 將目前節點連接給他右端點的"root"
	}
	printf("%d\n",ansL);
}