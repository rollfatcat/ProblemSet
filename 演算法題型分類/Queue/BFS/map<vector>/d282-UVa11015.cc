// 題目要輸出 到達其他點的加總距離『最小』的起點
// 雖然沒說但是需要求出所有點對的距離 => Floyed-Warshall
#include<bits/stdc++.h>
using namespace std;

inline bool scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); return c!=EOF; }
int main(){
  char name[23][12];
  int V, E;
  for(int caseN=0;scanInt(V) and scanInt(E) and V;){
    for(int i=1;i<=V;i++)
      scanf("%s",name[i]);
    getchar();
    int load[V+1][V+1];
    memset(load,0x3f,sizeof(load));
    for(int a,b,v;E--;){
      scanInt(a),
      scanInt(b),
      scanInt(v);
      if(load[a][b]>v)
        load[a][b]=load[b][a]=v;
    }
    for(int k=1;k<=V;k++)
      for(int i=1;i<=V;i++)
        for(int j=1;j<=V;j++)
          load[i][j]=min(load[i][j],load[i][k]+load[k][j]);
    int idx=0, maxS=0x7fffffff;
    for(int i=1;i<=V;i++){
      int sum=0;
      for(int j=1;j<=V;j++)
        if(i!=j)
          sum+=load[i][j];
      if(sum<maxS)
        maxS=sum, idx=i;
    }
    printf("Case #%d : %s\n",++caseN,name[idx]);
  }
}