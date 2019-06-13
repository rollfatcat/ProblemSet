// 解題核心：打劫＝只有一氣且領地數＝1的格子只有一格否則不會造成打劫

#include<bits/stdc++.h>
using namespace std;
#define MAXN 20

int N, chi, load;
char player;
char GoMap[MAXN][MAXN];
bool vis[MAXN][MAXN]={};

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
int main(){
  for(int caseN=1;scanf("%d",&N) and N;caseN++){
    printf("Case %d:\n",caseN);
    //
    for(int i=N;i>0;i--)
      scanf("%s",GoMap[i]+1);

    bool NoAns=true;
    for(int x=1;x<=N;x++)
      for(int y=1;y<=N;y++){
        // 這格是空地而且四周形成眼位，IsEye()回傳四周形成的眼位屬於誰的領地
        player=IsEye(y,x);
        if(player=='.') continue;

        // 枚舉形成眼位的點往外相連的屬地是不是只有一氣且領地數＝1
        // 打劫＝只有一氣且領地數＝1的格子只有一格否則不會造成打劫(題目未說明需要自行推導)
        vector<short> one_chi;
        if(x>1){ load=chi=0, memset(vis,0,sizeof(vis)), DFS(y,x-1);
        if(chi==1) one_chi.push_back(load); }

        if(x<N){ load=chi=0, memset(vis,0,sizeof(vis)), DFS(y,x+1);
        if(chi==1) one_chi.push_back(load); }

        if(y>1){ load=chi=0, memset(vis,0,sizeof(vis)), DFS(y-1,x);
        if(chi==1) one_chi.push_back(load); }

        if(y<N){ load=chi=0, memset(vis,0,sizeof(vis)), DFS(y+1,x);
        if(chi==1) one_chi.push_back(load); }

        if(one_chi.size()==1 and one_chi[0]==1) NoAns=0, printf("%d %d\n",x,y);
      }
    if(NoAns) puts("Peace!!");
  }
}
/* 題目未提及但容易判斷出錯的測資：
5
OOO..
OXXO.
OX.XO
OXXO.
OOO..
// Peace!
*/