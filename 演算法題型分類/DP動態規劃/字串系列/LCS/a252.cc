// 最長共同字串(3維版本) => 完成後請挑戰 ZJ-b953 並比較 ZJ-b954
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
  string ss[3];
  cin>>ss[0]>>ss[1]>>ss[2];
  int map[ss[0].length()+1][ss[1].length()+1][ss[2].length()+1];
  memset(map,0,sizeof(map));

  for(int i=0;i<ss[0].length();i++)
    for(int j=0;j<ss[1].length();j++)
      for(int k=0;k<ss[2].length();k++)
        if(ss[0][i]==ss[1][j] and ss[1][j]==ss[2][k])
          map[i+1][j+1][k+1]=map[i][j][k]+1;
        else
          map[i+1][j+1][k+1]=max(max(map[i][j+1][k+1],map[i+1][j][k+1]),map[i+1][j+1][k]);
  cout<<map[ss[0].length()][ss[1].length()][ss[2].length()]<<endl;
}