// 題解：https://blog.ototot.tk/2017/01/tioj-1228-phh.html
// 將樹壓平(DFS遍歷順序)，同時紀錄落在以目前點為起點的區間內所有號碼的邊
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000001;
int N, idx;

struct NODE{
  int n, v;
  NODE(int a=0,int b=0):n(a),v(b){}
};
vector<NODE> tree[MAXN];
struct DIAN{ int nL,nR; } dianMap[MAXN]; // (nL,nR)的意義代表有效邊的範圍從nL+1到nR之間
int bianMap[MAXN]; // 對應到達子節點的邊號碼(樹架構的關係每個節點只存在一個父節點)
int org[MAXN]; // 根據DFS遍歷整棵樹時分配權重邊的順序
int BIT[MAXN]; //

inline int lowbit(int x){ return x&-x; }
void foldTree(int now){
  dianMap[now].nL=idx;
  for(int i=0;i<tree[now].size();i++){
    bianMap[ tree[now][i].n ]=++idx,  //<- 先加加代表等下從這個號碼以後都是區間範圍
		org[idx]=tree[now][i].v,
		foldTree(tree[now][i].n);
  }
  dianMap[now].nR=idx;
}
inline int query(int x,int out=0){
  for(;x;x-=lowbit(x))
    out+=BIT[x];
  return out;
}
int main(){
  int Q, a, b, v;
  scanf("%d %d",&N,&Q);
  for(int i=1;i<N;i++)
    scanf("%d %d %d",&a,&b,&v),
    tree[a].push_back(NODE(b,v));
  idx=0, foldTree(0);

  // Built FenwickTree
  for(int i=1;i<=idx;i++)
    for(int j=i;j<N;j+=lowbit(j)) // idx=N-1(樹狀架構時邊數一定是點數減一)
      BIT[j]+=org[i];
  // React to Query
  int act, now;
  while(Q--){
		scanf("%d %d",&act,&now);
		if(act){ // 信件來回所以區間加總的成本需要兩倍
			int ans=query(dianMap[now].nR)-query(dianMap[now].nL);
			printf("%d\n",ans<<1);
		}else{
			scanf("%d",&v);
			// update BIT and org[]，注意需要先將位置轉換為DFS遍歷時的順序號碼
			for(int x=bianMap[now];x<N;x+=lowbit(x))
			  BIT[x]+=v-org[ bianMap[now] ];
			org[ bianMap[now] ]=v;
		}
	}
}
/*
7 6
0 1 4
1 2 7
1 3 12
2 4 8
2 5 11
3 6 8
0 2 11
1 5
0 3 7
1 2
0 4 2
1 3
*/