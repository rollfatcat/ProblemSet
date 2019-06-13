// Minimum Spanning Tree(Kruskal)
/* 兩個優化
 */
#include <bits/stdc++.h>
using namespace std;
#define INF 0x7f7f7f7f

int N, M;
int p[10000], h[10000];
struct ee{
  int a,b,v;
  bool operator<(const ee other)const{ return v<other.v; }
}now;
vector<ee> edge;
int find(int x){ // find_parent時順便扁平化
  if(p[x]!=x) p[x]=find(p[x]);
  return p[x];
}
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  while(scanInt(N) and scanInt(M)){
    edge.clear();
    for(int i=0;i<M;i++){ // 假設兩城市間不會有兩條路以上
      scanInt(now.a), scanInt(now.b), scanInt(now.v);
      if(now.a>now.b) now.a^=now.b^=now.a^=now.b;
      edge.push_back(now);
    }
    sort(edge.begin(),edge.end());
    for(int i=0;i<N;i++)
      p[i]=i, h[i]=1;
    int cost=0;
    for(int i=0, eNum=1;eNum<N;i++){ //eNum 選滿 N-1條時就結束(已經是聯通狀態)，假設一定可以選滿
      int pa=find(edge[i].a), pb=find(edge[i].b);
      if(pa==pb)  continue; // a和b在同一個set裡面時不選取這條邊
      eNum++, cost+=edge[i].v;
      // Union時選擇把高度低的併到高度低的底下(找parent時降低平均耗時)
      if(h[pa]>h[pb]) p[pb]=pa;
      else if(h[pa]<h[pb]) p[pa]=pb;
      else p[pb]=pa, h[pa]++;
    }
    printf("%d\n",cost);
  }
}