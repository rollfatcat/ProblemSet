// 運用動態規劃建立帕斯卡三角形
#include<bits/stdc++.h>
using namespace std;

const int MAXN=21;
int DP[MAXN][MAXN]={};
int main(){
  // 預跑：Ｃ(n,m)的動態規劃作法
  for(int i=0;i<MAXN;i++)
    DP[i][0]=DP[0][i]=1;
  for(int i=1;i<MAXN;i++)
    for(int j=1;j+i<MAXN;j++)
      DP[i][j]=DP[i-1][j]+DP[i][j-1];
  //
  int caseT, n, k;
  scanf("%d",&caseT);
  while(caseT--)
    scanf("%d %d",&n,&k),
    printf("%d\n",DP[n-k][k]);
}