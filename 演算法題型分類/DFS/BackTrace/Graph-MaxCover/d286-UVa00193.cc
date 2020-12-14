/* 給定Ｎ個點和Ｋ條邊，每個點可以選擇要不要塗黑但相鄰的點不可都是黑的，最大化塗黑點數和塗黑的號碼(最小字典序)？
 * 解題關鍵：DepthFirstSearch-CutBranch + Graph
 * 題型對比：BipartiteGraph，能形成二分圖時塗黑點數的最大覆蓋，不能則輸出０ ... DSU 可解但這題 DSU 不可。
 * 依據點的編號由小到大枚舉(為了快速收斂：塗黑優先於留白)
 * 剪枝：已經選取的點數＋這個點能否塗黑＋剩餘點數全部塗黑＞目前最多的塗黑點數，才需要呼叫遞迴繼續。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=100;
bool color[MaxN+1];
vector<int> to[MaxN+1];
int N, K;
 
void BackTrace(int now,vector<int> &ans,vector<int> &bag){
	if(now>N){ ans=bag; return; }
	
	/* 判斷這個點能不能塗黑 */ 
	bool can_color=true;
	for(int vx: to[now])
		can_color&= color[vx]==false;
	/* 這個點可以塗黑時，優先塗黑後呼叫遞迴 */
	if(can_color and bag.size()+N-now>=ans.size()){
		color[now]=1;
		bag.push_back(now);
		BackTrace(now+1,ans,bag);
		bag.pop_back();
		color[now]=0;
	}
	/* 該點不塗黑 */
	if(bag.size()+N-now>ans.size())
		BackTrace(now+1,ans,bag);
}
 
int main(){
	int caseT, u, v;
	scanf("%d",&caseT);
	while(caseT-->0){
		scanf("%d %d\n",&N,&K);
		for(int i=1;i<=N;i++)
			color[i]=0,
			to[i].clear();
		/* 遞迴時是依據編號小到大，編號大的點只需要檢查編號小的 */
		while(K-->0){
			scanf("%d %d\n",&u,&v);
			if(u>v) swap(u,v);
			to[v].push_back(u);
		}
 
		vector<int> ans;
		vector<int> bag;
		BackTrace(1,ans,bag);
 
		printf("%lu\n",ans.size());
		for(int vx:ans)
			printf("%d ",vx);
		putchar('\n');
	}
}