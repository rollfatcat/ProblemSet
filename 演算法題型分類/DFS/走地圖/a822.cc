// 和 d404-uva10285 的滑雪場做法相似但輸出要求不同
/* (1) 建圖 ( 200ms -> 34ms )，不需要轉成 1D 查看位置有沒有被標記過，直接在 2D 上確認
 * (2) DFS找到地圖上的最低點
 * (3) 輸出地圖上有幾個 local minimum 和 擁有最多的匯流點
 */
#include<bits/stdc++.h>
using namespace std;

const int maxN=500;
int N, size, cnt[maxN*maxN];
int mapH[maxN][maxN]={}, to[maxN][maxN];
int Go_lower(int x,int y){
  if(to[x][y]==-1){
    int nxt_x=x, nxt_y=y, nxt_v=mapH[x][y];
    if(x>0 and nxt_v>mapH[x-1][y])   nxt_v=mapH[x-1][y], nxt_x=x-1, nxt_y=y;
    if(y>0 and nxt_v>mapH[x][y-1])   nxt_v=mapH[x][y-1], nxt_x=x, nxt_y=y-1;
    if(x+1<N and nxt_v>mapH[x+1][y]) nxt_v=mapH[x+1][y], nxt_x=x+1, nxt_y=y;
    if(y+1<N and nxt_v>mapH[x][y+1]) nxt_v=mapH[x][y+1], nxt_x=x, nxt_y=y+1;
    to[x][y]=(nxt_v==mapH[x][y])? mapH[x][y]: Go_lower(nxt_x,nxt_y);
  }
  return to[x][y];
}
int main(){
  int x, y;
  scanf("%d %d %d",&N,&x,&y);
  // --- Produce Map ---
  for(int H=1;H<=N*N;H++){
    // ---現在這個位置已經有標記高度時往下個位置移動---
    while(mapH[x][y]){
      if((++y)==N) x++, y=0;
      if(x==N) x=0;
    }
    // ---高度標記---
    mapH[x][y]=H;
    // ---往下一個位置---
    y+=H, x+=(y/N), x%=N, y%=N;
  }
  // --- Go lower ---
  memset(to,0xff,sizeof(to));
  memset(cnt,0,sizeof(cnt));
  int maxCnt=0, tCnt=0;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
      int node_end=Go_lower(i,j);
      if(!cnt[node_end])
        tCnt++;
      cnt[node_end]++;
      maxCnt=max(maxCnt,cnt[node_end]);
    }
  // ---輸出---
  printf("%d %d\n",tCnt,maxCnt);
}