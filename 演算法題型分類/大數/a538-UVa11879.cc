// 大數對單位數的除法(根本不用管題目敘述的作法= =)
#include<iostream>
using namespace std;

int main(){
  string ss;
  while(cin>>ss and ss!="0"){
    int num=ss[0]-'0';
    for(int i=1;i<ss.length();i++)
      num=(10*num+ss[i]-'0')%17;
    cout<<(num%17==0)<<endl;
  }
}