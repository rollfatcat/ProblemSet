/* 這個題目內的格子移動時會『限制方向』
 * 當點和點之間『不存在連線』代表不能由該方向走到相鄰的格子
 * 需要紀錄每一格格子的4個方向可不可以延該方向走到相鄰格子，
 * 不存在連線時也要標記狀態改為1(預設是0代表可以走過去)
 * 一樣具有方格迷宮找最短距離的特性：先到的格子一定是最短距離一找到終點就可以跳離迴圈(6ms)
 */
#include<bits/stdc++.h>
using namespace std;

bool MAP[1000][1000][4]; // 0:下 1:上 2:左 3:右
int step[1000][1000];
int mv[4]={1,-1,0,0};
struct NODE{ int x,y,v=0; } st, ed, now, nxt;
int main(){

  for(int R,C,K;scanf("%d %d",&R,&C)!=EOF;){
    scanf("%d %d %d %d %d",&st.x,&st.y,&ed.x,&ed.y,&K);

    memset(MAP,0,sizeof(MAP));
    memset(step,0xff,sizeof(step));
    for(int x1,x2,y1,y2; K; K--){
      scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
      if(x1==x2){
        for(int i=y1;i<y2;i++)
          MAP[x1][i][3]=MAP[x1][i+1][2]=true;
      }else{ // y1==y2
        for(int i=x1;i<x2;i++)
          MAP[i][y1][0]=MAP[i+1][y1][1]=true;
      }
    }
    queue<NODE> Q;
    Q.push(st);
    for(int t=0;!Q.empty();t++){
      now=Q.front();  Q.pop();
      if(step[now.x][now.y]>=0) continue;
      step[now.x][now.y]=now.v;
      if(now.x==ed.x and now.y==ed.y) break;
      nxt.v=now.v+1;
      for(int i=0;i<4;i++)
        if(MAP[now.x][now.y][i]==0){
          nxt.x=now.x+mv[ i ],
          nxt.y=now.y+mv[3-i];
          if(nxt.x>=0 and nxt.x<R and nxt.y>=0 and nxt.y<C and step[nxt.x][nxt.y]==-1)
            Q.push(nxt);
        }
    }
    if(step[ed.x][ed.y]==-1)
      step[ed.x][ed.y]=10080;
    printf("%d\n",step[ed.x][ed.y]);
  }
}