#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 100
#define MaxM 1000
#define MAX(a,b) ((a>b)?a:b)

int N, M;
int v[MaxN], w[MaxN];
int map[MaxN+1][MaxM+1];

int DP(int item, int weight){
  if(item==-1 or weight==0)
    return 0;
  if(map[item][weight]==-1){
    if(weight>=w[item])
      map[item][weight]=MAX( DP(item-1,weight), DP(item-1,weight-w[item])+v[item] );
    else
      map[item][weight]=DP(item-1,weight);
  }
  return map[item][weight];
}
int main(void){
  memset(map, 0, sizeof(map));
  while(cin>>N>>M){
    for(int i=0;i<N;i++)
      cin>>w[i]>>v[i];
    for(int i=0;i<N;i++)
      for(int j=1;j<=M;j++)
        map[i][j]=-1;
    cout<<DP(N-1,M)<<endl;
  }
}