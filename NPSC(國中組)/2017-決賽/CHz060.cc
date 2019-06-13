#include<iostream>
using namespace std;

int main(){
  int N, K, ans;
  cin>>N>>K;
  ans=N-(K<<1);
  if(ans<0) ans=-ans;
  cout<<ans<<endl;
}