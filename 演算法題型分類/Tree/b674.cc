/* 給定Ｎ條「有向邊」(但點的編號不一定是１-Ｎ)，輸出是否為一棵樹？
 * 提示：確認一個組有向邊是否成為樹，下列３點需要都成立：
 * 1.邊的數量是否為點的數量減一
 * 2.不存在循環路徑(cycle)
 * 3.所有的點一值追尋其父點都會找到同一點,也就是root
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxNode=1e3+1;
/* 懶惰標記：只有這個點的 caseID 不是目前的 case 編號時才需要重置 */
int lazy[MaxNode]={};
int root[MaxNode];
/* 路徑壓縮 */
int FindRoot(int x){ 
	if(root[x]!=x) root[x]=FindRoot(root[x]);
	return root[x]; 
}

int main(){
  int edge_cnt, u, v;
  int caseI=0;
  while(scanf("%d\n",&edge_cnt) and edge_cnt>0){
  	caseI++;
  	int node_cnt=0;
  	bool twoRoot=0;
  	for(int i=0;i<edge_cnt;i++){
  		scanf("%d %d",&u,&v);
  		/* Lazy Update */
      if(lazy[u]<caseI) lazy[u]=caseI, root[u]=u, node_cnt+=1;
  		if(lazy[v]<caseI) lazy[v]=caseI, root[v]=v, node_cnt+=1;
  		/* 檢查：ｖ的父節點已經指向其他點 或是 存在一條邊自己指向自己
       * 檢查條件未觸發時ｖ的父節點指向ｕ的根節點 
       */
  		twoRoot|= u==v or root[v]!=v;
  		root[v]=FindRoot(u);
  	}
  	/* 確認所有人都指向同一個父節點(根節點是唯一的) */
  	for(v=1;v<MaxNode and lazy[v]<caseI;v++);
  	u=FindRoot(v);
  	for(v++;v<MaxNode;v++)
  		if(lazy[v]==caseI)
  			twoRoot|= FindRoot(v)!=u;

  	puts( (node_cnt!=edge_cnt+1 or twoRoot)? "n":"y" );
  }
}