// 01背包
#include<iostream>
#include<cstring>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(int n,total_w; cin>>n>>total_w;){
    int DP[total_w+1];
    memset(DP,0,sizeof(DP));
    for(int v,w,j;n--;)
      for(cin>>v>>w, j=total_w; j>=w; j--)
        DP[j]=max(DP[j],DP[j-w]+v);
    cout<<DP[total_w]<<endl;
  }
}