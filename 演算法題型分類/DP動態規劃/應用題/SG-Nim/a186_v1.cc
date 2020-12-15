/* 當存在３堆石頭時(每堆數量皆不超過２００個)，依照字典序輸出所有先手必輸的局面？
 * 解題關鍵：Nim( 動態規劃 )
 * 因為石頭數量比起 b588 時為２倍，所以描述的狀態為８倍，若要透過TopDown枚舉必定TLE
 * 該題目只能用 BottomUp 方式從必輸的局面(０,０,０)推導出其他也是必輸的局面。
 * 建議可以從 二維 的方式尋找規律後再類推到 三維 的作法( 需要搭配視覺化 )，以下描述為 二維 為例。
 * 目前狀態必輸，所以根據規則"延伸一步"(往右，往下，往右下)的其他狀態必贏
 * 而該狀態必輸是因為不存在能透過規則"縮回一步"(往左，往上，往左上)找到必輸的情況。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=201;
bool dp[MaxN][MaxN][MaxN]={};

int main(){
	/* Bottom-Up */
	for(int x=0;x<MaxN;x++)
		for(int y=0;y<MaxN;y++)
			for(int z=0;z<MaxN;z++)
				if(dp[x][y][z]==0){
					/* 只輸出遞增的狀態 */
                    if(x<=y and y<=z)
						printf("%d %d %d\n",x,y,z);
					for(int xS=x+1;xS<MaxN;xS++) dp[xS][y][z]=1;
					for(int yS=y+1;yS<MaxN;yS++) dp[x][yS][z]=1;
					for(int zS=z+1;zS<MaxN;zS++) dp[x][y][zS]=1;
					for(int i=1;i<MaxN-max(x,y);i++) dp[x+i][y+i][z]=1;
					for(int i=1;i<MaxN-max(x,z);i++) dp[x+i][y][z+i]=1;
					for(int i=1;i<MaxN-max(y,z);i++) dp[x][y+i][z+i]=1;
					for(int i=1;i<MaxN-max(x,max(y,z));i++) dp[x+i][y+i][z+i]=1;
				}
}
