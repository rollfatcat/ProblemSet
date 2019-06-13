// MST(Kruskal)
#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
struct ee{
  int a,b,v;
  bool operator<(const ee &other)const{ return v<other.v; }
}now;
int find_parent(int x){
  if(parent[x]!=x)
    parent[x]=find_parent(parent[x]);
  return parent[x];
}
int main(){
  for(int N;scanInt(N);){
    vector<ee> edge;
    for(int cnt=N*(N-1)/2; cnt--;)
      scanInt(now.a),
      scanInt(now.b),
      scanInt(now.v),
      edge.push_back(now);
    sort(edge.begin(),edge.end());
    parent.resize(N+1);
    for(int i=1;i<=N;i++)
      parent[i]=i;
    int sum=0;
    for(int i=0,cnt=1; cnt<N;i++){
      int pa=find_parent(edge[i].a);
      int pb=find_parent(edge[i].b);
      if(pa!=pb)
        cnt++,
        sum+=edge[i].v,
        parent[pb]=pa;
    }
    printf("%d\n",sum);
  }
}