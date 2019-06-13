#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int M, a, b, c;

  cin>>M;
  while(M--){
    cin>>a>>b>>c;
    int judge=b*b-4*a*c;
    if(judge<0){  cout<<"No\n"; continue; }
    int x=sqrt(judge);
    if(x*x==judge)  cout<<"Yes\n";
    else cout<<"No\n";
  }
}