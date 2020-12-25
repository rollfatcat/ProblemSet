/* 給定９種操作模式，模擬圖形編輯器互動。
 * Ｉ Ｍ Ｎ   ：創造Ｍ×Ｎ的圖且整張圖的像素設定為'Ｏ'
 * Ｃ        ：整張圖的像素設定為'Ｏ'
 * Ｌ Ｘ Ｙ Ｃ：使(Ｘ,Ｙ)的像素改為Ｃ
 * Ｖ Ｘ Ｙ1 Ｙ2 Ｃ：使(Ｘ,Ｙ1) 到 (Ｘ,Ｙ2)的像素改為Ｃ
 * Ｈ Ｘ1 Ｘ2 Ｙ Ｃ：使(Ｘ1,Ｙ) 到 (Ｘ2,Ｙ)的像素改為Ｃ
 * Ｋ Ｘ1 Ｘ2 Ｙ1 Ｙ Ｃ：使(Ｘ1,Ｙ1) 到 (Ｘ2,Ｙ2)的長方形範圍像素改為Ｃ
 * Ｆ Ｘ Ｙ Ｃ：滴管擴散，使(Ｘ,Ｙ)附近相同顏色的像素改為Ｃ
 * Ｓ Name：輸出檔案名稱和整張圖的內容
 * Ｘ：結束輸入
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxR=250;
const int MaxC=250;
int R, C;
char board[MaxR][MaxC];
 
void DFS(int x,int y,char c,char& t){
	board[x][y]=t;
	if(0<x   and board[x-1][y]==c) DFS(x-1,y,c,t);
	if(0<y   and board[x][y-1]==c) DFS(x,y-1,c,t);
	if(x+1<R and board[x+1][y]==c) DFS(x+1,y,c,t);
	if(y+1<C and board[x][y+1]==c) DFS(x,y+1,c,t);
}
int main(){
	char ss[100], ch;
	int opt, Lx, Ly, Rx, Ry;
 
	while((opt=getchar())!='X' and opt!=EOF){
		switch(opt){
			case 'I':
				scanf("%d %d\n",&C,&R);
			case 'C':
				for(int r=0;r<R;r++)
					for(int c=0;c<C;c++)
						board[r][c]='O';
				break;
			case 'L':
				scanf("%d %d %c\n",&Ly,&Lx,&ch);
				board[Lx-1][Ly-1]=ch;
				break;
			case 'S':
				scanf("%s\n",ss);
				puts(ss);
				for(int r=0;r<R;r++,putchar('\n'))
					for(int c=0;c<C;c++)
						putchar(board[r][c]);
				break;
			case 'V':
				scanf("%d %d %d %c\n",&Ly,&Lx,&Rx,&ch);
				for(int r=Lx-1;r<Rx;r++)
					board[r][Ly-1]=ch;
				break;
			case 'H':
				scanf("%d %d %d %c\n",&Ly,&Ry,&Lx,&ch);
				for(int c=Ly-1;c<Ry;c++)
					board[Lx-1][c]=ch;
				break;
			case 'K':
				scanf("%d %d %d %d %c\n",&Ly,&Lx,&Ry,&Rx,&ch);
				for(int r=Lx-1;r<Rx;r++)
					for(int c=Ly-1;c<Ry;c++)
						board[r][c]=ch;
				break;
			case 'F':
				scanf("%d %d %c\n",&Ly,&Lx,&ch);
				if(board[Lx-1][Ly-1]==ch)
					continue;
				DFS(Lx-1,Ly-1,board[Lx-1][Ly-1],ch);
				break;
		}
	}
}