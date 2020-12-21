// DP解題
#include<iostream>
using namespace std;
#define MaxN 101

int main(){
  // 輸入加速
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r, c, map[MaxN][MaxN];

  for(int caseNum=1;cin>>r>>c;caseNum++){
    for(int i=0;i<r;i++)
      for(int j=0;j<c;j++)
        cin>>map[i][j];
    for(int i=1;i<r;i++)
      map[i][0]+=map[i-1][0];
    for(int i=1;i<c;i++)
      map[0][i]+=map[0][i-1];
    for(int i=1;i<r;i++)
      for(int j=1;j<c;j++)
        map[i][j]=min(map[i-1][j],map[i][j-1])+map[i][j];
    printf("Case #%d :\n%d\n",caseNum,map[r-1][c-1]);
  }
}