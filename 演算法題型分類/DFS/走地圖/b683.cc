/* 題目給定Ｒ×Ｃ(最大３０×３０)，每格只有'＃'或'．'代表是否為 DNA ，輸出"環形" DNA 的個數和總和？
 * 題目定義的相連＝４格方向，且保證環形和線形都是單一路線(不存在分支的情況)
 * 解題關鍵：遞迴，無分支環形判斷
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxR=30;
const int MaxC=30;
char ss[MaxC+2];
/* 狀態設定時為了判斷環形，需要區隔"拜訪過的點"和"障礙物"兩種。
 * 狀態：０＝'#' １＝'.' ２＝vis 
 */
int dna[MaxR][MaxC];
int R, C, Pcnt; 
 
bool DFS(int x,int y,int point=0){
	Pcnt++;
	dna[x][y]=2;
	/* 因為路線不存在分支，挑選一個方向並回傳是否為環形 */
  if(  0<x and dna[x-1][y]==1) return DFS(x-1,y);
	if(x+1<R and dna[x+1][y]==1) return DFS(x+1,y);
	if(  0<y and dna[x][y-1]==1) return DFS(x,y-1);
	if(y+1<C and dna[x][y+1]==1) return DFS(x,y+1);
	/* 當走到尾端時才需要判斷是否存在環形，環形的條件＝存在兩個(拜訪過的)點
   * 若是線形只會存在一個(拜訪過)的點，其他都是障礙物。
   */
	if(  0<x) point+= dna[x-1][y]>0;
	if(x+1<R) point+= dna[x+1][y]>0;
	if(  0<y) point+= dna[x][y-1]>0;
	if(y+1<C) point+= dna[x][y+1]>0;
	return point==2;
}
int main(){
	while(scanf("%d %d\n",&R,&C)!=EOF){
		for(int i=0;i<R;i++){
			scanf("%s\n",ss);
			for(int j=0;j<C;j++)
				dna[i][j]= ss[j]=='.';
		}
		int Gcnt=0, sum=0;
		unsigned long mul=1;
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				if(dna[i][j]==1){
					Pcnt=0;
					if( DFS(i,j) )
						Gcnt++, 
						sum+=Pcnt, 
						mul*=Pcnt;
				}
		printf("\n%d %d %lu\n",Gcnt,sum,mul);
	}
}
/*
11 7
.......
.#####.
.#...#.
.#.#.#.
.#...#.
.#####.
.......
#######
#....#.
..##.#.
.###...
*/