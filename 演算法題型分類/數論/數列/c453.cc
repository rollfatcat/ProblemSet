// 對照 d887 => 計算：(2n)!/(n!n!) =>Catalan Number
// 問題可以等價為：a229括號配對算數量
#include<iostream>
using namespace std;

long DP[21][21]={};
int main(){
  for(int i=0;i<=20;i++)
    DP[i][0]=1;
  for(int i=1;i<=25;i++)
    for(int j=1;j<=i;j++) // Left+Up
      DP[i][j]=DP[i][j-1]+DP[i-1][j];
  for(int n;cin>>n;)
    cout<<DP[n][n]<<endl;
}