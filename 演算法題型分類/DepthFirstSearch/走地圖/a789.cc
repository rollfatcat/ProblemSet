/* 簡單DFS找周圍最小值的位置延展過去
 * 這題的測資中並未提到一種情況：周圍8格中出現的最低值不一定是唯一的, 可能有兩格都是一樣的, 導致搜尋時的順序會影響最終結果。
 * int dx[8]={0,1,1, 1, 0,-1,-1,-1}, dy[8]={1,1,0,-1,-1,-1, 0, 1};
 */
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 13

int map[MaxN][MaxN];
int dx[8]={0,1,1, 1, 0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1, 0, 1};
bool vis[MaxN][MaxN];
void DFS(int x,int y){
  if(vis[x][y]==1)  return;
  vis[x][y]=1;
  int min_v=map[x][y], min_x=x, min_y=y;
  for(int i=0;i<8;i++){
    int nxt_x=x+dx[i],  nxt_y=y+dy[i];
    if(min_v>map[nxt_x][nxt_y])
      min_v=map[nxt_x][nxt_y], min_x=nxt_x, min_y=nxt_y;
  }
  DFS(min_x,min_y);
}
int main(){
  memset(map,0x3f,sizeof(map));
  while(scanf("%d",&map[1][1])!=EOF){
    for(int i=2;i<=11;i++)
      scanf("%d",&map[1][i]);
    for(int i=2;i<=11;i++)
      for(int j=1;j<=11;j++)
        scanf("%d",&map[i][j]);
    memset(vis,0,sizeof(vis));
    for(int stx,sty; cin>>stx>>sty and stx!=-1;)
      DFS(sty+1,stx+1);
    for(int i=1;i<=11;i++,printf("\n"))
      for(int j=1;j<=11;j++)
        printf("%c",(vis[i][j])?'*':'.');
  }
}