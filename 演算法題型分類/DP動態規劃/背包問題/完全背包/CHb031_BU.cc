// 無限背包問題, 窮舉的單一維度是每個重量

#include<iostream>
#include<string.h>
using namespace std;
#define MaxNum 100
#define MAX(a,b) ((a>b)?a:b)

int N, M;
int v[MaxNum], w[MaxNum];

int main(void){
  while(cin>>N>>M){
    for(int i=0;i<N;i++)
      cin>>w[i]>>v[i];
    int map[M+1];
    memset(map, 0, sizeof(map));
    for(int i=0;i<N;i++)    // 窮舉每種物品
      for(int j=w[i];j<=M;j++) // 窮舉每種重量
        map[j]=MAX( map[j], map[j-w[i]]+v[i]);
    cout<<map[M]<<endl;
  }
}