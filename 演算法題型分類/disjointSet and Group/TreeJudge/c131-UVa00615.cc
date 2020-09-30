/* 給定數條(並未告知邊數但有明確該筆測資停止條件)「有向邊」(但點的編號不一定是１-Ｎ)，輸出是否為一棵樹？
 * 提示：確認一個組有向邊是否成為樹，下列３點需要都成立：
 * 1.邊的數量是否為點的數量減一
 * 2.不存在循環路徑(cycle)
 * 3.所有的點一值追尋其父點都會找到同一點,也就是root
 */
#include<bits/stdc++.h>
using namespace std;

struct EDGE{
	int u, v;
	EDGE(int u=0,int v=0):u(u),v(v){}
};
vector<EDGE> edge;
vector<int> node;
vector<int> root;
/* 路徑壓縮版本 */
int FindRoot(int x){
	if(root[x]!=x)
		root[x]=FindRoot(root[x]);
	return root[x];
}

int main(){
	int node_cnt, u, v;
	for(int caseI=1;scanf("%d %d",&u,&v)!=EOF;caseI++){
		/* 若輸入的第一組有向邊編號＝(-1,-1)時代表全部輸入結束 */
        if(u==-1 and v==-1) 
			break;
		edge.clear();
		node.clear();
		/* 最後一組測資＝(０,０)時代表輸入這筆結束 */
        while(u!=0 and v!=0){
			edge.push_back( EDGE(u,v) );
			node.push_back(u);
			node.push_back(v);
			scanf("%d %d",&u,&v);
		}
		/* 離散化 */
		sort(node.begin(),node.end());
		node_cnt=unique(node.begin(),node.end())-node.begin();
		root.resize(node_cnt,0);
		for(int i=0;i<node_cnt;i++)
			root[i]=i;
		/* 將「有向邊」的點透過離散化轉換為有序編號後 */
        bool twoRoot=0;
		for(EDGE now:edge){
			u=lower_bound(node.begin(),node.end(),now.u)-node.begin();
			v=lower_bound(node.begin(),node.end(),now.v)-node.begin();
            /* 檢查：ｖ的父節點已經指向其他點 或是 存在一條邊自己指向自己
             * 檢查條件未觸發時ｖ的父節點指向ｕ的根節點 
             */
			int root_u=FindRoot(u);
			twoRoot|=( u==v or root[v]!=v );
			root[v]=root_u;
		}
		/* 確認所有人都指向同一個父節點(根節點是唯一的) */
        if(node_cnt>0)
  		    u=FindRoot(0);
  	    for(v=1;v<node_cnt;v++)
  		    twoRoot|= FindRoot(v)!=u;
        /* 輸出，極端情況：點數＝０時視為符合樹架構 */
		printf("Case %d is ",caseI);
		if(node_cnt>0 and node_cnt!=edge.size()+1 or twoRoot)
			printf("%s ","not");
		puts("a tree.");
	}
}