/* Query某一個數字時輸出該數字在地圖中最大連通面積 -> DFS
 */

#include<bits/stdc++.h>
using namespace std;

int area, R, C, char_map[30][30];
bool vis[30][30];
void DFS(int x,int y,int num){
  if(vis[x][y] or char_map[x][y]!=num) return;
  area++, vis[x][y]=1;
  if(x>0) DFS(x-1,y,num);
  if(y>0) DFS(x,y-1,num);
  if(x+1<R) DFS(x+1,y,num);
  if(y+1<C) DFS(x,y+1,num);
}
int main(){
  int maxArea[10];

  while(scanf("%d %d",&R,&C)==2){
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        scanf("%d",&char_map[i][j]);
    memset(vis,0,sizeof(vis));
    memset(maxArea,0,sizeof(maxArea));
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        if(!vis[i][j]){
          area=0;
          DFS(i,j,char_map[i][j]);
          if(area>1 and area>maxArea[ char_map[i][j] ])
            maxArea[ char_map[i][j] ]=area;
        }
    int Q, x;
    for(scanf("%d",&Q); Q--;)
      scanf("%d",&x),
      printf("%d\n",maxArea[x]);
  }
}