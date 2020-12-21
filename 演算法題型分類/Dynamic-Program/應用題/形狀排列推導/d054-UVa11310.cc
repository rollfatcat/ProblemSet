// 重點是找DP規則和初始化的方法數
// 題目保證e18以下, 意思是long long int 可解決

#include<iostream>
using namespace std;

int main(){
  long long int DP[41];
  DP[1]=1, DP[2]=5, DP[3]=11;
  for(int i=4;i<=40;i++)
    DP[i]=DP[i-1]+4*DP[i-2]+2*DP[i-3];

  int t, n;
  cin>>t;
  while(t--){
    cin>>n;
    cout<<DP[n]<<endl;
  }
}