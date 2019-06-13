#include<bits/stdc++.h>
using namespace std;

const int INF=-(1<<30);
int DP[51][51][51][51]={};
int cost[51][51]={};
inline int MaxNum(int a, int b, int c, int d){ if(b>a) a=b;  if(c>a) a=c;  return (d>a)?d:a; }
int main(){
  // 初始化時把不合法的狀態改為INF 代表無法轉移到合法狀態 <- 時間耗在這邊
  for(int x1=0;x1<=50;x1++)
    for(int y1=0;y1<=50;y1++)
      for(int x2=0;x2<=50;x2++)
        for(int y2=0;y2<=50;y2++)
          if(x1==0 or y1==0 or x2==0 or y2==0)
            DP[x1][y1][x2][y2]=INF;
  for(int N;scanf("%d",&N)!=EOF;){
    for(int i=1;i<=N;i++)
      for(int j=1;j<=N;j++)
        scanf("%d",&cost[i][j]);
    DP[1][1][1][1]=cost[1][1]<<1;
    for(int x1=1;x1<=N;x1++)
      for(int y1=1;y1<=N;y1++)
        for(int x2=1;x2<=N;x2++)
          for(int y2=1;y2<=N;y2++){
            if(x1>1 or x2>1 or y1>1 or y2>1)
              DP[x1][y1][x2][y2]=MaxNum( DP[x1-1][y1][x2-1][y2],
                                         DP[x1-1][y1][x2][y2-1],
                                         DP[x1][y1-1][x2-1][y2],
                                         DP[x1][y1-1][x2][y2-1])+cost[x1][y1]+cost[x2][y2];
            if(x1==x2 and y1==y2)
              DP[x1][y1][x2][y2]-=cost[x1][y1];
          }
    printf("%d\n",DP[N][N][N][N]);
  }
}