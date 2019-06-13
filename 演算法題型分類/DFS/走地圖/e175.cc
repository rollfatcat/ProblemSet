// 計算某個棋子連成的區域『氣』的數量
// 從某個棋子做深度搜索(往外延伸)
// 若是同一位玩家的棋子就可以再往外展開，若是空地則計算氣(避免同一格重複走過)。

#include<bits/stdc++.h>
using namespace std;
#define MAXN 20

int N, cnt;
char player;
char GoMap[MAXN][MAXN];
bool vis[MAXN][MAXN]={};

void DFS(int x,int y){
  vis[x][y]=1;
  if(GoMap[x][y]=='.') cnt++;
  if(GoMap[x][y]!=player) return;

  if(x>0 and !vis[x-1][y]) DFS(x-1,y);
  if(x<N-1 and !vis[x+1][y]) DFS(x+1,y);
  if(y>0 and !vis[x][y-1]) DFS(x,y-1);
  if(y<N-1 and !vis[x][y+1]) DFS(x,y+1);
}
int main(){
  while(scanf("%d",&N) and N){
    for(int i=N-1;i>=0;i--)
      scanf("%s",GoMap[i]);

    int Q, x, y;
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++){
      scanf("%d%d",&y,&x);
      y--, x--;
      cnt=0;
      if(GoMap[x][y]=='O' or GoMap[x][y]=='X'){
        memset(vis,0,sizeof(vis));
        player=GoMap[x][y],
        DFS(x,y);
      }
      printf("%d\n",cnt);
    }
  }
}