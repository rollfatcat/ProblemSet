#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  string opt, mapss, inss;
  int N;

  cin>>opt>>mapss>>N>>inss;
  if(opt[0]=='d'){ // 解密:需要把密碼表反轉後再『加密』即可
    string tmpss=mapss;
    for(int i=0;i<26;i++)
      mapss[tmpss[i]-'a']=(char)(i+'a');
  }
  for(int i=0;i<inss.length();i++)
    cout<<( (inss[i]=='_')?'_':mapss[ inss[i]-'a' ] );
  cout<<'\n';
}
// vgxy_xy_r_yofdov_moyyrno
// vgxy_xy_r_yofdov_moyyrno