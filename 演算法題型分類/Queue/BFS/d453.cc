// 輸入時數字間沒有空白 000000會被當成一個整數0而不是6個0
// 請用字串輸入
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MaxN 101

struct Node{ int x, y, d;} st, ed, now, nxt;
int main(){
  int T, r, c;
  string ss;
  int dx[4]={0,0,-1,1};
  int dy[4]={-1,1,0,0};
  bool vis[MaxN][MaxN];


  cin>>T;
  while(T--){
    cin>>r>>c>>st.x>>st.y>>ed.x>>ed.y;
    st.x--, st.y--, ed.x--, ed.y--;

    for(int i=0;i<r;i++){
      cin>>ss;
      for(int j=0;j<c;j++)
        vis[i][j]=(ss[j]=='1');
    }
    st.d=1, ed.d=0;
    queue<Node> Q;
    Q.push(st);
    while(!Q.empty()){
      now=Q.front(); Q.pop();
      if(vis[now.x][now.y]) continue;
      if(now.x==ed.x and now.y==ed.y){
        ed.d=now.d; break;
      }
      vis[now.x][now.y]=1;
      nxt.d=now.d+1;
      for(int i=0;i<4;i++){
        nxt.x=now.x+dx[i],  nxt.y=now.y+dy[i];
        if(nxt.x<0 or nxt.y<0 or nxt.x>=r or nxt.y>=c or vis[nxt.x][nxt.y])
          continue;
        Q.push(nxt);
      }
    }
    cout<<ed.d<<endl;
  }
}