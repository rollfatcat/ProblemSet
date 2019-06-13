#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for(int B, P, M; cin>>B>>P>>M; ){
    int ans=1;
    for(B=B%M; P>0; P>>=1,B=(B*B)%M)
      if(P&1)
        ans=(ans*B)%M;
    cout<<ans<<'\n';
  }
}