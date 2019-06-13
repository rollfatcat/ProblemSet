// 簡單模擬題
#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int a, b, CheatNum;
  bool isSafe;
  while(cin>>a>>b){
    a=max(a,b);
    CheatNum=3, isSafe=false;
    for(int i=30;i>0;i--){
      cin>>b;
      if(b){
        if(b==a and CheatNum>0)
          isSafe=true;
        if(b!=a)
          CheatNum--;
      }
    }
    if(isSafe)
      cout<<"Y"<<endl;
    else
      cout<<"N"<<endl;
  }
}