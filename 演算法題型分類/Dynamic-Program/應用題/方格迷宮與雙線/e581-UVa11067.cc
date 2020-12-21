/* 經典動態規劃問題
 * 因為題目規定由(0,0)到達(w,h)且路徑只能向右和向上兩個方向
 * 狀態轉移：當這個格子沒有狼站在上面時, 這格的方法數＝左格＋上格
 * 實作時需要注意題目敘述的坐標和二維陣列的座標並不一致且方法數的最大值會超過int
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxW=100;
const int MaxH=100;
const int MaxN=100;
 
long cnt[MaxH+1][MaxW+1]; // 可能路徑數 ≤ 2^32 - 1
int main() {
	int W, H, N, x, y;
	while(scanf("%d %d",&W,&H) and W){
		memset(cnt,0,sizeof(cnt));
		for(scanf("%d",&N);N>0;N--){
			scanf("%d %d",&x,&y);
			cnt[x][y]=-1;
		}
		// 邊界設定
		cnt[0][0]=1;
		for(int i=1;i<=H;i++)
			cnt[0][i]=(cnt[0][i]==-1)? 0:cnt[0][i-1];
		for(int i=1;i<=W;i++)
			cnt[i][0]=(cnt[i][0]==-1)? 0:cnt[i-1][0];
		for(int i=1;i<=W;i++)
			for(int j=1;j<=H;j++)
				cnt[i][j]=(cnt[i][j]==-1)? 0: cnt[i-1][j]+cnt[i][j-1];
		if(cnt[W][H]>1) printf("There are %d paths from Little Red Riding Hood's house to her grandmother's house.\n",cnt[W][H]);
		else if(cnt[W][H]==1) puts("There is one path from Little Red Riding Hood's house to her grandmother's house.");
		else puts("There is no path.");
	}
}