// 最長共同字串
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
  string s1,s2;
  cin>>s1>>s2;
  int map[s1.length()+1][s2.length()+1];
  memset(map,0,sizeof(map));

  for(int i=0;i<s1.length();i++)
    for(int j=0;j<s2.length();j++)
      if(s1[i]==s2[j])
        map[i+1][j+1]=map[i][j]+1;
      else
        map[i+1][j+1]=max(map[i+1][j],map[i][j+1]);
  cout<<map[s1.length()][s2.length()]<<endl;
}