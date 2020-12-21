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

/* 描述７條"線"是否已經存在"必輸"狀態，狀態需要描述的是能夠構成線的"平面"
 * 三維空間內描述的線：Ａｘ+Ｂｙ+Ｃｚ＝Ｄ，需要使用兩個平面，枚舉兩個平面的Ｄ1+Ｄ2＝Ｄ時注意Ｄ1,Ｄ2範圍
 * (  Ｘ,  Ｙ,Ｚ+n)：Ｘ=x, Ｙ=y
 * (  Ｘ,Ｙ+n,  Ｚ)：Ｘ=x, Ｚ=z
 * (Ｘ+n,  Ｙ,  Ｚ)：Ｙ=y, Ｚ=z
 * (  Ｘ,Ｙ+n,Ｚ+n)：Ｘ=x, Ｙ-Ｚ=y-z
 * (Ｘ+n,  Ｙ,Ｚ+n)：Ｙ=y, Ｘ-Ｚ=x-z
 * (Ｘ+n,Ｙ+n,  Ｚ)：Ｚ=z, Ｘ-Ｙ=x-y
 * (Ｘ+n,Ｙ+n,Ｚ+n)：Ｘ-Ｙ=x-y, Ｙ-Ｚ=y-z
 * 
 */
const int MaxN=201;
bool XY[MaxN][MaxN]={};
bool XZ[MaxN][MaxN]={};
bool YZ[MaxN][MaxN]={};
bool X_YZ[MaxN][MaxN<<1]={};
bool Y_XZ[MaxN][MaxN<<1]={};
bool Z_XY[MaxN][MaxN<<1]={};
bool XYZ[MaxN<<1][MaxN<<1]={};

int main(){
	/* Bottom-Up */
	for(int x=0;x<MaxN;x++)
		for(int y=0;y<MaxN;y++)
			for(int z=0;z<MaxN;z++)
				if( !(XY[x][y] | XZ[x][z] | YZ[y][z] | X_YZ[x][y-z+200] | Y_XZ[y][x-z+200] | Z_XY[z][x-y+200] | XYZ[x-y+200][y-z+200]) ){
					/* 只輸出遞增的狀態 */
                    if(x<=y and y<=z)
						printf("%d %d %d\n",x,y,z);
					XY[x][y]=XZ[x][z]=YZ[y][z]=X_YZ[x][y-z+200]=Y_XZ[y][x-z+200]=Z_XY[z][x-y+200]=XYZ[x-y+200][y-z+200]=1;
				}
}