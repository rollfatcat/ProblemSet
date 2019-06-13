// 有趣而且有些難度的BFS
// 人要逃開迷宮時,火也會跟著展開
// 觀察第1筆測資：同時間點人先做展開, 但是人真實走到那一格才可以更新距離
// 觀察第2筆測資：同時間點在同一格時火會先佔到格子 => 拿到火的位置時把四周的距離設定成-1防止更新
// 結論：當時間點t時, 人先展開走到四周但只更新目前的距離而 火展開時更新四周的距離
// 停止條件,人的#Node=0
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define MaxN 1002
#define INF 0x7fffffff

struct Node{ int x, y, d; bool s; } now, nxt;
int main(){
  int caseNum, R, C, outR, outC;
  int dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0};
  int dis[MaxN][MaxN], step, cnt;
  char map[MaxN][MaxN];

  cin>>caseNum;
  for( int t=1; t<=caseNum; t++){
    //
    vector<Node> F;
    queue<Node> Q;
    //
    cin>>R>>C, outR=R+1, outC=C+1;
    for(int i=1;i<=R;i++)
      for(int j=1;j<=C;j++){
        cin>>map[i][j];
        if(map[i][j]=='J')      dis[i][j]=INF,Q.push({i,j,0,0});
        else if(map[i][j]=='F') dis[i][j]=-1, F.push_back({i,j,-1,1});
        else if(map[i][j]=='#') dis[i][j]=-1;
        else                    dis[i][j]=INF;
      }
    // 把四周的狀態設定成 INF, 代表可以走到(注意火不能燒到!!)
    for(int i=1;i<=C;i++)
      dis[0][i]=dis[outR][i]=INF;
    for(int i=1;i<=R;i++)
      dis[i][0]=dis[i][outC]=INF;
    // 人要先展開, 讀到火燄的位置時要先存起來
    for(int i=0;i<F.size();i++)
      Q.push(F[i]);

    for(step=INF, cnt=1; cnt>0; ){
      now=Q.front();  Q.pop();
      nxt.s=now.s; // Node狀態延續
      if(now.s){ //火展開時碰到牆壁就不能燒過去=>牆和火的狀態設定成-1
        nxt.d=now.d;
        for(int i=0;i<4;i++){
          nxt.x=now.x+dx[i],  nxt.y=now.y+dy[i];
          // 火焰能展開的範圍只存在迷宮內
          if(0<nxt.x and nxt.x<=R and 0<nxt.y and nxt.y<=C and dis[nxt.x][nxt.y]!=-1)
            dis[nxt.x][nxt.y]=-1,  Q.push(nxt);
        }
      }else{
        cnt--; // Node狀態是人 pop出來之後不管能不能更新,數量要-1
        if(now.x==0 or now.x>R or now.y==0 or now.y>C){  step=now.d; break; }
        if(dis[now.x][now.y]<=now.d)  continue;
        dis[now.x][now.y]=now.d;
        nxt.d=now.d+1;
        for(int i=0;i<4;i++){
          nxt.x=now.x+dx[i],  nxt.y=now.y+dy[i];
          if(0<=nxt.x and nxt.x<=R+1 and 0<=nxt.y and nxt.y<=C+1 and dis[nxt.x][nxt.y]>nxt.d)
            cnt++, Q.push(nxt);
        }
      }
    }
    if(step==INF) cout<<"IMPOSSIBLE"<<endl;
    else cout<<step<<endl;
  }
}

/*
2
4 4
####
#JF#
#..#
#..#
3 3
###
#J.
#.F
*/