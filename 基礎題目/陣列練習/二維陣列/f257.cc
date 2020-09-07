/* 給定Ｎ×Ｎ方格地圖和Ｋ個地雷，非地雷格子輸出周圍８格的地雷個數否則輸出'X'代表地雷。
 * 解題關鍵：二維陣列座標
 * 第２筆測資顯示題目會給予重複位置的地雷，紀錄上只顯示１次。
 * 最終輸出的地圖座標是以 Column-based
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e2;
const int dead=1<<30;
int scare[MaxN][MaxN];
int main(){
	int N, K, x, y;
	while(scanf("%d\n%d\n",&N,&K)!=EOF){
		memset(scare,0,sizeof(scare));
		while(K-->0){
			scanf("%d %d\n",&x,&y);
			if(scare[x][y]>=dead) continue;
			scare[x][y]=dead;
			if(  x>0) scare[x-1][y]++;
			if(x+1<N) scare[x+1][y]++;
			if(  y>0) scare[x][y-1]++;
			if(y+1<N) scare[x][y+1]++;
			if(x>0   and   y>0) scare[x-1][y-1]++;
			if(x+1<N and   y>0) scare[x+1][y-1]++;
			if(x>0   and y+1<N) scare[x-1][y+1]++;
			if(x+1<N and y+1<N) scare[x+1][y+1]++;
		}
		for(int i=0;i<N;i++,putchar('\n'))
			for(int j=0;j<N;j++)
				putchar( scare[j][i]>9? 'x':scare[j][i]+'0');
	}
}