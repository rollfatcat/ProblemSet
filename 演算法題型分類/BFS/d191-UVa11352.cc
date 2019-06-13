
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MaxN 100

struct Node{ int x, y, d;} st, ed, now, nxt;

int main(){
  int T, r, c;
  string ss;
  bool map[MaxN][MaxN];

  cin>>T;
  while(T--){
    cin>>r>>c;
    memset(map,0,sizeof(map));
    queue<Node> Q;
    int move_j[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    int move_k[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

    for(int i=0;i<r;i++){
      cin>>ss;
      for(int j=0;j<c;j++)
        if(ss[j]=='Z'){
          map[i][j]=1;
          for(int k=0;k<8;k++){
            int x=i+move_j[k][0], y=j+move_j[k][1];
            if(0<=x and x<r and 0<=y and y<c)
              map[x][y]=1;
          }
        }
        else if(ss[j]=='B')
          ed.x=i, ed.y=j, ed.d=-1;
        else if(ss[j]=='A')
          st.x=i, st.y=j, st.d=0;
    }
    map[st.x][st.y]=map[ed.x][ed.y]=0;
    Q.push(st);
    while(!Q.empty()){
      now=Q.front();  Q.pop();
      if(map[now.x][now.y]) continue;
      if(now.x==ed.x and now.y==ed.y){
        ed.d=now.d; break;
      }
      map[now.x][now.y]=1;
      nxt.d=now.d+1;
      for(int i=0;i<8;i++){
        nxt.x=now.x+move_k[i][0], nxt.y=now.y+move_k[i][1];
        if(0<=nxt.x and nxt.x<r and 0<=nxt.y and nxt.y<c and !map[nxt.x][nxt.y])
          Q.push(nxt);
      }
    }
    if(ed.d==-1)  cout<<"King Peter, you can't go now!\n";
    else cout<<"Minimal possible length of a trip is "<<ed.d<<endl;
  }
}