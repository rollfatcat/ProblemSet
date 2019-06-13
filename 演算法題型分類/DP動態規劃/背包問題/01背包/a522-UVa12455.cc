// 標準01背包問題
#include<iostream>
#include<cstring>
using namespace std;

int main(){
  int T, p, n;
  for(cin>>T; T--;){
    cin>>p>>n;
    int DP[p+1];
    memset(DP,0,sizeof(DP));
    for(int w; n--; ){
      cin>>w;
      for(int i=p;i>=w;i--)
        DP[i]=max(DP[i],DP[i-w]+w);
    }
    if(DP[p]==p)  cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}