// 圍棋眼位的判斷：(不需要DFS遞迴判斷斜向４個位置是否屬於某位玩家的屬地)
/* 注意測資的盤面中(5,1)應該是Fake(實際是Real)
 */

#include<bits/stdc++.h>
using namespace std;
#define MAXN 20

int N;
char GoMap[MAXN][MAXN];
char IsEye(int x,int y){
  // 若這格不是空地代表屬於'O'或是'X'，無法形成眼位
  if(GoMap[x][y]!='.') return '.';
  // 判斷橫直向４格是不是屬於同一個玩家
  vector<char> player;
  if(x>1) player.push_back(GoMap[x-1][y]);
  if(x<N) player.push_back(GoMap[x+1][y]);
  if(y>1) player.push_back(GoMap[x][y-1]);
  if(y<N) player.push_back(GoMap[x][y+1]);
  if(player[0]=='.') return '.';
  for(int i=1;i<player.size();i++)
    if(player[0]!=player[i])
      return '.';
  return player[0];
}
bool IsFake(int x,int y,char player){
  short cnt=0, type=0;
  if(x==1 or x==N) type++;
  if(y==1 or y==N) type++;

  if(1<x and 1<y and GoMap[x-1][y-1]==player) cnt++;
  if(x<N and 1<y and GoMap[x+1][y-1]==player) cnt++;
  if(1<x and y<N and GoMap[x-1][y+1]==player) cnt++;
  if(x<N and y<N and GoMap[x+1][y+1]==player) cnt++;

  return (type==2)? (cnt==1): (type==1)? (cnt==2): (cnt>=3);

}
int main(){
  int Q, x, y;
  while(scanf("%d",&N) and N){
    for(int i=N;i>0;i--)
      scanf("%s",GoMap[i]+1);
    scanf("%d",&Q);
    while(Q--){
      scanf("%d%d",&y,&x);
      char player=IsEye(x,y);
      if(player!='.')
        puts( IsFake(x,y,player)? "Real!": "Fake!");
      else
        puts("Interesting...");
    }
  }
}