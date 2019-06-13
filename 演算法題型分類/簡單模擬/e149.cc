/* 模擬題：需要思考可能的盤面後做排容：
 * (1) 黑棋的數量 和 白棋的數量 一樣多且黑棋未勝(所以才可以輪到白棋)
 * (2) 黑棋的數量 比 白棋的數量 多一手且白棋未勝(所以才可以輪到黑棋)
 */
#include<bits/stdc++.h>
using namespace std;

char mapss[6][7];
inline bool IsWin(char player){
  bool player_win=false;
  for(int i=0;i<6 and player_win==0;i++) // Row or Column 的連續5格
    player_win|=(mapss[i][0]==player and mapss[i][1]==player and mapss[i][2]==player and mapss[i][3]==player and mapss[i][4]==player),
    player_win|=(mapss[i][1]==player and mapss[i][2]==player and mapss[i][3]==player and mapss[i][4]==player and mapss[i][5]==player),
    player_win|=(mapss[0][i]==player and mapss[1][i]==player and mapss[2][i]==player and mapss[3][i]==player and mapss[4][i]==player),
    player_win|=(mapss[1][i]==player and mapss[2][i]==player and mapss[3][i]==player and mapss[4][i]==player and mapss[5][i]==player);
  if(player_win==0) // 方向：左上右下的斜線
    player_win|=(mapss[0][0]==player and mapss[1][1]==player and mapss[2][2]==player and mapss[3][3]==player and mapss[4][4]==player),
    player_win|=(mapss[1][1]==player and mapss[2][2]==player and mapss[3][3]==player and mapss[4][4]==player and mapss[5][5]==player),
    player_win|=(mapss[0][1]==player and mapss[1][2]==player and mapss[2][3]==player and mapss[3][4]==player and mapss[4][5]==player),
    player_win|=(mapss[1][0]==player and mapss[2][1]==player and mapss[3][2]==player and mapss[4][3]==player and mapss[5][4]==player);
  if(player_win==0) // 方向：左下右上的斜線
    player_win|=(mapss[0][4]==player and mapss[1][3]==player and mapss[2][2]==player and mapss[3][1]==player and mapss[4][0]==player),
    player_win|=(mapss[0][5]==player and mapss[1][4]==player and mapss[2][3]==player and mapss[3][2]==player and mapss[4][1]==player),
    player_win|=(mapss[1][4]==player and mapss[2][3]==player and mapss[3][2]==player and mapss[4][1]==player and mapss[5][0]==player),
    player_win|=(mapss[1][5]==player and mapss[2][4]==player and mapss[3][3]==player and mapss[4][2]==player and mapss[5][1]==player);
  return player_win;
}

int main(){
  int caseT;

  scanf("%d",&caseT);
  while(caseT--){
    int black=0, white=0;
    for(int i=0;i<6;i++){
      scanf("%s",mapss[i]);
      for(int j=0;j<6;j++)
        if(mapss[i][j]=='B') black++;
        else if(mapss[i][j]=='W') white++;
    }
    if(black==white)
      puts(IsWin('B')?"N":"Y");
    else if(black==white+1)
      puts(IsWin('W')?"N":"Y");
    else
      puts("N");
  }
}