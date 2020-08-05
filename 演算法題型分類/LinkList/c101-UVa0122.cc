/* 給定數個節點( 停止條件：讀取的字串是"()" )，若該樹是合法的依照BFS順序輸出節點的數值。
 * 節點給定的方式為（ 節點數值(正整數)，路徑 ），走訪路徑時需要注意建構樹的節點不一定存在。
 * 合法：不存在有節點沒有數值(為０)且沒有任意兩個節點存在相同路徑，前者在做BFS拜訪時可以同時偵測到，
 *      後者則是每根據路徑更新一個節點時注意是否路徑尾端的節點數值＝０。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxNode=256;
bool NewTree;
char ss[300];

struct NODE{
	int v;
	NODE *L;
	NODE *R;
	NODE(int v=0):v(v),L(nullptr),R(nullptr){}
} *root;

inline void DeCode(int idx=0,int v=0,NODE* now=root){
	for(;ss[++idx]!=',';v=10*v+(ss[idx]-'0') );
	for(;ss[++idx]!=')';now=(ss[idx]=='L')?now->L:now->R){
		/* 確認等下移動過去的節點存在 */
        if(ss[idx]=='L' and !now->L)
			now->L=new NODE();
		if(ss[idx]=='R' and !now->R)
			now->R=new NODE();
	}
	NewTree &=(now->v==0);
	now->v=v;
}

void BFSTree(vector<int> &ans){
	queue<NODE*> Q;
	Q.push(root);
	while(Q.empty()==0){
		NODE* now=Q.front(); Q.pop();
		if(now->v==0){
			NewTree=0; break; 
		}else
			ans.push_back(now->v);
		if(now->L) Q.push(now->L);
		if(now->R) Q.push(now->R);
	}
}
int main(){
	while(scanf("%s",ss)!=EOF){
		NewTree=1;
		root=new NODE();
		for(DeCode();scanf("%s",ss)!=EOF and ss[1]!=')';DeCode());
		vector<int> ans;
		BFSTree(ans);
		if(NewTree==0) 
			puts("not complete");
		else{
			printf("%d",ans[0]);
			for(int i=1;i<ans.size();i++)
				printf(" %d",ans[i]);
			putchar('\n');
		}
	}
}

