/* 題目的種族定義是『相鄰的相同數字』屬於同一種族(但即使數字相同但不相鄰就視為不同種族)
 * 所以第二筆測資中有"4"個種族，同一個種族個數最大是"2"
 */

#include<bits/stdc++.h>
using namespace std;

int R, C, OneN;
char mapss[100][100];

void DFS(int x,int y,char t){
  if(mapss[x][y]!=t) return;
  mapss[x][y]='0', OneN++;
  if(x>0){
              DFS(x-1,  y,t);
    if(y>0)   DFS(x-1,y-1,t);
    if(y<C-1) DFS(x-1,y+1,t);
  }
  if(y>0)  DFS(  x,y-1,t);
  if(y<C-1)DFS(  x,y+1,t);
  if(x<R-1){
              DFS(x+1,  y,t);
    if(y>0)   DFS(x+1,y-1,t);
    if(y<C-1) DFS(x+1,y+1,t);
  }
}
int main(){
  while(scanf("%d%d",&R,&C) and R){
    for(int i=0;i<R;i++)
      scanf("%s",mapss[i]);
    int maxN=0, Gnum=0;
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        if(mapss[i][j]>'0')
          Gnum++,
          OneN=0,
          DFS(i,j,mapss[i][j]),
          maxN=max(maxN,OneN);
    puts( (Gnum>maxN)?"choas":"peace" );
  }
}
