/* 給定Ｒ×Ｃ的地圖，輸出 最大面積的水窪 / 最小面積的水窪 / 所有水窪的數量？
 * 解題關鍵：DepthFirstSearch + memorization
 * 枚舉每格未走過的水窪為起點，利用深度優先搜尋走遍同一個連通區域，走過的水窪就設定為'#'避免重複走回。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxR=1e3;
const int MaxC=1e3;
char ss[MaxR][MaxC+2];
int R, C;
 
void DFS(int x,int y,int& now_area){
	ss[x][y]='#';
	now_area+=1;
	if(x>0   and ss[x-1][y]=='W') DFS(x-1,y,now_area);
	if(y>0   and ss[x][y-1]=='W') DFS(x,y-1,now_area);
	if(x+1<R and ss[x+1][y]=='W') DFS(x+1,y,now_area);
	if(y+1<C and ss[x][y+1]=='W') DFS(x,y+1,now_area);
}
int main(){
 
	scanf("%d %d\n",&R,&C);
	for(int r=0;r<R;r++)
		scanf("%s\n",ss[r]);
	int min_area=INT_MAX;
	int max_area=0;
	int waterCnt=0;
	for(int r=0;r<R;r++)
		for(int c=0;c<C;c++)
			if(ss[r][c]=='W'){
				waterCnt+=1;
				int now_area=0;
				DFS(r,c, now_area);
				min_area=min(min_area,now_area);
				max_area=max(max_area,now_area);
			}
	printf("%d %d %d\n",max_area,min_area,waterCnt);
}