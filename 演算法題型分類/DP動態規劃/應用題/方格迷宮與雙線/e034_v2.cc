// 三維動態規劃版本(6ms)
/* 因為『同步』的性質，可以改為窮舉步數+兩個人的y座標
 * 利用同步和y座標反推x座標，狀態轉移的部份繼承四維的版本(91ms)
 */
#include<bits/stdc++.h>
using namespace std;

const int INF=-(1<<30);
int DP[101][51][51]={};
int cost[51][51]={};
int main(){
  for(int N;scanf("%d",&N)!=EOF;){
    for(int i=1;i<=N;i++)
      for(int j=1;j<=N;j++)
        scanf("%d",&cost[i][j]);
    int x1, y1, x2, y2, Cmin;
    for(int step=2;step<=(N<<1);step++){
      Cmin=(N>step-1)?step-1:N; //y座標的範圍落在(1,N)
      for(y1=1;y1<=Cmin;y1++){
        for(x1=step-y1; x1>N; y1++,x1--);  //x座標的範圍落在(1,N)
        for(y2=1;y2<=Cmin;y2++){ //避免路徑出現交叉 y2從 y1+1开始
          for(x2=step-y2; x2>N; y2++,x2--);
          int maxN=INF;
          // 邊界判斷：避免從『不合法』的狀態轉移過來
          if(x1>1 and x2>1) maxN=max(maxN,DP[step-1][y1][y2]);
          if(x1>1 and y2>1) maxN=max(maxN,DP[step-1][y1][y2-1]);
          if(y1>1 and x2>1) maxN=max(maxN,DP[step-1][y1-1][y2]);
          if(y1>1 and y2>1) maxN=max(maxN,DP[step-1][y1-1][y2-1]);
          DP[step][y1][y2]=(maxN==INF)?0:maxN;
          DP[step][y1][y2]+=cost[x1][y1]+cost[x2][y2];
          if(x1==x2 and y1==y2)
            DP[step][y1][y2]-=cost[x1][y1];
        }
      }
    }
    printf("%d\n",DP[N<<1][N][N]);
  }
}
