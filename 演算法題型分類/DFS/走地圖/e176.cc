// 目標找到：被叫吃且數量最多的棋子，輸出唯一一口『氣』的位置
/* 叫吃的定義：這個格子是'.'且判斷四個位置所延伸的領地是不是只剩這口氣。
 * 注意題目規定：這口氣不能在落子後形成『氣絕』。
 * 若全部的領地都屬於叫吃的狀態但落子後會形成氣絕的話則輸出T_T。
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 20

int N, chi, load;
char player;
char GoMap[MAXN][MAXN];
bool vis[MAXN][MAXN]={};

void DFS(int x,int y){
  vis[x][y]=1;
  if(GoMap[x][y]=='.') chi++;
  if(GoMap[x][y]==player) load++;
  if(GoMap[x][y]!=player) return;

  if(x>1 and !vis[x-1][y]) DFS(x-1,y);
  if(x<N and !vis[x+1][y]) DFS(x+1,y);
  if(y>1 and !vis[x][y-1]) DFS(x,y-1);
  if(y<N and !vis[x][y+1]) DFS(x,y+1);
}
bool TryTheGrid(int x,int y){
  player=GoMap[x][y], load=chi=0,
  memset(vis,0,sizeof(vis));
  DFS(x,y);
  return chi==1;
}
int main(){
  while(scanf("%d",&N) and N){
    for(int i=N;i>0;i--)
      scanf("%s",GoMap[i]+1);

    bool Nolive=false;
    int max_load=0, rec_load;
    pair<int,int> rec;
    /* 枚舉棋盤上每個座標(依照題目要求的順序更新)
     * 以這格往四周判斷是否存在叫吃狀態的領地，若存在則再判斷落子後是否會形成氣絕
     * 若不會形成氣絕才可以更新紀錄，若會形成氣絕則更新 Nolive 的狀態
     * 唯有 Nolive=1 且 max_load=0 時代表存在領地處於叫吃的狀態但落子後會形成氣絕。
     */
    for(int x=1;x<=N;x++)
      for(int y=1;y<=N;y++){
        if(GoMap[y][x]!='.') continue;
        if(x>1 and GoMap[y][x-1]!='.' and TryTheGrid(y,x-1)){
          rec_load=load;
          GoMap[y][x]=GoMap[y][x-1];
          TryTheGrid(y,x);
          if(chi>0){ if(rec_load>max_load) max_load=rec_load, rec=make_pair(x,y); } else Nolive=true;
          GoMap[y][x]='.';
        }
        if(x<N and GoMap[y][x+1]!='.' and TryTheGrid(y,x+1)){
          rec_load=load;
          GoMap[y][x]=GoMap[y][x+1];
          TryTheGrid(y,x);
          if(chi>0){ if(rec_load>max_load) max_load=rec_load, rec=make_pair(x,y); } else Nolive=true;
          GoMap[y][x]='.';
        }
        if(y>1 and GoMap[y-1][x]!='.' and TryTheGrid(y-1,x)){
          rec_load=load;
          GoMap[y][x]=GoMap[y-1][x];
          TryTheGrid(y,x);
          if(chi>0){ if(rec_load>max_load) max_load=rec_load, rec=make_pair(x,y); } else Nolive=true;
          GoMap[y][x]='.';
        }
        if(y<N and GoMap[y+1][x]!='.' and TryTheGrid(y+1,x)){
          rec_load=load;
          GoMap[y][x]=GoMap[y+1][x];
          TryTheGrid(y,x);
          if(chi>0){ if(rec_load>max_load) max_load=rec_load, rec=make_pair(x,y); } else Nolive=true;
          GoMap[y][x]='.';
        }
      }
    (max_load==0 and Nolive)? puts("T_T"): printf("%d %d\n",rec.first,rec.second);
  }
}
/*
5
.XO..
XOX..
XO...
OX...
.....
// 3 3
*/