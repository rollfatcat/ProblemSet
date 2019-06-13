// 本質是BFS要計算某個時刻的某種顏色最多個數
// 染色模擬可以用位元取or計算
#include<iostream>
#include<cstring>
#include<queue>
#include<map>
using namespace std;

struct nn{ int x,y,c,t; }now, nxt;
int main(){
  /* 這樣命名顏色的好處就是可以用位元計算染色問題
  /* Y: 001  G: 011  D:111
  /* B: 010  P: 110
  /* R: 100  O: 101
  */
  map<char,int> table;
  table['Y']=1, table['B']=2, table['R']=4,
  table['G']=3, table['P']=6, table['O']=5, table['D']=7;

  int cnt[8], Board[100][100];
  bool vis[3][100][100];
  int dx[8]={-1,-1,-1, 0, 1, 1, 1, 0};
  int dy[8]={-1, 0, 1, 1, 1, 0,-1,-1};
  char c;

  for(int N; cin>>N;){
    memset(Board,0,sizeof(Board));
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    cnt[0]=N*N;
    queue<nn> Q;
    now.t=0;
    for(int i=0;i<3;i++)
      cin>>c>>now.x>>now.y, now.c=1<<i, Q.push(now);
    cin>>c;
    int Tnow=1, Xcolor=table[c], MaxCnt=0;
    while(!Q.empty()){
      now=Q.front(), Q.pop();
      // 時間點刷新時比較指定顏色的個數
      if(now.t==Tnow)
        MaxCnt=(MaxCnt<cnt[Xcolor])?cnt[Xcolor]:MaxCnt, Tnow++;
      // 把 R(4)->2, B(2)->1, Y(1)->0 找到對應紀錄有沒有走過的地圖
      int color=now.c/2;
      if(vis[color][now.x][now.y]) continue;
      // 標記走過的部分，把格子原本的顏色改成染色後的顏色
      vis[color][now.x][now.y]=true;
      cnt[Board[now.x][now.y]]--;
      Board[now.x][now.y]|=now.c;
      cnt[Board[now.x][now.y]]++;
      // 往四周染色
      nxt.t=now.t+1, nxt.c=now.c;
      for(int i=0;i<8;i++){
        nxt.x=now.x+dx[i],  nxt.y=now.y+dy[i];
        if(0<=nxt.x and nxt.x<N and 0<=nxt.y and nxt.y<N and !vis[color][nxt.x][nxt.y])
          Q.push(nxt);
      }
    }
    cout<<MaxCnt<<endl;
  }
}