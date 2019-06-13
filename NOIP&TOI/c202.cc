#include<iostream>
using namespace std;

long GCD(long a, long b){ return(a%b)?GCD(b,a%b):b; }
int main(){
  int n;
  long a, b, x;

  for(cin>>n>>a;--n;)
    cin>>x, a=(a>x)?GCD(a,x):GCD(x,a);
  cout<<a<<endl;
}