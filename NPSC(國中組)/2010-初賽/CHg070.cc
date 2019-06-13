// PriorityQueue+BFS走地圖
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct Node{
  int x, y, v;
  bool operator<(const Node &other)const{ return v>other.v; }
}now, nxt;
int main(){
  int caseNum, R, C, N, cnt;
  int dx[4]={0,0,1,-1};
  int dy[4]={1,-1,0,0};
  int map[100][100];

  cin>>caseNum;
  while(caseNum--){
    priority_queue< Node, vector<Node> > PQ;
    memset(map,0xff,sizeof(map));
    cin>>R>>C>>N;
    for(int i=0;i<N;i++)
      cin>>now.x>>now.y>>now.v,
      now.x--,now.y--,
      PQ.push(now);
    for(cnt=R*C;cnt>0;){
      now=PQ.top();  PQ.pop();
      if(map[now.x][now.y]>-1)  continue;
      cnt--;
      map[now.x][now.y]=now.v;
      nxt.v=now.v+1;
      for(int i=0;i<4;i++){
        nxt.x=now.x+dx[i],  nxt.y=now.y+dy[i];
        if(nxt.x<0 or R<=nxt.x or nxt.y<0 or C<=nxt.y or map[nxt.x][nxt.y]>-1)  continue;
          PQ.push(nxt);
      }
    }
    // Output
    for(int i=0;i<R;i++){
      cout<<map[i][0];
      for(int j=1;j<C;j++)
        cout<<' '<<map[i][j];
      cout<<endl;
    }
    if(caseNum) cout<<endl;
  }
}