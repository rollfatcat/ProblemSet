/* 給定Ｎ點和Ｍ條邊，輸出能否將所有點拆分成二分圖？
 * 解題關鍵：DepthFirstSearch 
 * 題目沒有保證所有的點彼此聯通，需要枚舉所有未塗色的點當作起點，DFS 跑遍可以和該點聯通的其他點。
 * 每到一個新點時，設定該點的狀態為「走過」、標記「顏色」。
 *    檢查和該點有相連的其他點，若其他點已經走過時檢查顏色是否衝突，若沒走過則根據遞迴的結果決定是否提早結束？
 *    過程中確認無法拆分成二分圖時可以提早結束遞迴。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=200;
vector<int> to[MaxN];
bool clr[MaxN];
bool vis[MaxN];
 
bool DFS(int now_pos,int now_color){
	vis[now_pos]=1;
	clr[now_pos]=now_color;
	for(int vx:to[now_pos]){
		if( (vis[vx] and clr[vx]==now_color) )
			return false;
		if( vis[vx]==0 and DFS(vx,now_color^1)==0 )
			return false;
	}
	return true;
}
 
int main(){
	int N, M, u, v;
 
	while(scanf("%d\n",&N) and N>0){
		for(int i=0;i<N;i++){
			vis[i]=false;
			to[i].clear();
		}
		scanf("%d\n",&M);
		while(M-->0){
			scanf("%d %d\n",&u,&v);
			to[u].push_back(v);
			to[v].push_back(u);
		}

		bool CanBiColor=true;
		for(int i=0;i<N and CanBiColor;i++)
			if(vis[i]==0)
				CanBiColor=DFS(i,0);
		puts( CanBiColor?"BICOLORABLE.":"NOT BICOLORABLE." );
	}
}