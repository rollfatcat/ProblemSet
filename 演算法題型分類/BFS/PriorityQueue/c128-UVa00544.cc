// 練習 STL 的 map
// Prioty Queue 從最大的開始更新出去, 起點的load設定成0x7fffffff
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
#define MaxN 201

map<string,int> mapCity;
map<string,int>::iterator iter;
struct Edge{ int n, w; }tmp;
vector<Edge> e[MaxN];
int load[MaxN], n;
bool vis[MaxN];

void init(){
  mapCity.clear();
  for(int i=1;i<=n;i++)
    e[i].clear(), load[i]=vis[i]=0;
}
int findCity(string ss){
  iter=mapCity.find(ss);
  if(iter==mapCity.end()){ // 用iter走遍整個內容
    mapCity[ss]=mapCity.size();
    return mapCity.size();
  }else
    return iter->second;
}
struct compare{
  bool operator()(Edge &a, Edge &b){ return a.w<b.w; }
};
int main(){
  int m, w;
  string cityA, cityB;

  for(int caseNum=1;cin>>n>>m and n;caseNum++){
    init();
    for(int i=0;i<m;i++){
      cin>>cityA>>cityB>>tmp.w;
      int a=findCity(cityA),  b=findCity(cityB);
      tmp.n=b,  e[a].push_back(tmp);
      tmp.n=a,  e[b].push_back(tmp);
    }
    cin>>cityA>>cityB;

    //for(iter=mapCity.begin();iter!=mapCity.end();iter++)
    //  cout<<iter->first<<' '<<iter->second<<endl;

    priority_queue<Edge,vector<Edge>,compare> PQ;
    PQ.push({findCity(cityA),0x7fffffff});
    int ed=findCity(cityB);
    while(!PQ.empty()){
      Edge now=PQ.top();  PQ.pop();
      if(vis[now.n])  continue;
      vis[now.n]=1, load[now.n]=now.w;
      if(now.n==ed) break;
      for(int i=0;i<e[now.n].size();i++)
        if(vis[ e[now.n][i].n ]==0)
          PQ.push( {e[now.n][i].n, min(load[now.n],e[now.n][i].w)} );
    }
    cout<<"Scenario #"<<caseNum<<endl<<load[ed]<<" tons"<<endl<<endl;
  }
}