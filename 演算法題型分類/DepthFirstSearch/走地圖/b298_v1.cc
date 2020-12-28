// Stack只能降低記憶體使用，速度沒有改善
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int N, M, L, Q;
  vector<int> e[10001];
  bool vis[10001]={};

  cin>>N>>M>>L>>Q;
  for(int i=0,u,v;i<M;i++)
    cin>>u>>v, e[u].push_back(v);
  stack<int> S;
  for(int i=0,u;i<L;i++)
    cin>>u, S.push(u);
  while(!S.empty()){
    int now=S.top(); S.pop();
    if(vis[now]) continue;
    vis[now]=true;
    for(int i=0;i<e[now].size();i++)
      if(!vis[e[now][i]])
        S.push(e[now][i]);
  }
  for(int i=0,u;i<Q;i++)
    cin>>u, cout<<((!vis[u])?"YA~~":"TUIHUOOOOOO")<<endl;
}