/* 給定Ｒ×Ｃ的地圖和Ｎ個地雷，在「引爆規則」下輸出最少需要的誘導彈數量？
 * 引爆規則：地雷Ａ可以引爆地雷Ｂ＝地雷Ａ的周圍８格和地雷Ｂ的周圍８有重疊部分＝地雷Ａ為中心的周圍２５格內存在地雷Ｂ 
 * 解題關鍵：map＋查並集
 * 題目盲點：地圖最大是 10000×10000 所以紀錄時不能直接宣告這個大小的陣列，而是枚舉Ｒ建立只存在的Ｃ和對應的群
 * 將周圍２５格內不同的群合併成同一群(以編號較小者為主)
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxR=1e4;
const int MaxC=1e4;
const int MaxN=5e4; // TIOJ 才有保證
 
vector<int> root;
map<int,int> toID[MaxR+1]; // toID[x][y]紀錄這個地雷屬於哪一群？
int R, C;
int FindRoot(int x){ 
	return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
/* 該座標超過範圍 或是 該座標不存在地雷時回傳 nowID 否則回傳代表該座標地雷的群編號 */
int GetID(int x,int y,int ID){
	if(x<=0 or x>R) return ID;
	if(y<=0 or y>C) return ID;
	if(toID[x].size()==0) return ID;
	return (toID[x].find(y)==toID[x].end())? ID:FindRoot(toID[x][y]);
}
int main(){
	int N, x, y;
	while(scanf("%d %d %d\n",&R,&C,&N)!=EOF){
		/* 初始化 */
		for(int i=1;i<=R;i++) 
			toID[i].clear();
		root.resize(N);

		for(int nowID=0; nowID<N; nowID++){
			root[nowID]=nowID;
			scanf("%d %d\n",&x,&y);
			/* 偵測周圍的２５格是否有地雷存在？ */
			for(int dx=-2;dx<=2;dx++)
				for(int dy=-2;dy<=2;dy++){
					int root_neighbor=GetID(x+dx, y+dy, nowID);
					int root_now=FindRoot(nowID);
					if(root_now==root_neighbor) continue;
					(root_now<root_neighbor)? root[root_neighbor]=root_now:root[root_now]=root_neighbor;
				}
			/* 新增這個座標的地雷 */
			toID[x][y]=FindRoot(nowID);
		}
		/* 計算有幾個群(代表群的編號＝自己的編號)？ */
		int ans_cnt=0;
		for(int nowID=0; nowID<N; nowID++)
			ans_cnt+= root[nowID]==nowID;
		printf("%d\n",ans_cnt);
	}
}