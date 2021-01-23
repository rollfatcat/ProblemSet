/* 給定一張無向圖Ｇ(Ｎ個點和Ｍ條無向邊)，若題目給定的圖可以作為二分圖分割則輸出需要塗黑的最少點數？
 * 解題關鍵：DepthFirstSearch 
 * 題目對比：只有在二分圖成立時才需要輸出最少的覆蓋點數(相鄰的點不能同色)
 * 題目沒有保證所有的點彼此聯通，需要枚舉所有未塗色的點當作起點，DFS 跑遍可以和該點聯通的其他點。
 * 起點不一定會塗黑，只需要走遍整個聯通圖後統計兩種顏色的個數取較少者，所以一開始以代號，計算時也只要累加到正確的代號。
 * 每到一個新點時，設定該點的狀態為「走過」、標記「代號顏色」和「代號顏色」的個數加一。
 *    檢查和該點有相連的其他點，若其他點已經走過時檢查顏色是否衝突，若沒走過則根據遞迴的結果決定是否提早結束？
 *    過程中確認無法拆分成二分圖時可以提早結束遞迴。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e5;
const int MaxM=1e6;
vector<int> to[MaxN+1];
bool clr[MaxN+1];
bool vis[MaxN+1];
 
bool DFS(int now_pos,int now_color,vector<int> &color){
	vis[now_pos]=1;
	clr[now_pos]=now_color;
	color[now_color]+=1;
  /* 相鄰的點已經走過：檢查顏色是否相同(衝突)
   * 相鄰的點沒有走過：根據遞迴決定，失敗時直接回傳失敗否則繼續嘗試下一個相連的點
   */
	for(int vx:to[now_pos]){
		if( (vis[vx] and clr[vx]==now_color) ) 
			return false;
		if( vis[vx]==0 and DFS(vx,now_color^1,color)==0 )
			return false;
	}
	return true;
}
 
int main(){
	int N, M, u, v;
 
	while(scanf("%d %d\n",&N,&M)!=EOF){
		for(int i=1;i<=N;i++){
			vis[i]=false;
			to[i].clear();
		}
		while(M-->0){
			scanf("%d %d\n",&u,&v);
			to[u].push_back(v);
			to[v].push_back(u);
		}
 
		int ans=0;
		bool CanBiColor=true;
		for(int i=1;i<=N and CanBiColor;i++)
			if(vis[i]==0){
				vector<int> color(2);
				CanBiColor=DFS(i,0,color);
				ans+= min(color[0],color[1]);
			}
		printf("%d\n",(CanBiColor)? ans:0);
	}
}