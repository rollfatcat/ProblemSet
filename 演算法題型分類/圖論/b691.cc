// MST變形：目的是加總越小越好，所以有負價值的邊一定要選取(不管會不會造成環)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MaxN 3000000

struct nn{ int a,b,v; }e[MaxN];
int P[1000001], h[1000001];
bool compare(nn x,nn y){ return x.v<y.v; }
int find(int x){
  if(P[x]!=x)
    P[x]=find(P[x]);
  return P[x];
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int N, M, v1, v2;
  cin>>N>>M;
  for(int i=1;i<=N;i++)
    P[i]=i, h[i]=0;
  for(int i=0;i<M;i++)
    cin>>e[i].a>>e[i].b>>v1>>v2, e[i].v=v1-v2;
  sort(e,e+M,compare);
  long cost=0;
  for(int i=0; i<M; i++){
    int Pa=find(e[i].a), Pb=find(e[i].b);
    if(Pa!=Pb){
      if(h[Pa]<h[Pb]) P[Pa]=Pb;
      else if(h[Pa]>h[Pb]) P[Pb]=Pa;
      else P[Pb]=Pa, h[Pa]++;
      cost+=e[i].v;
    } else if(e[i].v<0) // 負價值的邊一定要加入，這樣加總的值會更小
      cost+=e[i].v;
  }
  cout<<cost<<endl;
}
/*
4 4
2 4 1 0
1 2 8 0
1 3 7 0
1 4 3 0
3 4
1 3 20 3
1 3 200 500
3 2 10 1
2 3 100 1000
*/