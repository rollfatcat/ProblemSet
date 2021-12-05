// 偵測有向環( 點的狀態分為3種：0(沒走過)/1(正在走)/2(已經走過) )
// 有向環的定義：由起點展開的過程中存在一個遇到的點狀態也是1(正在走)
// 剪枝：若這個點的狀態是2(已經走過)就不再展開
#include<bits/stdc++.h>
using namespace std;

const int MAXV=1001;
int V, E;
bool NoCycle;
vector<int> Link[MAXV];
vector<int> vis(MAXV,0);

bool DFS(int now){
  vis[now]=1;
  for(int i=0;i<Link[now].size();i++)
    if(vis[ Link[now][i] ]==1 or vis[ Link[now][i] ]==0 and DFS(Link[now][i])==0)
      return false;
  vis[now]=2;
  return true;
}
int main(){
  int caseT;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d %d",&V,&E);
    for(int i=1;i<=V;i++)
      Link[i].clear(),
      vis[i]=0;
    for(int u,v;E--;)
      scanf("%d %d",&u,&v),
      Link[u].push_back(v);
    NoCycle=true;
    for(int i=1;i<=V and NoCycle;i++)
      if(vis[i]==0)
        NoCycle=DFS(i);
    puts((NoCycle)?"W+W":"O______O");
  }
}
