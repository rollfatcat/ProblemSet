/* 給定初始時３堆石頭的數量，依照規則問先手玩家的結果是贏還是輸？
 * 規則：玩家可以從３堆石頭至少任選一堆取最少一顆石頭。
 * 解題關鍵：Nim( 動態規劃 )
 * 初始狀態：(０,０,０) ＝當玩家面臨該狀態時必輸
 * 所有狀態：必輸/存在贏的局面(０/１)
 * 狀態轉移：只有當目前狀態是必輸時才需要做延伸：只要將下位玩家要面臨的局面變成必輸則目前玩家會贏
 *         根據規則延伸的下個狀態會贏＝至少存在一個當前必輸的狀態。
 * Ｂottom-Up | 7ms
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=101;
bool dp[MaxN][MaxN][MaxN]={};

int main(){
	/* Bottom-Up：由目前的狀態是輸時，代表能延伸的下個狀態存在會贏的情況 */
	for(int x=0;x<MaxN;x++)
		for(int y=0;y<MaxN;y++)
			for(int z=0;z<MaxN;z++)
				if(dp[x][y][z]==0){
					for(int xS=x+1;xS<MaxN;xS++) dp[xS][y][z]=1;
					for(int yS=y+1;yS<MaxN;yS++) dp[x][yS][z]=1;
					for(int zS=z+1;zS<MaxN;zS++) dp[x][y][zS]=1;
					for(int i=1;i<MaxN-max(x,y);i++) dp[x+i][y+i][z]=1;
					for(int i=1;i<MaxN-max(x,z);i++) dp[x+i][y][z+i]=1;
					for(int i=1;i<MaxN-max(y,z);i++) dp[x][y+i][z+i]=1;
					for(int i=1;i<MaxN-max(x,max(y,z));i++) dp[x+i][y+i][z+i]=1;
				}
	/* main */
	int xS, yS, zS;
	while(scanf("%d",&xS)!=EOF and xS>0){
		scanf(" %d %d\n",&yS,&zS);
		puts( dp[xS][yS][zS]? "w": "l" );
	}
}
