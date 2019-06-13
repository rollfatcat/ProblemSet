// 題目保證給的數字都是相異且1 ≤Ａi≤ 1e9

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001

struct DATA{
  int o,v;
  bool operator<(const DATA &rhs)const{ return v<rhs.v; }
}org[MAXN];
struct NODE{
  int L,R,P,n;
  NODE(int a=0,int b=0,int c=0,int d=0):L(a),R(b),P(c),n(d){}
}node[MAXN];
bool IsIn[MAXN];
int N, maxL;

int Find(int x){ return (node[x].P==x)? x: node[x].P=Find(node[x].P); }
void Union(int now){
  IsIn[now]=1;
  int head=now;
  int FL=Find(node[now].L);
  int FR=Find(node[now].R);
  if( node[FL].n ) head=FL;

  node[head].n=node[FL].n+1+node[FR].n;
  if(IsIn[node[FL].L]==0 and IsIn[node[FR].R]==0)
    maxL=max(maxL,node[head].n);
  node[now].P=head;
  if(node[FR].n)
    node[FR].P=head,
    node[head].R=node[FR].R;
  else
    node[head].R=node[now].R;
}

int main(){
  while(scanf("%d",&N)!=EOF){
    for(int i=0;i<N;i++)
      IsIn[i]=0,
      node[i]=NODE(i-1,i+1,i);
    node[0].L=0,
    node[N-1].R=N-1;

    for(int i=0;i<N;i++)
      scanf("%d",&org[i].v),
      org[i].o=i;
    sort(org,org+N);
    maxL=0;
    for(int i=N-1;i>=0;i--)
      Union(org[i].o);
    printf("%d\n",maxL+2);
  }
}
/*
 1 9 8 2 6 => 1 5 4 2 3
10 9 8 2 1 => 5 4 3 2 1
 3 9 8 2 1 => 3 5 4 2 1
1 6 7 2 5 4 3
*/