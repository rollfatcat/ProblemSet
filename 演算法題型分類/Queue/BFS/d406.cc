#include<iostream>
#include<queue>
using namespace std;
#define MaxN 101

struct Pos{ int x,y,dis; }now, nxt;

int main(){
  int dx[4]={ 0, 0, 1,-1};
  int dy[4]={-1, 1, 0, 0};
  bool vis[MaxN][MaxN];
  int map[MaxN][MaxN];

  int canUP, W, H, new_x, new_y;
  for(int caseNum=1;  cin>>canUP; caseNum++){
    cin>>H>>W;
    queue<Pos> Q;
    for(int i=0;i<H;i++)
      for(int j=0;j<W;j++)
        cin>>vis[i][j], map[i][j]=0;

    for(int i=0;i<W;i++)
      if(vis[0][i]){
        now.x=i,  now.y=0,  now.dis=1;
        Q.push(now);
        break;
      }

    canUP=canUP-1;
    while(!Q.empty()){
      now=Q.front();
      Q.pop();
      if(vis[now.y][now.x]){
        vis[now.y][now.x]=0;
        map[now.y][now.x]=now.dis;
        for(int i=canUP;i<4;i++){
          new_x=now.x+dx[i];
          new_y=now.y+dy[i];
          if(0<=new_x and new_x<W and 0<=new_y and new_y<H and vis[new_y][new_x])
            nxt.x=new_x,  nxt.y=new_y,  nxt.dis=now.dis+1, Q.push(nxt);
        }
      }
    }
    cout<<"Case "<<caseNum<<":\n";
    for(int i=0;i<H;i++){
      cout<<map[i][0];
      for(int j=1;j<W;j++)
        cout<<' '<<map[i][j];
      cout<<endl;
    }
  }
}