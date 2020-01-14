/* Bingo模擬：建立映射表(號碼對應到賓果表中的座標)
 * 給定一張５x５的賓果卡，且規定每個Column可以填寫的數字範圍
 * 其中中間的格子(2,2)是space，可填入任意其他數字(重複也可)
 * 作法：建立映射表，紀錄輸入數字時紀錄該數字是屬於哪一格，若未選取時該格子的紀錄的賓果表座標值＝(-1,-1)，初始化時就需要把75個號碼都做此設定，當賓果表中的號碼被選中時則在對應的 Row[] 和 Col[] 紀錄中獎的號碼數量+1，對角線則額外判斷即可。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxNum=75;
struct NODE{
	int x, y;
	NODE(int x=-1,int y=-1):x(x),y(y){}
} pos[MaxNum];
int row[5];
int col[5];
int crs[2];

int main(){
	int caseT, num, turn;
	scanf("%d",&caseT);
	while(caseT--){
		// 初始化
		for(int i=1;i<=75;i++) 
			pos[i]=NODE();
		fill(row,row+5,0);
		fill(col,col+5,0);
		row[2]=col[2]=crs[0]=crs[1]=1;
		// 測資讀取
		for(int i=0;i<25;i++){
			if(i==12) continue;
			scanf("%d",&num);
			pos[num].x=i/5, pos[num].y=i%5;
		}
		//
		for(turn=0;turn++<75;){
			scanf("%d",&num);
			if(pos[num].x==-1 and pos[num].y==-1)// 該格子未選取
				continue;
			row[pos[num].x]++; 
			col[pos[num].y]++;
			crs[0]+= pos[num].x==pos[num].y;
			crs[1]+= pos[num].x+pos[num].y==4;
			if(row[pos[num].x]==5 or col[pos[num].y]==5 or crs[0]==5 or crs[1]==5){
				printf("BINGO after %d numbers announced\n",turn); break;
			}
		}
		while(turn++<75)
			scanf("%d",&num);
	}
}