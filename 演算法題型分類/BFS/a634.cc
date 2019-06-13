// 中等進階題, 讀取有點麻煩, 題目沒說但保證存在一條路徑從起點到終點
// 展開BFS時,紀錄路徑, 字典序決定展開的順序
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

struct Edge{ int x, y, d; string ss; } ed, now, nxt;
int main(){
  int dx[8]={-2,-2,-1,-1, 1, 1, 2, 2};
  int dy[8]={-1, 1,-2, 2,-2, 2,-1, 1};
  string pos_x="abcdefgh", pos_y="12345678";

  for(string ss; cin>>ss;){
    int dis[8][8];
    memset(dis,0x7f,sizeof(dis));
    vector<string> ans;
    queue<Edge> Q;
    Q.push( {ss[0]-'a',ss[1]-'1',0,ss} );
    // 讀取終點
    cin>>ss;
    ed.x=ss[0]-'a', ed.y=ss[1]-'1', ed.d=0x7fffffff;
    // 讀取路障, 路障道起點的距離設定為-1代表無法被更新
    while(cin>>ss and ss!="xx")
      dis[ss[0]-'a'][ss[1]-'1']=-1;
    // BFS
    while(!Q.empty()){
      now=Q.front();  Q.pop();
      // 現在的點到起點的距離一樣時一樣要更新
      if(dis[now.x][now.y]<now.d) continue;
      dis[now.x][now.y]=now.d;
      if(dis[ed.x][ed.y]<now.d) break;
      else if(dis[ed.x][ed.y]==now.d and now.x==ed.x and now.y==ed.y){ ans.push_back(now.ss); continue; }
      nxt.d=now.d+1;
      for(int i=0;i<8;i++){
        nxt.x=now.x+dx[i], nxt.y=now.y+dy[i];
        if(0<=nxt.x and nxt.x<8 and 0<=nxt.y and nxt.y<8 and dis[nxt.x][nxt.y]>nxt.d)
          nxt.ss=now.ss+' '+pos_x[nxt.x]+pos_y[nxt.y],  Q.push(nxt);
      }
    }
    cout<<"The shortest solution is "<<dis[ed.x][ed.y]<<" move(s)."<<endl;
    for(int i=0;i<ans.size();i++)
      cout<<"Solution: "<<ans[i]<<endl;
  }
}