/* 給定邊長Ｎ的棋盤和Ｎ×Ｎ的格子能不能放皇后，輸出方法數？
 * 解題關鍵：EightQueen 變形題(遞迴前需要檢查棋盤上這格能不能放皇后)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=14;
bool column[MaxN]={1,1,1,1,1,1,1,1,1,1,1,1,1,1};
bool negative[MaxN<<1]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
bool positive[MaxN<<1]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

int N, cnt;
char oness[MaxN+2];
bool board[MaxN][MaxN];

void PutQueens(int row){
	if(row==N){ cnt++; return; }
	for(int col=0;col<N;col++)
		if(column[col] & negative[col+row] & positive[col-row+N] & board[row][col]){
			column[col]=negative[col+row]=positive[col-row+N]=0;
			PutQueens(row+1);
			column[col]=negative[col+row]=positive[col-row+N]=1;
		}
}
int main() {
	for(int caseI=1;scanf("%d\n",&N)!=EOF and N>0;caseI++){
		for(int i=0;i<N;i++){
			scanf("%s\n",oness);
      for(int j=0;j<N;j++)
        board[i][j]= oness[j]=='.';
    }
		cnt=0;
		PutQueens(0);
		printf("Case %d: %d\n",caseI,cnt);
	}
}