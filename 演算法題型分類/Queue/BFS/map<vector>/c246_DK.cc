#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define MaxN 101

struct Node{ int n, t;} now, nxt;
struct compare{ bool operator()(Node &a, Node &b){ return a.t>b.t; }  };
int main(){
  int T, N, E, t, M;
  int a, b, c;
  int cost[MaxN][MaxN];

  cin>>T;
  while(T--){
    cin>>N>>E>>t>>M;
    vector<int> map[N+1];
    while(M--)
      cin>>a>>b>>c,
      map[b].push_back(a), cost[b][a]=c;

    bool vis[N+1];
    memset(vis,0,sizeof(vis));
    priority_queue<Node,vector<Node>,compare> PQ;
    PQ.push({E,0});
    int safe=0;
    while(!PQ.empty()){
      now=PQ.top(); PQ.pop();
      if(now.t>t) break;
      if(vis[now.n])  continue;
      vis[now.n]=1; safe++;
      for(int i=0;i<map[now.n].size();i++)
        if(!vis[ map[now.n][i] ])
          PQ.push({map[now.n][i],now.t+cost[ now.n ][ map[now.n][i] ]});
    }
    cout<<safe<<endl;
    if(T) cout<<endl;
  }
}