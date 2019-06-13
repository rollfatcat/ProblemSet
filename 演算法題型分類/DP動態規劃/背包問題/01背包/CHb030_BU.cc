// 01背包問題, 窮舉的兩個維度分別是物品的編號和每個重量
// 換成 DFS 暴力窮舉+brach , 即便已經做 Qsort 還是會TLE(前三個AC)

#include<iostream>
#include <string.h>
using namespace std;
#define MaxNum 100
#define MAX(a,b) ((a>b)?a:b)

int N, M;
int v[MaxNum], w[MaxNum];

int main(void){
  while(cin>>N>>M){
    for(int i=0;i<N;i++)
      cin>>w[i]>>v[i];
    int map[N+1][M+1];
    memset(map, 0, sizeof(map));
    for(int i=0;i<N;i++)    // 窮舉每種物品
      for(int j=0;j<=M;j++) // 窮舉每種重量
        if( j<w[i] )  // 耐重能力不足，故只能不放。
          map[i+1][j]=map[i][j];
        else          // 耐重能力足夠，可以放或不放。
          map[i+1][j]=MAX( map[i][j], map[i][j-w[i]]+v[i] );
    cout<<map[N][M]<<endl;
  }
}