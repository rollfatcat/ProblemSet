// 二進位的小數版本，保證不出現無窮的情況
#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(double num; cin>>num; ){
    int INT=num; num-=INT;
    string ss;
    while(INT)
      ss=(char)((INT%2)+'0')+ss, INT>>=1;
    ss+='.';
    for(double base=0.5; num>0.0; base/=2)
      if(num>=base)  ss+='1', num-=base;
      else ss+='0';
    cout<<ss<<endl;
  }
}