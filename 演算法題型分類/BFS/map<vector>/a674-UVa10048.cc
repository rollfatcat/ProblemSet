// 題目會多次查詢同張地圖 => Floyed-Warshall
#include<bits/stdc++.h>
using namespace std;

inline bool scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); return c!=EOF; }
int main(){
  int C, S, Q;
  for(int caseN=0;scanInt(C) and scanInt(S) and scanInt(Q) and C;){
    int load[C+1][C+1];
    memset(load,0x7f,sizeof(load));
    for(int a,b,v;S--;){
      scanInt(a),
      scanInt(b),
      scanInt(v);
      if(load[a][b]>v)
        load[a][b]=load[b][a]=v;
    }
    for(int k=1;k<=C;k++)
      for(int i=1;i<=C;i++)
        for(int j=1;j<=C;j++)
          load[i][j]=min(load[i][j],max(load[i][k],load[k][j]));
    if(caseN++) puts("");
    printf("Case #%d\n",caseN);
    for(int a,b;Q--;){
      scanInt(a),
      scanInt(b);
      if(load[a][b]==0x7f7f7f7f)
        puts("no path");
      else
        printf("%d\n",load[a][b]);
    }
  }
}