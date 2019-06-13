// (偽)大數Mod(?)
#include<iostream>
using namespace std;

int main(){
  cin.sync_with_stdio(false), cin.tie(0), cout.tie(0);
  for(string ss; cin>>ss; ){
    int num=0;
    for(int i=0;i<ss.length();i++)
      num=(10*num+ss[i]-'0')%91;
    cout<<num<<endl;
  }
}