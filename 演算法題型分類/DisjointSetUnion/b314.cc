/* 給定Ｒ×Ｃ的地圖和Ｎ個陷阱座標，當給定新的陷阱時是否違反「規則」輸出對應的字串和是否放入新陷阱？
 * 規則：放入新陷阱後會導致無法從左側移動(上下左右)到右側時輸出 >_<，並且這個陷阱視為不存在，反之輸出 <(_ _)> 並記錄。
 * 題目保證每個陷阱座標最多只會被放一次，且陷阱的座標範圍(X,Y)落在(0,1000)內。
 * 解題關鍵：狀態設定，查並集
 * 無法從左側移動(上下左右)到右側＝新放入陷阱後導致上下連通 ... 如何偵測上下連通？
 *    新的陷阱座標周圍８格內存在其他陷阱(至少一個連通上、一個連通下 ... 查並集偵測該座標的陷阱屬於哪個群？)
 *    狀態設定：周圍的陷阱需要紀錄屬於哪個群(若該格子不存在陷阱，群的編號＝-1) ... Ｏ(1)的 check
 * 放入新陷阱後要將不同的群做 Union 。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxR=1e3;
const int MaxC=1e3;
const int MaxN=1e6;
int toID[MaxR][MaxC];
int root[MaxN];
int R, C, N;

/* 檢測該陷阱屬於哪群 */
inline int FindRoot(int now){ 
	return (root[now]==now)? now: root[now]=FindRoot(root[now]);}
/* 周圍８格位置的偏移量和該位置找到的群 */
int dx[8]={-1,-1,-1, 0, 0, 1, 1, 1};
int dy[8]={-1, 0, 1,-1, 1,-1, 0, 1};
int neighbor[8];

/* 先處理超過邊界的情況：(1)(2)(3)，再根據位置是否存在其他陷阱做討論：
 * 指向自己是因為做 Union 時不會觸發。
 * (1)超過左右邊界＝該格不存在＝指向自己
 * (2)超過上界＝該格與上界連通＝指向０(代表上界)
 * (3)超過下界＝該格與下界連通＝指向１(代表下界)
 * (4)位置未超過邊界時檢查這個座標是否存在其他陷阱，是則輸出該陷阱代表的群，否則指向自己。
 */
inline int GetID(int x,int y,int nowID){
	if(y==-1 or y==C) return nowID;
	if(x==-1) return 0;
	if(x==R)  return 1;
	return (toID[x][y]==-1)? nowID: FindRoot(toID[x][y]);
}
/* 優先偵測：放係新陷阱座標時是否會導致上下連通＝周圍８格的位置存在至少一個陷阱屬於上界且一個屬於下界
 * 若會導致上下連通則該陷阱不能存在＝回傳 false 代表該行為失敗
 * 若上述情況不存在，則該陷阱可以存在：這個座標標記為該陷阱的 ID 且將周圍８格不同的群做合併。
 *    合併時以 ID 較小者為主，所以設定 Top＝０、Down＝１，出現順序越優先的陷阱能合併到的陷阱數量較多。
 */
inline bool CanPut(int x,int y,int nowID){
	bool connect_top =0;
	bool connect_down=0;
	for(int i=0;i<8;i++){
		neighbor[i]=GetID( x+dx[i], y+dy[i], nowID);
		connect_top |= neighbor[i]==0;
		connect_down|= neighbor[i]==1;
	}
	if(connect_top and connect_down) return false;
	toID[x][y]=nowID;
	root[nowID]=nowID;
	for(int i=0;i<8;i++){
		int root_a=FindRoot(nowID);
		int root_b=FindRoot(neighbor[i]);
		if(root_a==root_b) continue;
		(root_a<root_b)? root[root_b]=root_a: root[root_a]=root_b;
	}
	return true;
}
int main(){
	int x, y;
	root[0]=0; 
	root[1]=1;
	while(scanf("%d %d %d\n",&R,&C,&N)!=EOF){
		/* 初始化每格座標(該陷阱屬於群的編號)＝-1代表不存在陷阱 */
    for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				toID[i][j]=-1;
    /* 因為０代表上界的群、１代表下界的群，所以放入的陷阱 ID 從２開始計算 */
		for(int nowID=2; N>0; N--){
			scanf("%d %d\n",&x,&y);
			bool success=CanPut(x,y,nowID);
			puts( success ?"<(_ _)>":">_<");
			nowID+=success;
		}
	}
}