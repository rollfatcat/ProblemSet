// 方格取數(移動方式只能往右/往下)
#include<iostream>
using namespace std;
#define MaxN 100

int main(){
  int len, io[MaxN][MaxN];
  int map[MaxN][MaxN];
  while(cin>>len){
    for(int i=0;i<len;i++)
      for(int j=0;j<len;j++)
        cin>>io[i][j];
    //邊界預處理
    map[0][0]=io[0][0];
    for(int i=1;i<len;i++)
      map[i][0]=map[i-1][0]+io[i][0],
      map[0][i]=map[0][i-1]+io[0][i];
    // Bottom-Up
    for(int i=1;i<len;i++)
      for(int j=1;j<len;j++)
        map[i][j]=max(map[i-1][j],map[i][j-1])+io[i][j];
    cout<<map[len-1][len-1]<<endl;
  }
}