// 暴力DFS, 找到起點到終點的全部路徑
// 累乘到達終點的機率
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MaxN 20

struct Node{ int n; double p; } T;
vector<Node> e[MaxN];
int N;
bool vis[MaxN];
void DFS(int now, double mulP){
  if(now==T.n){ T.p*=(1-mulP); return; }
  if(vis[now])  return;
  vis[now]=1;
  for(int i=0;i<e[now].size();i++)
    DFS(e[now][i].n,mulP*e[now][i].p);
  vis[now]=0;
}

int main(){
  int S;
  double x;

  while(cin>>N){
    for(int i=0;i<N;i++)
      e[i].clear();
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++){
        cin>>x;
        if(x>0.0 and i!=j)
          e[i].push_back({j,x});
      }
    cin>>S>>T.n;  T.n--;
    T.p=1.0;
    memset(vis,0,sizeof(vis));
    DFS(S-1,1.0);
    printf("%.5lf\n",1.0-T.p);
  }
}