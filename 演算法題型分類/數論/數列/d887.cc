// 第一眼感覺是等價括號配對，但這一題一定得用DP解
// 此題等價於 c453(TIO2003的P2)，計算：(2n)!/(n!n!) =>Catalan Number
// 證明：https://johnmayhk.wordpress.com/2014/02/03/cn/
/*
C(0,0) = 1
C(1,1) = C(0,0)
C(2,2) = C(1,0)+C(1,1)
C(3,3) = C(2,0)+C(2,1)+C(2,2)
C(4,4) = C(3,0)+C(3,1)+C(3,2)+C(3,3)
…
C(N,N) = C(N−1,0)+C(N−1,1)+…+C(N−1,N−1)
*/
#include<iostream>
using namespace std;

long DP[26][26]={};
int main(){
  for(int i=0;i<=25;i++)
    DP[i][0]=1;
  for(int i=1;i<=25;i++)
    for(int j=1;j<=i;j++) // Left+Up
      DP[i][j]=DP[i][j-1]+DP[i-1][j];
  for(int n;cin>>n;)
    cout<<DP[n][n]<<endl;
}