// Minimal Spanning Tree
// 最小權重請用long long int 紀錄
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int p[100000], h[100000];
struct Edge{ int a, b, w; }e[200000];
bool cmp(Edge a, Edge b){ return a.w<b.w; };
int find(int now){  return (now==p[now])?now:find(p[now]);  }
bool UNION(int a,int b){
  int pa=find(a);
  int pb=find(b);
  // 這條edge加入會導致Circle
  if(pa==pb)  return false;
  // 把兩個subgroup合併在一起
  // 將頂點指向另一個頂點, 高度低指向高度高的
  if(h[pa]>h[pb]) p[pb]=pa;
  else if(h[pa]<h[pb]) p[pa]=pb;
  else p[pa]=pb, h[pb]++;
  return true;
}
int main(){
  int n, m;

  while(scanf("%d%d",&n,&m)==2){
    for(int i=0;i<m;i++)
      scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].w);
    //形成Tree至少要n-1個edge
    if(m<n-1){ printf("-1\n"); continue; }
    sort(e,e+m,cmp);

    for(int i=0;i<n;i++)
      p[i]=i, h[i]=1;
    long long int cost=0;
    int pick=0;
    for(int i=0;i<m;i++)
      if(UNION(e[i].a,e[i].b))
        cost+=e[i].w, pick++;
    if(pick==n-1)  printf("%lld\n",cost);
    else printf("-1\n");
  }
}