#include<iostream>
using namespace std;


int main(){
  int caseNum, x, y;
  int map[14][14];
  for(int i=1;i<=13;i++)
    map[i][1]=map[i][i]=1;
  for(int i=3;i<=13;i++)
    for(int j=2;j<i;j++)
      map[i][j]=map[i-1][j-1]+map[i-1][j];

  cin>>caseNum;
  while(caseNum--)
    cin>>x>>y, cout<<map[x][y]<<endl;
}