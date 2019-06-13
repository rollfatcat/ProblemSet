// 字串練習，string.substr＋getline(cin,ss)的用法
#include<bits/stdc++.h>
using namespace std;

int main(){
  string cut, input;
  getline(cin,cut),
  getline(cin,input);
  int now=0;
  for(int i=0;i+cut.length()<input.length(); ){
    string subss=input.substr(i,cut.length());
    if(subss==cut)
      cout<<input.substr(now,i-now)<<'\n',
      i=now=i+cut.length();
    else
      i++;
  }
  if(now!=input.length()) // 如果切點處剛好等於輸入字串結尾表示沒有東西存在buff
    cout<<input.substr(now)<<'\n';

}
/*
and
appleandbanana

 ,
baluteshih ,leo , alan
*/