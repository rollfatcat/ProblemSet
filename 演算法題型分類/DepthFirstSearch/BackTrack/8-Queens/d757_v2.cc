/* 給定邊長Ｎ的棋盤和Ｎ×Ｎ的格子能不能放皇后，輸出方法數？
 * 解題關鍵：Recursion＋BitMask(狀態壓縮)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=14;
int N, cnt;
int board[MaxN];
char oness[MaxN+2];

void PutQueens(int row,int col,int negative,int positive){
	if(row==N){ cnt++; return; }
  int Nmask=negative>>row;
	int Pmask=positive>>(N-1-row);
	int canPutQueen= board[row] & col & Pmask & Nmask;
	for(int yPut; canPutQueen>0; canPutQueen^=yPut){
		yPut=canPutQueen& -canPutQueen;
		PutQueens(row+1, col^yPut, negative^(yPut<<row), positive^(yPut<<(N-row-1)) );
	}
}
int main(){
	int D, caseI=1;
	while(scanf("%d\n",&N)!=EOF and N>0){
		/* 講每個 Row 能不能放皇后的狀態壓縮成一個整數做代表 
     * 第ｉ個整數的第ｊ個位元代表(ｉ,ｊ)這格子能不能放皇后
     */
    for(int i=0;i<N;i++){
			scanf("%s\n",oness);
      board[i]=0;
      for(int j=0;j<N;j++)
        board[i]|= (oness[j]=='.')<<j;
    } 
    cnt=0;
		PutQueens(0, (1<<N)-1, (1<<(2*N-1))-1, (1<<(2*N-1))-1);
		printf("Case %d: %d\n",caseI++,cnt);
	}
}