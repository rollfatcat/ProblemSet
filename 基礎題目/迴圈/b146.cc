// for迴圈+if的練習
#include<iostream>
using namespace std;

int main(){
  int a,b,ex=0;
  for(int i=0;i<7;i++){
    cin>>a>>b;
    if(a+b>8 and ex==0)
      ex=i;
  }
  cout<<ex<<endl;
}