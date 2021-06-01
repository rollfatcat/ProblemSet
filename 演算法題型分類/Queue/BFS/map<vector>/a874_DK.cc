// 用這題來講解Dijkstra版本
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

struct Edge{
  int n, v;
  bool operator<(const Edge &other)const{ return v>other.v; }
};
int main(){
  for(int N; cin>>N; ){
    vector<Edge>map[26];
    char a, b;
    for(int v;N--;)
      cin>>a>>b>>v,  map[a-'A'].push_back({b-'A',v}),  map[b-'A'].push_back({a-'A',v});

    int dis[26], st, ed;
    memset(dis,0xff,sizeof(dis));
    cin>>a>>b,  st=a-'A', ed=b-'A';
    priority_queue<Edge,vector<Edge> > PQ;
    PQ.push({st,0});
    while(!PQ.empty()){
      Edge now=PQ.top();  PQ.pop();
      if(dis[now.n]>-1) continue;
      dis[now.n]=now.v;
      if(now.n==ed) break;
      for(int i=0;i<map[now.n].size();i++)
        if(dis[ map[now.n][i].n ]==-1)
          PQ.push({map[now.n][i].n,now.v+map[now.n][i].v});
    }
    if(dis[ed]==-1) cout<<"NoRoute"<<endl;
    else cout<<dis[ed]<<endl;
  }
}