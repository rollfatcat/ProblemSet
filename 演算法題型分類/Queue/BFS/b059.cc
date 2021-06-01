#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MaxN 100

struct Node{int x, y, d;} ed, now, nxt, obs;
int main(){
  int n, x, y;
  bool map[MaxN][MaxN], vis[MaxN][MaxN];
  int move[8][2]={{-3,-1},{-3,1},{-1,3},{1,3},{3,1},{3,-1},{1,-3},{-1,-3}};
  int judge[4][2]={{-1,0},{0,1},{1,0},{0,-1}}; // 上左下右

  while(cin>>n){
    memset(map,0,sizeof(map));
    memset(vis,0,sizeof(vis));
    while(n--)
      cin>>x>>y,  map[x][y]=vis[x][y]=1;
    cin>>x>>y;
    cin>>ed.x>>ed.y;  ed.d=-1;
    queue<Node> Q;
    Q.push({x,y,0});
    while(!Q.empty()){
      now=Q.front();  Q.pop();
      if(vis[now.x][now.y]) continue;
      if(now.x==ed.x and now.y==ed.y){
        ed.d=now.d; break;
      }
      vis[now.x][now.y]=1;
      nxt.d=now.d+1;
      for(int i=0;i<4;i++){
        obs.x=now.x+judge[i][0],  obs.y=now.y+judge[i][1];
        if(map[obs.x][obs.y])
          continue;
        nxt.x=now.x+move[2*i][0], nxt.y=now.y+move[2*i][1];
        if(0<=nxt.x and nxt.x<100 and 0<=nxt.y and nxt.y<100 and !map[nxt.x][nxt.y])
          Q.push(nxt);
        nxt.x=now.x+move[2*i+1][0], nxt.y=now.y+move[2*i+1][1];
        if(0<=nxt.x and nxt.x<100 and 0<=nxt.y and nxt.y<100 and !map[nxt.x][nxt.y])
          Q.push(nxt);
      }
    }
    if(ed.d==-1)  cout<<"impossible\n";
    else  cout<<ed.d<<endl;
  }
}
