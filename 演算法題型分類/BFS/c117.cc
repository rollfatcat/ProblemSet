#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct pos{ int x, y, t; } ed, now;
int main(){
  string stss, edss;
  bool vis[8][8];
  int dis[8][8];

  while(cin>>stss>>edss){
    now.x=stss[0]-'a', now.y=stss[1]-'1', now.t=0;
    ed.x=edss[0]-'a', ed.y=edss[1]-'1';
    memset(vis,0,sizeof(vis));
    queue<pos>Q;
    Q.push(now);
    while(!Q.empty()){
      now=Q.front(), Q.pop();
      if( now.x<0 or now.y<0 or now.x>=8 or now.y>=8 or vis[now.y][now.x] )
        continue;
      vis[now.y][now.x]=1;
      dis[now.y][now.x]=now.t++;
      if(now.y==ed.y and now.x==ed.x) // 第一次更新的距離一定是最短距離, 只要找到終點就跳開
        break;
      Q.push( {now.x+1,now.y-2,now.t} );
      Q.push( {now.x+2,now.y-1,now.t} );
      Q.push( {now.x+2,now.y+1,now.t} );
      Q.push( {now.x+1,now.y+2,now.t} );
      Q.push( {now.x-1,now.y+2,now.t} );
      Q.push( {now.x-2,now.y+1,now.t} );
      Q.push( {now.x-2,now.y-1,now.t} );
      Q.push( {now.x-1,now.y-2,now.t} );
    }
    cout<<"To get from "<<stss<<" to "<<edss<<" takes "<<dis[ed.y][ed.x]<<" knight moves.\n";
  }
}