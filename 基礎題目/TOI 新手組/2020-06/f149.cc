/* 給定Ｒ×Ｃ的地圖，每個格子狀態(０=空地/１=地雷/５=偵測器)輸出(被偵測到和未偵測到)的地雷數量。
 * 當偵測器的周圍８格存在其他偵測器時，該偵測器會失靈。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxR=15+2;
int board[MaxR][MaxR]={};
bool mask[MaxR][MaxR];

inline bool Detect(int x,int y){
	return board[x-1][y-1]==5 or board[x-1][y]==5 or board[x-1][y+1]==5 or board[x][y-1]==5 or board[x][y+1]==5 or board[x+1][y-1]==5 or board[x+1][y]==5 or board[x+1][y+1]==5; }
int main(){
	int R, C;
	scanf("%d %d\n",&R,&C);
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			scanf("%d",&board[i][j]);
			
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			if(board[i][j]==5)
				mask[i][j]=Detect(i,j);
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			if(board[i][j]==5 and mask[i][j])
				board[i][j]=0;
	
	int A=0, B=0;
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			if(board[i][j]==1) 
				(Detect(i,j))? A++: B++;
	printf("%d %d\n",A,B);
}