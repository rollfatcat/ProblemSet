#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MaxN 1000
#define INF 99

int r, c;
int x1, x2, y1, y2, tmp;
int dis[MaxN][MaxN];
char t[MaxN][MaxN];

struct Node{ int x, y; } now, nxt;
struct compare{ bool operator()(Node &a, Node &b){ return dis[a.x][a.y]>dis[b.x][b.y]; }  };
priority_queue<Node,vector<Node>,compare> PQ;
void ColorMap(int type){
  if(x1>x2) tmp=x1, x1=x2, x2=tmp;
  if(y1>y2) tmp=y1, y1=y2, y2=tmp;
  if(type==1)
    for(int i=x1;i<=x2;i++)
      for(int j=y1;j<=y2;j++)
        PQ.push({i,j}), dis[i][j]=0;
  else
    for(int i=x1;i<=x2;i++)
      for(int j=y1;j<=y2;j++)
        t[i][j]=type;
}
int main(){
  int dx[4]={0,0,-1,1};
  int dy[4]={-1,1,0,0};
  while(cin>>r>>c){
    for(int i=0;i<r;i++)
      for(int j=0;j<c;j++)
        dis[i][j]=INF, t[i][j]=0;
    while(!PQ.empty())
      PQ.pop();
    string msg;
    cin>>msg>>x1>>y1>>x2>>y2;
    ColorMap(1);
    cin>>msg>>x1>>y1>>x2>>y2;
    ColorMap(2);
    cin>>msg;
    while(cin>>msg){
      if(msg==".be")  break;
      x1=0;
      for(int i=0;i<msg.length();i++)
        x1=10*x1+(msg[i]-'0');
      cin>>y1>>x2>>y2;
      ColorMap(3);
    }

    int path=INF;
    bool find_end=false;
    for(;!PQ.empty() and !find_end; ){
      now=PQ.top(); PQ.pop();
      if(t[now.x][now.y])
        continue;
      t[now.x][now.y]=3;
      for(int i=0;i<4;i++){
        nxt.x=now.x+dx[i];
        nxt.y=now.y+dy[i];
        if(nxt.x<0 or nxt.x>=r or nxt.y<0 or nxt.y>=c or dis[nxt.x][nxt.y]!=INF or t[nxt.x][nxt.y]==3)
          continue;
        dis[nxt.x][nxt.y]=dis[now.x][now.y]+1;
        if(t[nxt.x][nxt.y]==2)
          path=dis[nxt.x][nxt.y], find_end=true;
        PQ.push(nxt);
      }
    }
    if(path==INF) cout<<"no path\n";
    else  cout<<path<<endl;
  }
}