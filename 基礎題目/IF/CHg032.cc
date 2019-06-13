#include<iostream>
#include<cmath>
using namespace std;
int main(){
  double a,b,c;
  while(cin>>a>>b and a and b){
    bool flag=true;
    c=sqrt(a*a+b*b);
    if(c==(int)c)
      cout<<(int)c<<endl;
    else{
      c=sqrt(abs(a*a-b*b));
      if(c==(int)c)
        cout<<(int)c<<endl;
      else
        cout<<"Wrong"<<endl;
    }
  }
}