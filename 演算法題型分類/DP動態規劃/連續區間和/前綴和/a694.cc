// 『二維』陣列都要印出來確認
// 注意輸入的二維座標和二維陣列的對應
#include<iostream>
#include<cstring>
using namespace std;

int main(){
  int n, m;
  int num[501][501];
  int sum1[501][501], sum2[501][501];
  int x1, y1, x2, y2;
  while(scanf("%d%d",&n,&m)!=EOF){
    memset(sum1,sizeof(sum1),0);
    memset(sum2,sizeof(sum2),0);
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        scanf("%d",&num[i][j]);
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        sum1[i+1][j+1]=sum1[i+1][j]+num[i][j];
    for(int j=1;j<=n;j++)
      for(int i=1;i<=n;i++)
        sum2[i][j]=sum2[i-1][j]+sum1[i][j];

    while(m--){
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      printf("%d\n",sum2[x2][y2]+sum2[x1-1][y1-1]-sum2[x1-1][y2]-sum2[x2][y1-1]);
    }
  }
}