// 請用scanf("%s",s)

#include<iostream>
using namespace std;
#define MaxN 505

bool map[MaxN][MaxN];
int m, n, numG, SizeG, MaxG;
int dx[4]={ 0, 0, 1,-1};
int dy[4]={-1, 1, 0, 0};
void DFS(int x, int y){
  SizeG++;
  map[x][y]=0;
  for(int i=0;i<4;i++){
    int new_x=x+dx[i];
    int new_y=y+dy[i];
    if(new_x<0 or new_y<0 or new_x>=m or new_y>=n or !map[new_x][new_y])
      continue;
    DFS(new_x,new_y);
  }
}
int main(){
  char ss[MaxN];
  while(scanf("%d %d",&m,&n)!=EOF){
    for(int i=0;i<m;i++){
      scanf("%s",&ss[0]);
      for(int j=0;j<n;j++)
        map[i][j]=(ss[j]=='J');
    }
    numG=MaxG=0;
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        if(map[i][j]){
          numG++;
          SizeG=0;
          DFS(i,j);
          if(MaxG<SizeG)
            MaxG=SizeG;
        }
    printf("%d %d\n",numG,MaxG);
  }
}