// for迴圈+if的練習
#include<iostream>
using namespace std;

int main(){
  int cnt=0, h[10], H;
  for(int i=0; i<10; i++)
    cin>>h[i];
  cin>>H, H+=30;
  for(int i=0;i<10;i++)
    if(h[i]<=H)
      cnt++;
  cout<<cnt<<endl;
}