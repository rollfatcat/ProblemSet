// 數字倒轉輸出, 注意0開頭和負數
#include<iostream>
using namespace std;

int main(){
  int a, b, base, sign;
  while(cin>>a){
    if(a==0){  cout<<0<<endl;  continue; }
    while(a%10==0)  a/=10;
    sign=(a<0)?-1:1;
    for(b=0, a*=sign;a>0;a/=10)
      b=10*b+(a%10);
    cout<<sign*b<<endl;
  }
}