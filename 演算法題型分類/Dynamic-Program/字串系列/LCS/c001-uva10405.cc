// LCS 模板題，題目要求輸出最長子字串
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
#define MaxN 1001

int map[MaxN][MaxN];
int main(){
  string ss[2];
  while(cin>>ss[0]>>ss[1]){
    memset(map,0,sizeof(map));
    for(int i=0;i<ss[0].length();i++)
      for(int j=0;j<ss[1].length();j++)
        map[i+1][j+1]=(ss[0][i]==ss[1][j])?(map[i][j]+1):(max(map[i+1][j],map[i][j+1]));
    cout<<map[ss[0].length()][ss[1].length()]<<endl;
  }
}