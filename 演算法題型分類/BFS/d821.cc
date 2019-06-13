// 題目要找出『最短路徑的方法數』，但可以上/下/左/右四個方向移動時...
// 解法：用BFS做Bottom-Up
#include<iostream>
#include<queue>
using namespace std;
#define MaxN 50

struct Node{ int x, y; } st, ed, now, nxt;
int main(){
  bool vis[MaxN][MaxN];
  int map[MaxN][MaxN];
  int N, M;
  int dx[4]={ 0, 0, 1,-1};
  int dy[4]={ 1,-1, 0, 0};

  while(cin>>N>>M){
    for(int i=0;i<N;i++)
      for(int j=0;j<M;j++)
        cin>>vis[i][j], map[i][j]=0;
    cin>>st.x>>st.y>>ed.x>>ed.y;

    map[st.x][st.y]=1;
    queue<Node> Q;
    Q.push(st);
    int t=0;
    while(!Q.empty()){
      now=Q.front();
      Q.pop();
      if(vis[now.x][now.y]==0){
        t++;
        vis[now.x][now.y]=1;
        if(now.x==ed.x and now.y==ed.y)
          break;
        for(int i=0;i<4;i++){
          nxt.x=now.x+dx[i];
          nxt.y=now.y+dy[i];
          if(nxt.x<0 or nxt.y<0 or nxt.x>=N or nxt.y>=M)
            continue;
          if(vis[nxt.x][nxt.y]==0)
            map[nxt.x][nxt.y]=(map[nxt.x][nxt.y]+map[now.x][now.y])%100000;
          Q.push(nxt);
        }
      }
    }
    cout<<map[ed.x][ed.y]<<endl;
  }
}