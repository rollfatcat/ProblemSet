// GCD的應用題

#include<iostream>
using namespace std;

int gcd(int a,int b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}
int main(){
  int a,b,c,d;
  while(cin>>a>>b>>c and a and b and c){
    if(b>a){ d=b; b=a; a=d; }
    if(c%gcd(a,b)==0) cout<<"Yes"<<endl;
    else  cout<<"No"<<endl;
  }
}