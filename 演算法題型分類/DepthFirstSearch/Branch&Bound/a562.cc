/* 剪枝的版本(1.8s/336KB)：
 * (1) 只有當走到盡頭時才做判斷
 * (2) 當(目前)最佳解出現的時候，紀錄已經拜訪過的地圖狀態，
 *     以後枚舉起點時避開處於最佳解的地圖中的點。
 */
#include<bits/stdc++.h>
using namespace std;

bool use[101];
bool vis[8][8];
bool rec[8][8];
int mapn[8][8];
int N, maxL;

void DFS(int x,int y,int L){
  vis[x][y]=use[ mapn[x][y] ]=1;
  // 只有走到『盡頭』時才做最長邊的判斷
  bool getEND=1;
  if(x>0   and vis[x-1][y]==0 and use[ mapn[x-1][y] ]==0) getEND=0,DFS(x-1,y,L+1);
  if(x<N-1 and vis[x+1][y]==0 and use[ mapn[x+1][y] ]==0) getEND=0,DFS(x+1,y,L+1);
  if(y>0   and vis[x][y-1]==0 and use[ mapn[x][y-1] ]==0) getEND=0,DFS(x,y-1,L+1);
  if(y<N-1 and vis[x][y+1]==0 and use[ mapn[x][y+1] ]==0) getEND=0,DFS(x,y+1,L+1);
  if(getEND and L>maxL){
    maxL=L;
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        rec[i][j]=vis[i][j];
  }
  vis[x][y]=use[ mapn[x][y] ]=0;
  return;
}
int main(){
  int caseT;

  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        scanf("%d",&mapn[i][j]);
    memset(use,0,sizeof(use));
    memset(vis,0,sizeof(vis));
    memset(rec,0,sizeof(rec));
    maxL=0;
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        if(rec[i][j]==0)
          DFS(i,j,1);
    printf("%d\n",maxL);
  }
}
/*
2
4
1 3 5 7
2 11 6 9
6 13 8 2
8 17 10 4
3
1 2 3
1 2 4
1 2 3
*/