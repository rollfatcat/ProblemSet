/* 給定 21×15 的地圖(不存在邊界)根據移動指令模擬貪食蛇的移動過程，輸出遊戲結束後的從頭部到尾端的身體位置。
 * 吃到食物時，身體會從尾端延伸出一格並且該格子的食物會消失(只存在一次)。
 * 碰到蛇的身體 或是 障礙物時則結束遊戲(不再依據指令移動)。
 * 解題關鍵：Queue(維護貪食蛇的伸縮身體) + BFS
 * 根據移動指令判斷"下一格的狀態"是屬於 (1)空格 (2)食物 (3)障礙物/身體
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxW=21;
const int MaxH=15;
char board[MaxH][MaxW+2];
struct NODE{
	int x, y;
	NODE(int x=0,int y=0):x(x),y(y){}
};
int DIR[128];
int dv[4]={1,-1,0,0};

int main(){
	DIR['S']=0;
	DIR['N']=1;
	DIR['W']=2;
	DIR['E']=3;
	
	for(int r=0;r<15;r+=1)
		scanf("%s",board[r]);
	
	deque<NODE> snake={NODE()};
	char opt[5];
	int step;
	bool stop=false;
	while(stop==0 and scanf("%s %d",opt,&step)!=EOF){
		int dir=DIR[opt[0]];
		while(step-->0){
			NODE nxt=snake.front();
			nxt.x+=dv[   dir ];
			nxt.x=(nxt.x==-1)? 14:(nxt.x==15)? 0: nxt.x;
			nxt.y+=dv[ 3-dir ];
			nxt.y=(nxt.y==-1)? 20:(nxt.y==21)? 0: nxt.y;
			switch(board[nxt.x][nxt.y]){
				case 's':
				case 'x': 
					stop=true; break;
				case 'o': 
					board[snake.back().x][snake.back().y]='o'; 
					snake.pop_back();
				case '$': 
					board[nxt.x][nxt.y]='s';
					snake.push_front(nxt); 
					break;
			}
		}
	}
	for(NODE now:snake)
		printf("%d %d\n",now.y,now.x);
}