// 題目要求找到由左上到達右下的『兩條路徑』
// (x) 找到第一條路徑後根據記錄通過的格子位置回朔後設定為0，再重新找第二條路徑
// (O) 等價於找到兩條『不相交』的路徑 => 雙線動態規劃
#include<bits/stdc++.h>
using namespace std;

int num[11][11]={};
int DP[11][11][11][11]={};

inline int maxv(int a,int b,int c,int d){
  if(b>a) a=b;
  if(c>a) a=c;
  return (d>a)? d: a;
}
int main(){
  int N, x, y, n;

  scanf("%d",&N);
  while(scanf("%d%d%d",&x,&y,&n) and x)
    num[x][y]=n;
  for(int x1=1;x1<=N;x1++)
    for(int y1=1;y1<=N;y1++)
      for(int x2=1;x2<=N;x2++)
        for(int y2=1;y2<=N;y2++){
          // 將『相交問題』轉換為兩條路線一起出發，並且把『相交』的情況獨立出來判斷
          DP[x1][y1][x2][y2]=maxv(DP[x1-1][y1][x2-1][y2],
                                  DP[x1-1][y1][x2][y2-1],
                                  DP[x1][y1-1][x2-1][y2],
                                  DP[x1][y1-1][x2][y2-1])+num[x1][y1]+num[x2][y2];
          //當x1==x2且y1==y2時，說明兩個人相交了，所以這裡應該減去一個人的動態規劃價值
          if(x1==x2 and y1==y2)
            DP[x1][y1][x2][y2]-=num[x1][y1];
        }
  printf("%d\n",DP[N][N][N][N]);
}