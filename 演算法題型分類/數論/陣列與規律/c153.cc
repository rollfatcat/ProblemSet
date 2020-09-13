/* 題目給定Ｎ代表Ｎ×Ｎ矩陣，依照規定將數字由小到大填入矩陣，使得矩陣的行列總和皆相等。
 * 規則：
 * 		數字１從第１個 Row 的中間位置開始填寫。
 * 		每次向"右上方"填入下個數字(若超過邊界時則從一側繼續)直到遇到格子填寫過。
 * 		若下個位置是填寫過的狀態則改由目前位置的下一格重複剛剛的流程。
 * 解題關鍵：二維矩陣位置控制
 * 題目已經給定規則，依規則模擬填入即可。
 */
#include<bits/stdc++.h>
using namespace std;

int MaxN=39;
int board[40][40]={};
int main(){
	int N, R, C, v=1;
	scanf("%d\n",&N);
	
	R=N;
	C=(N+1>>1)+1;
	if(C>N) C-=N;
	board[1][N+1>>1]=v++;
	while( board[R][C]==0 ){
		board[R][C]=v++;
		int nxtR=(R-1 >0)? R-1:N;
		int nxtC=(C+1<=N)? C+1:1;
		if(board[nxtR][nxtC]){
			nxtR=(R+1<=N)? R+1: 1;
			nxtC=C;
		}
		R=nxtR; C=nxtC;
	}
	
	for(int i=1;i<=N;i++){
		printf("%d",board[i][1]);
		for(int j=2;j<=N;j++)
			printf(" %d",board[i][j]);
		putchar('\n');
	}
}
