// 題解：https://psychicalcoder.github.io/2017/07/18/tioj1939/
// DP規則說明請參考投影片
#include<iostream>
using namespace std;
#define MOD 1000000009

int main(){
  long DP[101]={0,1}, s[100]={0,1};
  for(int i=2;i<=100;i++)
    /*      1：上下邊都存在最後一格是左開口
     * s[i-2]：前綴和，到(i-2)格之前的所有點連通方法數，且可以透過選擇(i-1)格時的上下邊其一和目前左開口的格子連通
     * DP[i] ：形成目前合法連通狀態的方法數，後面接上下邊/上右邊/下右邊可以變成下一格的合法狀態
     */
    DP[i]=(1+2*s[i-2]+DP[i-1]*3)%MOD,
    s[i]=(DP[i]+s[i-1])%MOD;
  int T, n;
  cin>>T;
  for(int n; T--; )
    cin>>n, cout<<DP[n]<<endl;
}