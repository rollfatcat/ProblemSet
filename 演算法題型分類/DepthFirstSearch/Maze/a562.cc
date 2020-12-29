// 最簡單的DFS版本(9.6s/328KB)
#include<bits/stdc++.h>
using namespace std;

bool use[101];
bool vis[8][8];
int mapn[8][8];
int mv[4]={1,-1,0,0};
int N, nowL;

void DFS(int x,int y,int L){
  if(x==-1 or x==N or y==-1 or y==N) return; // 走到邊界
  if(vis[x][y] or use[ mapn[x][y] ]) return; // 這格已經走過或是這格的數字已經存在
  // 通過上述的檢驗後將狀態改標記
  vis[x][y]=use[ mapn[x][y] ]=1;
  nowL=max(nowL,++L);
  // 往四周延伸
  DFS(x-1,y,L),
  DFS(x+1,y,L),
  DFS(x,y-1,L),
  DFS(x,y+1,L);
  // 狀態還原
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
    int maxL=0;
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++){
        nowL=0;
        DFS(i,j,0);
        maxL=max(maxL,nowL);
      }
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