#include<iostream>
using namespace std;

int main(){
  int x1,x2,y1,y2;
  while(cin>>x1>>y1>>x2>>y2 and x1){
    if(x1==x2 and y1==y2)
      cout<<0<<endl;
    else if(x1==x2 or y1==y2 or x1+y1==x2+y2 or x1-y1==x2-y2)
      cout<<1<<endl;
    else
      cout<<2<<endl;
  }
}