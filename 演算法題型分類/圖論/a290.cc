// 圖論：找任意兩點是否有狀態連通(有向邊)
// 輸入時兩點間可能有多條邊, 建圖時結合二維陣列避免重複紀錄已經存在的邊
// 地圖的點很多, 剪枝=>找到點之後就return,  不繼續展開, 88ms
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int ed;
vector<int> e[801];
bool vis[801], to[801][801];
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  for(int N,M,st; cin>>N>>M; ){
    memset(to,0,sizeof(to));
    for(int i=1;i<=N;i++)
      e[i].clear();
    for(int a,b; M--; ){
      cin>>a>>b;
      if(!to[a][b]) //兩點之間可能有多條邊
        to[a][b]=true, e[a].push_back(b);
    }
    memset(vis,0,sizeof(vis));
    cin>>st>>ed;
    if(DFS(st))  cout<<"Yes!!!"<<endl;
    else  cout<<"No!!!"<<endl;
  }
}