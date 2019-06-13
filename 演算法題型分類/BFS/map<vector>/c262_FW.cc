// 0.3s/1.3MB(最後兩筆測資的邊會包含整數最大值，且負重也可能是整數最大值的情況)
#include<bits/stdc++.h>
using namespace std;

const int INF=0x7fffffff; // 這題沒說權重最大值，所以直接設定成整數最大值
inline bool scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); return c!=EOF; }
int main(){

  int V, E, Q;
  while(scanInt(V) and scanInt(E) and scanInt(Q) and V){
    int load[V+1][V+1];
    for(int i=1;i<=V;i++)
      for(int j=1;j<=V;j++)
        load[i][j]=INF;
    int a, b, v;
    for(int i=0;i<E;i++)
      scanInt(a),
      scanInt(b),
      scanInt(v),
      load[a][b]=load[b][a]=v;
    load[1][1]=0;
    for(int k=1;k<=V;k++)
      for(int i=1;i<=V;i++)
        for(int j=1;j<=V;j++)
          load[i][j]=min(load[i][j],max(load[i][k],load[k][j]));
    puts((load[1][V]<=Q)?"Save":"GG");
  }
}