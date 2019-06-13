// FloydWall or Dijkstra
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define MaxN 200

int n, p[MaxN], h[MaxN];
struct Node{ int x, y, d; } node[MaxN];
vector<Node> edge;
int Power2(int a, int b){ return a*a+b*b; }
bool compare(Node a, Node b){ return a.d<b.d;}
int find(int now){ return (now==p[now])?now:find(p[now]);}

int main(){

  for(int caseNum=1;cin>>n and n;caseNum++){
    if(caseNum>1) printf("\n");
    edge.clear();
    for(int i=0;i<n;i++){
      cin>>node[i].x>>node[i].y;
      for(int j=0;j<i;j++){
        int tmp_d=Power2(node[i].x-node[j].x,node[i].y-node[j].y);
        edge.push_back({j,i,tmp_d});
      }
    }
    sort(edge.begin(),edge.end(),compare);
    for(int i=0;i<n;i++)  p[i]=i, h[i]=1;
    int dis=0x7fffffff;
    for(int i=0;i<edge.size();i++){
      int px=find(edge[i].x);
      int py=find(edge[i].y);
      if(px==py)  continue;
      if(h[px]>h[py]) p[py]=px;
      else if(h[px]<h[py]) p[px]=py;
      else p[py]=px, h[px]++;
      if(find(1)==find(0)){ dis=edge[i].d; break; }
    }
    printf("Scenario #%d\nFrog Distance = %.3lf\n",caseNum,sqrt(dis));
  }
}