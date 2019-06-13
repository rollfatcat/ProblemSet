// 題目要求找到由左上到達右下的『兩條路徑』
// (X) 找到第一條路徑後根據記錄通過的格子位置回朔後設定為0，再重新找第二條路徑
// (O) 等價於找到兩條『不相交』的路徑 => 雙線動態規劃
#include<bits/stdc++.h>
using namespace std;

int org[11][11]={};
int dpn[11][11]={};
int dir[11][11]={}; // 紀錄第一次動態規劃的方向，回朔時讓路徑上的數字歸零

void BackTace(int x,int y){
  org[x][y]=0;
  if(dir[x][y]==1) BackTace(x-1,y-1);
  if(dir[x][y]==2) BackTace(x-1,y); // 從左邊
  if(dir[x][y]==3) BackTace(x,y-1); // 從右邊
}
int main(){
  int N, x, y, n, maxv;

  scanf("%d",&N);
  while(scanf("%d%d%d",&x,&y,&n) and x)
    org[x][y]=n;
  // 最大路徑：第一次動態規劃
  dpn[1][1]=org[1][1];
  // 邊界設定
  for(int x1=2;x1<=N;x1++)
    dpn[x1][1]=dpn[x1-1][1]+org[x1][1],
    dir[x1][1]=2;
  for(int y1=2;y1<=N;y1++)
    dpn[1][y1]=dpn[1][y1-1]+org[1][y1],
    dir[1][y1]=3;
  // 雙層處理不是邊界的部分
  for(int x1=2;x1<=N;x1++)
    for(int y1=2;y1<=N;y1++)
      maxv=max(dpn[x1-1][y1],dpn[x1][y1-1]),
      dpn[x1][y1]=maxv+org[x1][y1],
      dir[x1][y1]=(maxv==dpn[x1-1][y1])? 2: (maxv==dpn[x1][y1-1])? 3: 1;

  n=dpn[N][N];
  //printf("%d\n",n);
  BackTace(N,N); // 回朔
  // 第二次動態規劃
  dpn[1][1]=org[1][1];
  for(int x1=2;x1<=N;x1++)
    dpn[x1][1]=dpn[x1-1][1]+org[x1][1], dir[x1][1]=2;
  for(int y1=2;y1<=N;y1++)
    dpn[1][y1]=dpn[1][y1-1]+org[1][y1], dir[1][y1]=3;
  for(int x1=2;x1<=N;x1++)
    for(int y1=2;y1<=N;y1++){
      maxv=max(max(dpn[x1-1][y1],dpn[x1][y1-1]),dpn[x1-1][y1-1]),
      dpn[x1][y1]=maxv+org[x1][y1],
      dir[x1][y1]=(maxv==dpn[x1-1][y])? 3: (maxv==dpn[x1][y-1])? 2: 1;
    }
  n+=dpn[N][N];
  printf("%d\n",n);
}
/*
8
2 3 13
2 6 6
3 5 7
4 4 14
5 2 21
5 6 4
6 3 15
7 2 14
0 0 0

3
1 2 3
1 3 9
2 1 2
2 2 8
2 3 5
3 1 5
3 2 7
0 0 0
======
0 3 9
2 8 5
5 7 0
// 34
*/