/* 給定Ｒ×Ｃ的二維地圖和遮罩
 * 根據每個位置作轉換：若與該位置相同行/列的１個數是奇數則把地圖上的位元反向。
 * 讀取遮罩時就同時統計該位置的行列中１的個數，但計算時該位置會重複計算兩次所以要扣回一次
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxR=1e2;
const int MaxC=1e2;
bool mapv[MaxR][MaxC];
bool mask[MaxR][MaxC];
bool Rsum[MaxR];
bool Csum[MaxC];
int main(){
	for(int R,C;scanf("%d %d\n",&R,&C)!=EOF;){
		for(int x=0;x<R;x++)
			for(int y=0;y<C;y++)
				scanf("%d",&mapv[x][y]);
		fill(Rsum,Rsum+R,0);
		fill(Csum,Csum+C,0);
		for(int x=0;x<R;x++)
			for(int y=0;y<C;y++)
				scanf("%d",&mask[x][y]),
				Rsum[x]^=mask[x][y],
				Csum[y]^=mask[x][y];
		for(int x=0;x<R;x++,putchar('\n'))
			for(int y=0;y<C;y++)
				printf("%d ",mapv[x][y]^mask[x][y]^Rsum[x]^Csum[y]);
	}
}
