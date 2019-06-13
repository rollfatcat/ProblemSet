// 建單向邊的樹, 問A能不能到B => 經典DFS走地圖
// 測資有點大, 優化輸入讀取, 24ms=>8ms
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int ed;
vector<int> e[101];
bool vis[101];
bool DFS(int now){
  vis[now]=true;
  if(now==ed) return true;
  for(int i=0; i<e[now].size(); i++)
    if( !vis[e[now][i]] ){
      bool status=DFS(e[now][i]);
      if(status)
        return true;
    }
  return false;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for(int k; cin>>ed>>k; ){
    for(int i=0;i<=100;i++)
      e[i].clear();
    for(int a,b; k--; )
      cin>>a>>b,
      e[a].push_back(b);
    memset(vis,0,sizeof(vis));
    if(DFS(0))
      cout<<"Ok!"<<endl;
    else
      cout<<"Impossib1e!"<<endl;
  }
}