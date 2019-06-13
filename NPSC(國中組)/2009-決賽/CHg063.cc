// 很難的DFS模擬題, 需要自己推測所有水流的情況和走向
// 輸入：方向和下一個格子位置(為避免超出邊界在四周填上'.')
// 輸出：根據現在這一格決定下一步怎麼移動和方向是不是要改變
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 25

int R, C;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char map[MaxN][MaxN];
struct Node{ int x, y; }node[26];
char DFS(int now_x, int now_y, int dir){
  //printf("%2d %2d %d\n",now_x,now_y,dir);
  if(dir<2){ //移動方向目前是『橫的』
    if(map[now_x][now_y]=='-' or map[now_x][now_y]=='#')  // 保持方向
      return DFS(now_x, now_y+dy[dir], dir);
    else if(map[now_x][now_y]=='+'){ // 改變方向, 查看另一個維度
      if(map[now_x+1][now_y]!='-' and map[now_x+1][now_y]!='.')
        return DFS(now_x+1,now_y,2);
      else  return DFS(now_x-1,now_y,3);
    }else // 現在這一格是字母代表走到底
      return map[now_x][now_y];
  }else{ //移動方向目前是『直的』
    if(map[now_x][now_y]=='|' or map[now_x][now_y]=='#')// 保持方向
      return DFS(now_x+dx[dir], now_y, dir);
    else if(map[now_x][now_y]=='+'){ // 改變方向, 查看另一個維度
      if(map[now_x][now_y+1]!='|' and map[now_x][now_y+1]!='.')
        return DFS(now_x,now_y+1,0);
      else  return DFS(now_x,now_y-1,1);
    } else // 現在這一格是字母代表走到底
      return map[now_x][now_y];
  }
}
int main(){
  int caseNum, Q;
  char st_node, link[26];
  for(int i=0;i<=21;i++)
    map[i][0]=map[0][i]='.';

  cin>>caseNum;
  while(caseNum--){
    cin>>R>>C;
    memset(node,0xff,sizeof(node));
    for(int i=1;i<=R;i++){
      for(int j=1;j<=C;j++){
        cin>>map[i][j];
        if('A'<=map[i][j] and map[i][j]<='Z')
          node[map[i][j]-'A'].x=i,  node[map[i][j]-'A'].y=j;
      }
      map[i][C+1]='.';
    }
    for(int j=1;j<=C;j++)
      map[R+1][j]='.';
    memset(link,0,sizeof(link));
    for(cin>>Q;Q--;){
      cin>>st_node;
      int st=st_node-'A';
      if(link[st]==0){
        for(int i=0;i<4;i++){ //決定出發方向和下一個點的位置, 題目保證點是一對一對應,跑一次就記起來
          int x=node[st].x+dx[i];
          int y=node[st].y+dy[i];
          if(map[x][y]=='#' or map[x][y]=='+'){  link[st]=DFS(x,y,i), link[link[st]-'A']=st_node;  break;  }
          else if(map[x][y]=='-' and i<2){ link[st]=DFS(x,y,i), link[link[st]-'A']=st_node;    break;  }
          else if(map[x][y]=='|' and i>1){ link[st]=DFS(x,y,i), link[link[st]-'A']=st_node;    break;  }
        }
      }
      cout<<st_node<<"->"<<link[st]<<endl;
    }
  }
}