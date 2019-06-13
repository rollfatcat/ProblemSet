// 01背包問題
#include<iostream>
#include<cstring>
using namespace std;

int main(){
  int T, M;
  cin>>T>>M;
  int DP[T+1];
  memset(DP,0,sizeof(DP));
  for(int i=0,w,v;i<M;i++){
    cin>>w>>v;
    for(int j=T;j>=w;j--)
      DP[j]=max(DP[j],DP[j-w]+v);
  }
  cout<<DP[T]<<endl;
}