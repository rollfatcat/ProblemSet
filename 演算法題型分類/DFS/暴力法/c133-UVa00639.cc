/* 給定Ｎ×Ｎ棋盤(最大４×４)最多能放上多少個不會相互攻擊的城堡？
 * 注意：城堡的攻擊會被障礙物阻斷( 兩座城堡間隔著一格障礙物時就不會相互攻擊 )
 * 解題關鍵：暴力法遞迴
 * 遞迴枚舉((Ｘ,Ｙ)小到大)每個格子若有選擇時則 遞迴放不放城堡，否則只能選擇不放
 * 放城堡時往十字架的方向延伸(往右和往下即可，因為枚舉時是由左上開始)將"可以放"城堡的格子都設定為"不可放"
 * 還原時只能把設定過的格子做還原，其他的格子狀態不能改動。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=4;
int N, max_cnt;
bool can[MaxN][MaxN]={};

char ss[MaxN+2];
void Recursive(int x,int y,int cnt){
  /* 走遍所有的格子，比較棋盤上城堡的最大數量 */
	if(x==N){ max_cnt=max(max_cnt,cnt);  return; }
	/* 選擇"放"城堡 */
  if(can[x][y]){
		can[x][y]=0;
		int Rx, Ry;
		/* 從目前格子往右和往下延伸的範圍內"有選擇權"的格子都設定為不能放 */
    for(Rx=x+1; Rx<N  and can[Rx][y]; Rx++) can[Rx][y]=0;
		for(Ry=y+1; Ry<N  and can[x][Ry]; Ry++) can[x][Ry]=0;
		/* 當現在這個格子在這個 Row 邊界時從下次從下一個 Row 的第０格開始 */
    (y==N-1)? Recursive(x+1,0,cnt+1): Recursive(x,y+1,cnt+1);
    /* 從目前格子往右和往下延伸的範圍內"有選擇權"的格子都還原為能放 */
		for(Rx--; Rx>x; Rx--) can[Rx][y]=1;
		for(Ry--; Ry>y; Ry--) can[x][Ry]=1;
		can[x][y]=1;
	}
  /* 選擇"不"放城堡 */
	(y==N-1)? Recursive(x+1,0,cnt): Recursive(x,y+1,cnt);
}
int main(){
	while(scanf("%d\n",&N)!=EOF and N>0){
		for(int i=0;i<N;i++){
			scanf("%s\n",ss);
			for(int j=0;j<N;j++)
				can[i][j]= ss[j]=='.';
		}
		max_cnt=0;
		Recursive(0,0,0);
		printf("%d\n",max_cnt);
	}
}

/*
輸入：
4
....
....
....
X.X.
輸出：
4
*/