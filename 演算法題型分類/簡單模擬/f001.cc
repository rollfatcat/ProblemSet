/* 給定『進行中』的盤面，輸出有幾種『平手』的局面和盤面的內容(依字典序輸出)？
 * 規則：ＯＸ遊戲是由Ｏ開始，盤面的內容間需要以換行分隔，但每筆測資後則是直接輸出換行。
 * 直覺(Ｘ)
 * 作法：根據規則先判斷進行中的盤面接下來是誰下，從'-'的格子中挑一個位置後，
 *    檢查填入後是否會造成該玩家獲勝，若不會則遞迴呼叫帶入另一位玩家，直到盤面填滿。
 * 問題：該方法找到的平手盤面會重複(挑選的順序不同但盤面結果相同)
 *      且需要處理平手盤面要依照字典序輸出的問題。
 * 正解(Ｏ)
 * 作法：每格都可填入ＯＸ(因為字典序Ｏ優先)，每填一格時就檢查是否會出現贏家
 *      因為Ｏ開始，最終盤面的Ｏ必定是５個，所以停止條件需要檢查每格都填完且#Ｏ=5
 */
#include<bits/stdc++.h>
using namespace std;

char board[9];
int check_cnt[9]={3,2,3,2,4,2,3,2,3};
int check[9][4][2]={
	{{1,2},{3,6},{4,8}},
	{{0,2},{4,7}},
	{{0,1},{4,6},{5,8}},
	{{0,6},{4,5}},
	{{0,8},{1,7},{2,6},{3,5}},
	{{2,8},{3,4}},
	{{0,3},{2,4},{7,8}},
	{{1,4},{6,8}},
	{{0,4},{2,5},{6,7}},
};

vector<int> pool;
char memo[512][10];
char player[2]={'O','X'};
int cnt;
inline bool IsSafe(int now,char who){
	for(int i=0;i<check_cnt[now];i++)
		if(who==board[ check[now][i][0] ] and 
		   who==board[ check[now][i][1] ])
			return false;
	return true;
}
inline void DFS(int depth,int P1,int P2){
	if(depth==9){
		if(P1==5){
			for(int i=0;i<9;i++)
				memo[cnt][i]=board[i];
			memo[cnt++][9]='\0';
		}
		return;
	}
	if(board[depth]=='O'){ DFS(depth+1,P1+1,P2); return; }
	if(board[depth]=='X'){ DFS(depth+1,P1,P2+1); return; }
	if(board[depth]=='-'){
		if(IsSafe(depth,'O'))
			board[depth]='O', DFS(depth+1,P1+1,P2);
		if(IsSafe(depth,'X'))
			board[depth]='X', DFS(depth+1,P1,P2+1);
		board[depth]='-';
	}
}
int main(){
	
	for(int caseN=1;scanf("%s\n",board)!=EOF;caseN++){
		cnt=0, DFS(0,0,0);
		printf("%d\n",cnt);
		for(int i=0;i<cnt;i++){
			if(i>0) putchar('\n');
			for(int j=0;j<9;j++){
				putchar(memo[i][j]);
				if(j%3==2) putchar('\n');
			}
		}
		putchar('\n');
	}
}