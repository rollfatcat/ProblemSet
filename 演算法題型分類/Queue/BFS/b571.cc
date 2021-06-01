// 值得一做的BFS，解法簡單但不易想到
/* 乍看之後會以為是複雜的BFS，得同時考慮時間和障礙物(陷阱會根據不同時間被視為障礙物)
 * 觀察後可以發現其實時間隨著不同陷阱變化可以切分成3種狀態，分別紀錄步數對應的不同陷阱的時間即可
 */
#include<bits/stdc++.h>
using namespace std;
#define maxN 1<<9

char char_map[maxN][maxN]={};
int time_map[3][maxN][maxN];
struct nn{ int t, x, y; } st, ed, now, nxt;
int main(){
  int R, C, move[4]={-1,1,0,0};
  scanf("%d %d",&R,&C);
  // time_map[t][x][y] 初始化給值-1
  memset(time_map,0xff,sizeof(time_map));
  // 讀取時為了避免判斷邊界存儲位置偏差(1,1)，邊界部分的字元改為'#'
  for(int i=1;i<=R;i++){
    scanf("%s",char_map[i]+1);
    for(int j=1;j<=C;j++){
      if(char_map[i][j]=='X') st.t=0, st.x=i, st.y=j;
      if(char_map[i][j]=='Y') ed.t=-1, ed.x=i, ed.y=j;
    }
    char_map[i][0]=char_map[i][C+1]='#';
  }
  for(int j=1;j<=C;j++)
    char_map[0][j]=char_map[R+1][j]='#';
  // 以下是由【現在這點】去更新四周沒走過且不是邊界也不是障礙物的點
  queue<nn> Q;
  Q.push(st), time_map[st.t][st.x][st.y]=0;
  while(!Q.empty()){
    now=Q.front(), Q.pop();
    if(now.x==ed.x and now.y==ed.y){
      ed.t=time_map[now.t][now.x][now.y]; break;
    }
    nxt.t=(now.t+1)%3;
    for(int i=0;i<4;i++){
      nxt.x=now.x+move[i],
      nxt.y=now.y+move[3-i];
      if(char_map[nxt.x][nxt.y]!='#' and time_map[nxt.t][nxt.x][nxt.y]==-1 and nxt.t!=(char_map[nxt.x][nxt.y]-'A'))
        time_map[nxt.t][nxt.x][nxt.y]=time_map[now.t][now.x][now.y]+1,
        Q.push(nxt);
    }
  }
  // 如果有找到，提早跳開前會紀錄ed.t，如果找不到ed.t就是初始值的-1
  printf("%d\n",ed.t);
}