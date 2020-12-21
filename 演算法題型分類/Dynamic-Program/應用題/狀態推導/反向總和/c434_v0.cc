// DP解(反向計算) 題目要求算連續3個以上的數字 =>  連續2個以下的數字組合
// 對每個數字有選和不選兩種狀態，避免連續選擇3次以上的方法數
// N個數字全部的選擇是2^N 扣除DP[N]後取模即可
#include<iostream>
using namespace std;
#define mod 1000000007

int DP[1000002][3]={}, power2[1000001]={};
int main(){
  // 線性累加 => 加速方式:矩陣做快速冪次
  DP[1][0]=DP[1][1]=1, power2[1]=2;
  for(int i=2;i<=1000000;i++)
    DP[i][0]=((DP[i-1][0]+DP[i-1][1])%mod+DP[i-1][2])%mod,
    DP[i][1]=DP[i-1][0],
    DP[i][2]=DP[i-1][1],
    power2[i]=(power2[i-1]<<1)%mod;
  DP[1000001][0]=((DP[1000000][0]+DP[1000000][1])%mod+DP[1000000][2])%mod;

  ios::sync_with_stdio(0), cin.tie(0);
  int T, N;
  for(cin>>T;T--;){
    cin>>N;
    int ans=power2[N]-DP[N+1][0];
    printf("%d\n",(ans<0)?(ans+mod):ans);
  }
}
