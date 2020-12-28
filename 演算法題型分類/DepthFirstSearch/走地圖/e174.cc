// 圍地的定義除了空格外還要包含圍地的棋子，且題目不會有『平手』的情況
// 核心想法：枚舉每一個沒有走過的格子做深度優先搜尋，碰到『邊界棋子』時標註玩家後結束
// 難點：怎麼設計深度搜尋時這個腹地是屬於哪個玩家

#include<bits/stdc++.h>
using namespace std;
#define MAXN 20

int black, white;
int cnt;
char player;
char GoMap[MAXN][MAXN];
bool vis[MAXN][MAXN];
void DFS(int x,int y){
  // 將這格狀態轉變為『走過』並且數量+1
  vis[x][y]=1, cnt++;
  // 若這格不是空格：需要登記玩家後結束搜尋
  if(GoMap[x][y]!='.'){ player=GoMap[x][y]; return; }
  // 往四周移動(若在合法範圍內)
  if(x>0 ) if(!vis[x-1][y]) DFS(x-1,y);
  if(x<18) if(!vis[x+1][y]) DFS(x+1,y);
  if(y>0 ) if(!vis[x][y-1]) DFS(x,y-1);
  if(y<18) if(!vis[x][y+1]) DFS(x,y+1);
  // 標註這格是屬於哪個玩家
  GoMap[x][y]=player;
}
int main(){
  int caseT;
  scanf("%d",&caseT);
  while(caseT--){
    for(int i=0;i<19;i++)
      scanf("%s",GoMap[i]);
    memset(vis,0,sizeof(vis));
    black=white=0;
    for(int i=0;i<19;i++)
      for(int j=0;j<19;j++)
        if(!vis[i][j]){
          cnt=0, DFS(i,j);
          (player=='O')? black+=cnt: white+=cnt;
        }
    printf("O:%d\nX:%d\n",black,white);
    puts((black>white)?"Black win!!":"White win!!");
  }
}