// 圖論：DFS走地圖 => 模板題
// 練習利用 getchar()優化輸入, puts()/putchar()優化輸出 8ms=>0ms
#include <bits/stdc++.h>
#include<vector>
#include<cstring>
using namespace std;
#define MaxN 10001

vector<int> e[MaxN];
bool vis[MaxN]={};
inline bool ReadInt(int &x) {
  static char c, neg;
  while((c=getchar())<'-')    {if(c == EOF) return 0;}
  neg=(c=='-')?-1:1;
  x=(neg==1)?(c-'0'):0;
  while((c=getchar())>='0')
    x=(x<<3)+(x<<1)+c-'0';
  x*=neg;
  return 1;
}
void DFS(int now){
  if(vis[now])  return;
  vis[now]=true;
  for(int i=0;i<e[now].size();i++)
    DFS(e[now][i]);
}
int main(){

  int N,M,L,Q;
  ReadInt(&N), ReadInt(&M), ReadInt(&L), ReadInt(&Q);

  for(int i=0,a,b; i<M; i++)
    ReadInt(&a), ReadInt(&b), e[a].push_back(b);
  for(int i=0,a;i<L;i++)
    ReadInt(&a), DFS(a);
  for(int i=0,a;i<Q;i++)
    ReadInt(&a), puts((!vis[a])?"YA~~":"TUIHUOOOOOO");
}