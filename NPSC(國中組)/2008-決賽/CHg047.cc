// 題目保證迷宮的外圍一定有牆而且是長方形, 做簡單BFS
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct Node{ int x, y, d; } st, ed;
int main(){
  int R, C;
  int dx[4]={-1,1,0,0};
  int dy[4]={0,0,-1,1};
  char map[100][100];

  while(cin>>R and R){
    for(int i=0;i<R;i++){
      scanf("%s",map[i]);
      C=strlen(map[i]);
      for(int j=0;j<C;j++)
        if(map[i][j]=='K')
          st.x=i, st.y=j, st.d=0;
    }
    queue<Node> Q;
    Q.push(st); ed.d=-1;
    while(!Q.empty()){
      Node now=Q.front(); Q.pop();
      if(map[now.x][now.y]=='#') continue;
      else if(map[now.x][now.y]=='@'){ ed.d=now.d; break; }
      map[now.x][now.y]='#';
      Node nxt; nxt.d=now.d+1;
      for(int i=0;i<4;i++){
        nxt.x=now.x+dx[i],  nxt.y=now.y+dy[i];
        if(0<=nxt.x and nxt.x<R and 0<=nxt.y and nxt.y<C and map[nxt.x][nxt.y]!='#')
          Q.push(nxt);
      }
    }
    if(ed.d==-1)  cout<<"= =\""<<endl;
    else  cout<<ed.d<<endl;
  }
}