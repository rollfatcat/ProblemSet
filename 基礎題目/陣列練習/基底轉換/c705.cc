#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  unsigned int x, base=(1<<8)-1, N[4];
  while(cin>>x){
    for(int i=3;i>=0;i--)
      N[i]=x&base, x>>=8;
    cout<<N[0]<<'.'<<N[1]<<'.'<<N[2]<<'.'<<N[3]<<'\n';
  }
}