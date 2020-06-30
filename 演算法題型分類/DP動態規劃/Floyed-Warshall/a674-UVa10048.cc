/* 給定Ｃ個點和Ｓ條無向路徑，查詢Ｑ次
 * 給定的無向路徑(Ｃ1,Ｃ2,d)代表兩點間的噪音分貝，
 * 查詢會給定兩點，輸出最小化路徑上需要忍受最大分貝的負荷程度(可能存在無法抵達時則輸出"no path")。
 * 由於針對單一地圖的查詢的數量過多，可推斷出 Floyed-Warshall
 */
#include<bits/stdc++.h>
using namespace std;

const int INF=1<<30;
const int MaxC=1e2;
const int MaxS=1e3;
const int MaxQ=1e4;

int load[MaxC+1][MaxC+1];
int main(){
  int C, S, Q;
  for(int caseI=1;scanf("%d %d %d\n",&C,&S,&Q) and C; caseI++){
    
    for(int i=0;i<=C;i++)
      for(int j=0;j<=C;j++)
      	load[i][j]=INF;
    for(int a,b,v;S--;)
      scanf("%d %d %d\n",&a,&b,&v),
      load[a][b]=load[b][a]=min(load[a][b],v);
    
    for(int k=1;k<=C;k++)
      for(int i=1;i<=C;i++)
        for(int j=1;j<=C;j++)
          load[i][j]=min(load[i][j],max(load[i][k],load[k][j]));
    if(caseI>1) putchar('\n');
    printf("Case #%d\n",caseI);
    for(int a,b;Q--;)
      scanf("%d %d\n",&a,&b),
      (load[a][b]==INF)?puts("no path"):printf("%d\n",load[a][b]);
  }
}