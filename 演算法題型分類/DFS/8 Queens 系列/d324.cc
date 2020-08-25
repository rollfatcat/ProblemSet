/* 給定８×８的棋盤每格的分數，輸出在８皇后的限制下能夠獲得最大的８格分數和是多少(靠右對齊長度５)？
 * 解題關鍵：EightQueen
 * 先算出８皇后的９２種解答，每給定張新分數時就依照９２種答案推算相應的總和後找出最大值。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=20;
const int MaxN=8;
int ans_cnt=0;
int now_y[8];
bool col[8]={};
bool nsh[16]={};
bool psh[16]={};
int ans_y[92][8]; // ans_y[ 第ｉ個答案 ][ Ｘ座標 ]= Ｙ座標

void EQ(int x){
	if(x==MaxN){
		/* 把選定８個皇后的位置複製到 ans_y */
		for(int i=0;i<MaxN;i++)
			ans_y[ans_cnt][i]=now_y[i];
		ans_cnt++;
		return;
	}
	for(int i=0;i<MaxN;i++)
		if(col[i] & nsh[x+i] & psh[x-i+MaxN]){
			now_y[x]=i;
			col[i]=nsh[x+i]=psh[x-i+MaxN]=1;
			EQ(x+1);
			col[i]=nsh[x+i]=psh[x-i+MaxN]=0;
		}
}
int main(){
	/* 先找出９２組答案的座標 */
	EQ(0);
	
	int caseT, x, y;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d\n",&y,&x);
		printf("SOLN       COLUMN\n");
		printf("#      1 2 3 4 5 6 7 8\n\n");
		int ID=1;
		for(int i=0;i<ans_cnt;i++){
			if(ans_y[i][x-1]==y-1){
				printf("%2d     ",ID++);
				for(int j=0;j<8;j++)
					printf(" %d",ans_y[i][j]+1);
				putchar('\n');
			}
		}
		putchar('\n');
	}
}