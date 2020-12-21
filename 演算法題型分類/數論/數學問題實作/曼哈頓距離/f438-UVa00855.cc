/* 給定座標軸的右上角(範圍)Ｓ,Ａ和Ｆ個落在範圍內的點，輸出與所有點的曼哈頓距離總和最少的點座標(多組解則輸出ＸＹ越小越好)
 * 解題關鍵：曼哈頓距離
 * 將兩個維度的值分開處理，由小到大排序後取中位數。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxA=1e3;
const int MaxF=5e4;
int pos[2][MaxF];
int main(){
	int caseT, S, A, F;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d %d\n",&S,&A,&F);
		for(int i=0;i<F;i++)
			scanf("%d %d\n",&pos[0][i],&pos[1][i]);
		sort(pos[0],pos[0]+F);
		sort(pos[1],pos[1]+F);
		printf("(Street: %d, Avenue: %d)\n",pos[0][F-1>>1],pos[1][F-1>>1]);
	}
}