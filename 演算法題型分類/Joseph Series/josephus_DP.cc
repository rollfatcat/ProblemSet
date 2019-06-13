#include<iostream>
using namespace std;

//  號碼從0開始算
int main(){
  int n, m, f=0;
  cin>>n>>m;
  for(int i=1; i<=n; i++)
    f=(f+m)%i;
  cout<<f+1<<endl;
}