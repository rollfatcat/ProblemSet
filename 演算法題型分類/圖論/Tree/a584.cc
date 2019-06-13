#include<bits/stdc++.h>
using namespace std;

const int INF=0x7fffffff;
struct NODE{ vector<int>link; }one;
vector<NODE> node;
unordered_map<string,int> table;

inline int getID(string name){
  if(table.count(name)==0)
    table[name]=node.size(),
    node.push_back(one);
  return table[name];
}
int main(){
  for(int N,st,ed;cin>>N>>ws;){
    node.clear();
    table.clear();
    string line, name;
    for(int a,b,i=0;i<N;i++){
      getline(cin,line);
      stringstream ss(line);
      ss>>name;
      a=getID(name);
      while(ss>>name){
        b=getID(name);
        node[a].link.push_back(b),
        node[b].link.push_back(a);
      }
    }
    cin>>name, st=getID(name);
    cin>>name, ed=getID(name);
    // 利用 BFS 找親屬關係的親等(最短路徑)
    vector<int> dis(table.size(),INF);
    queue<int> Q;
    dis[st]=0;
    for(int i=0;i<node[st].link.size();i++)
      Q.push(node[st].link[i]),
      dis[node[st].link[i]]=1;
    while(Q.empty()==0 and dis[ed]==INF){
      int now=Q.front();  Q.pop();
      for(int i=0;i<node[now].link.size();i++)
        if(dis[ node[now].link[i] ]>dis[now]+1)
          Q.push(node[now].link[i]),
          dis[node[now].link[i]]=dis[now]+1;
    }
    cout<<dis[ed]<<endl;
  }
}