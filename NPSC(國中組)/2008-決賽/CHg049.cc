// 題目說鋪的地磚不能轉90度接起來, 但不包含當只有一塊地磚時可以旋轉接合
#include<iostream>
using namespace std;

int main(){
  int w, h, x, y;

  while(cin>>w>>h>>x>>y and x)
    if(w*h==x*y) cout<<1<<endl;
    else if(w%x or h%y)  cout<<-1<<endl;
    else cout<<(w/x*(h/y))<<endl;
}