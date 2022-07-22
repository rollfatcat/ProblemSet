/* 三維版本的前綴和( PerfixSum )
 * 概念相同，sum[x][y][z]紀錄的數值＝(0,0,0)-(x,y,z)的區間和
 * 查詢兩點內(x1,y1,z1)-(x2,y2,z2)的區間和時，
 *   sum[ x2 ][ y2 ][ z2 ]
 *  -sum[x1-1][ y2 ][ z2 ]-sum[ x2 ][y1-1][ z2 ]-sum[x2][ y2 ][z1-1]
 *  +sum[x1-1][y1-1][ z2 ]+sum[x1-1][ y2 ][z1-1]+sum[x2][y1-1][z1-1]
 *  -sum[x1-1][y1-1][z1-1]
 * 問題點：這題需要的記憶體空間剛好會到達單個函數(宣告在區域變數)可以允許的上限(大約1e6)
 *        而且題目只保證體積必定 ≦ 1e6但長寬高並沒有限制，無法事先宣告在全域範圍。
 *        因此只能宣告在區域空間時，數字無法空出"邊界"，避免SE(記憶體錯誤)。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxV=1e6;
const int MaxQ=1e4;
int main(){
    int R, C, H, Q;
	int x1, x2, y1, y2, z1, z2;
	scanf("%d %d %d\n",&R,&C,&H);
	// 題目保證數字不超過1e6且每個數值不超過1e3，所以區間和不超過1e9，可用 int 紀錄
    int prS[R][C][H]; 
	for(int h=0;h<H;h++)
		for(int r=0;r<R;r++)
			for(int c=0;c<C;c++){
				scanf("%d",&prS[h][r][c]);
				prS[h][r][c]+=((h>0)? prS[h-1][r][c]: 0)+
				              ((r>0)? prS[h][r-1][c]: 0)+
				              ((c>0)? prS[h][r][c-1]: 0)+
				              ((h>0 and r>0 and c>0)? prS[h-1][r-1][c-1]: 0)-
				              ((h>0 and r>0)? prS[h-1][r-1][c]: 0)-
				              ((r>0 and c>0)? prS[h][r-1][c-1]: 0)-
				              ((c>0 and h>0)? prS[h-1][r][c-1]: 0);
			}
    // 原點座標＝(1,1,1)而紀錄的三維陣列原點座標是(0,0,0)，存取數值時需要做校正
	for(scanf("%d\n",&Q);Q--;)
		scanf("%d %d %d %d %d %d\n",&x1,&y1,&z1,&x2,&y2,&z2),
		printf("%d\n",prS[x2-1][y2-1][z2-1]
                    -( (x1==1)? 0:prS[x1-2][y2-1][z2-1] )
                    -( (y1==1)? 0:prS[x2-1][y1-2][z2-1] )
                    -( (z1==1)? 0:prS[x2-1][y2-1][z1-2] )
                    +( (x1==1 or y1==1)? 0:prS[x1-2][y1-2][z2-1] )
                    +( (x1==1 or z1==1)? 0:prS[x1-2][y2-1][z1-2] )
                    +( (y1==1 or z1==1)? 0:prS[x2-1][y1-2][z1-2] )
                    -( (x1==1 or y1==1 or z1==1)? 0:prS[x1-2][y1-2][z1-2]));
}