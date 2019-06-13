// 想法：將 1 ~ n個數字選m個做相乗的總和問題轉化成多項式與係數的關係(x+1)(x+2)(x+3)...
// 題解：https://home.gamer.com.tw/creationDetail.php?sn=4102130
#include<iostream>
#include<vector>
using namespace std;
#define mod 1572869

int main(){
  vector<unsigned int> DP[1001];
  DP[1].push_back(1),DP[1].push_back(1);
  for(int idx=2;idx<=1000;idx++){
    DP[idx]=DP[idx-1],  DP[idx].push_back(0);
    for(int j=1;j<=DP[idx-1].size();j++)
      DP[idx][j]=(DP[idx][j]+DP[idx-1][j-1]*idx)%mod;
  }
  ios::sync_with_stdio(0),
  cin.tie(0);

  for(int n,m; cin>>n>>m;)
    printf("%u\n",DP[n][m]);
}