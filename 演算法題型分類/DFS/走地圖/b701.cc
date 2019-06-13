#include<iostream>
using namespace std;
#define MaxN 512

int map[MaxN][MaxN];
int m, n, area, w, e, s;

void DFS(int x, int y){
  if(x<0 or y<0 or x>=m or y>=n or !map[x][y])
    return;
  area++, map[x][y]=0;
  if(w>y) w=y;
  if(e<y) e=y;
  if(s<x) s=x;
  DFS(x-1, y);
  DFS(x+1, y);
  DFS(x, y-1);
  DFS(x, y+1);
}
int main(){
  while(scanf("%d %d",&m,&n)!=EOF){
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        scanf("%d",&map[i][j]);
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        if(map[i][j]){
          area=0, w=e=j, s=i;
          DFS(i,j);
          printf("%d %d %d %d %d\n",w,i,e,s,area);
        }
  }
}