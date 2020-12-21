// 01背包問題的變形, 但只能用一維陣列解所以注意更新方向!!
// 定義最大值的方式不同
#include<iostream>
#include<cstring>
using namespace std;
#define MAX(a,b)((a>b)?a:b)
#define MaxW 30000
#define MaxN 25


int main(){
  int W,N;
  int w[MaxN], v[MaxN];
  int map[MaxW];

  cin>>W>>N;
  for(int i=0; i<N; i++)
    cin>>w[i]>>v[i];
  memset(map,0,sizeof(map));
  for(int i=0;i<N;i++)
    for(int j=W;j>=w[i];j--)
      map[j]=MAX( map[j], map[j-w[i]]+v[i]*w[i] );
  cout<< map[W] <<endl;
}