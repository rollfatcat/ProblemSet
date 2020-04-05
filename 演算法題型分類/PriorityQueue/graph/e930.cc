/* Dijkstra變形版：第一次走到的點一定是最低 Cost，之後再次走到就不更新(此時並未考慮最低成本時的步數)
 * 需要考慮從Ａ走到Ｂ時不同的步數時的最低 Cost
 * 因為 #nodeｘMaxK＝1e7，避免記憶體需求過大和初始化時間過長。
 * 代價：同樣步數的情況下不會採計『最低成本』而產生重複展開。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxM=1e6;
const int INF=1<<30;
struct DATA{
	int node, step, cost;
	DATA(int n=0,int s=0,int c=0):node(n),step(s),cost(c){}
	inline bool operator<(const DATA &rhs)const{ return cost>rhs.cost; }
};
struct PATH{ 
	int t, w; 
	PATH(int t=0,int w=0):t(t),w(w){}
};

vector<PATH> to[MaxN];
int main(){
	int N, M, K, u, v, w;
	scanf("%d %d %d\n",&N,&M,&K);
	// 路徑是單向道
	for(int i=0;i<M;i++)
		scanf("%d %d %d\n",&u,&v,&w),
		to[u].push_back(PATH(v,w));
	bool GetThePath=0;
	priority_queue<DATA,vector<DATA>>PQ;
	for(PQ.push(DATA()); PQ.empty()==0; PQ.pop()){
		DATA now=PQ.top();
		if(now.node==N-1){ printf("%d\n",now.cost); GetThePath=1; break; }
		if(now.step==K) continue;
		for(PATH nxt:to[now.node])
			PQ.push(DATA(nxt.t,now.step+1,now.cost+nxt.w));
	}
	if(GetThePath==0) puts("impossible");
}