#include<bits/stdc++.h>
using namespace std;

const int INF=-(1<<30);
int DP[51][51][51][51]={};
int cost[51][51]={};
int main(){

  for(int N;scanf("%d",&N)!=EOF;){
    for(int i=1;i<=N;i++)
      for(int j=1;j<=N;j++)
        scanf("%d",&cost[i][j]);
    for(int x1=1;x1<=N;x1++)
      for(int y1=1;y1<=N;y1++)
        for(int x2=1;x2<=N;x2++)
          for(int y2=1;y2<=N;y2++){
            int maxN=INF;
            // 邊界判斷：避免從『不合法』的狀態轉移過來
            if(x1>1 and x2>1) maxN=max(maxN,DP[x1-1][y1][x2-1][y2]);
            if(x1>1 and y2>1) maxN=max(maxN,DP[x1-1][y1][x2][y2-1]);
            if(y1>1 and x2>1) maxN=max(maxN,DP[x1][y1-1][x2-1][y2]);
            if(y1>1 and y2>1) maxN=max(maxN,DP[x1][y1-1][x2][y2-1]);
            DP[x1][y1][x2][y2]=(maxN==INF)?0:maxN;
            DP[x1][y1][x2][y2]+=cost[x1][y1]+cost[x2][y2];
            if(x1==x2 and y1==y2)
              DP[x1][y1][x2][y2]-=cost[x1][y1];
          }
    printf("%d\n",DP[N][N][N][N]);
  }
}