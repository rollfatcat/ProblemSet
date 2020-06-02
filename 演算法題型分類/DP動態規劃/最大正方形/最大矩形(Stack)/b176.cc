/* 給定二維的地圖，最大化矩形面積。
 * 該矩形內的數字皆符合『嚴格遞減』(上方/左方的數字必須小於目前的數字)
 * 類似題：UVa-12192：給定二維矩陣和上下限的數字，最大化正方形邊長
 * 		該正方形內的數字皆落在範圍內。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e2;
const int MaxV=1e9;
int org [MaxN][MaxN];
int conR[MaxN][MaxN]; // 同一個 Row 連續小於的個數
int conC[MaxN][MaxN]; // 同一個 Col 連續小於的個數
int main(){
	/* 測資讀取並且計算連續性的累加
	 */
	int R, C;
	scanf("%d %d\n",&R,&C);
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++){
			scanf("%d",&org[i][j]);
			conC[i][j]=(i==0 or org[i-1][j]>=org[i][j])? 1: conC[i-1][j]+1;
			conR[i][j]=(j==0 or org[i][j-1]>=org[i][j])? 1: conR[i][j-1]+1;
		}
	/* 左上到右下枚舉每個格子(雙層迴圈)
	 * 以目前這個格子為右下角往左和往上延伸，計算可以形成的矩形
	 * 該格子 Col 的連續性 往左更新直到小於等於目前的高度
	 * 模仿 Stack：目前指標指到的格子，該格子的高度(Col連續性)是否＝目前假設的高度
	 * 當高度＝１時，矩形面積＝目前的格子往左 Row 的連續性
	 * 當高度＝２時，指標右移直到指的格子，該格子的高度(Col連續性)＝目前假設的高度 且 該格落在往左的寬度
	 */
	int maxRec=0, w;
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++){
			for(int k=j-1;k>=0 and conC[i][k]>conC[i][j];k--) 
				conC[i][k]=conC[i][j];
			w=conR[i][j], maxRec=max(maxRec,w);
			for(int H=2;H<=conC[i][j];maxRec=max(maxRec,H*w),H++)
				for(w=min(w,conR[i-H+1][j]);w>0 and conC[i][j-w+1]<H;w--);
		}
	printf("%d\n",maxRec);
}
/*
5 5
2 1 4 3 5
2 4 3 3 1
3 1 2 4 5
2 3 4 5 1
3 4 2 6 5
3 5
1 2 3 4 5
1 1 2 5 6
2 3 4 5 7
2 4
1 2 7 8
6 7 8 9
*/