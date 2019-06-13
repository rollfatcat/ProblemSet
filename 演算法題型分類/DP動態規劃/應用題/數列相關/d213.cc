// 題目說明的不是很清楚(但作法就是字面上的處理即可)
#include<iostream>
using namespace std;

int main(){
  unsigned long DP[64][2]={};
  DP[0][0]=DP[0][1]=2;
  for(int i=1;i<10;i++)
    DP[i][0]=(DP[i-1][0]<<1), DP[i][1]=DP[i][0]+DP[i-1][1];
  for(int i=10;i<63;i++){
    DP[i][0]=(DP[i-1][0]<<1); //生產的速度是前一年的兩倍
    for(int j=i-9;j<=i;j++) //因為兔子的壽命只有10年，所以累計的範圍是從現在往前推10個狀態
      DP[i][1]+=DP[j][0];
  }
  for(int n; cin>>n;)
    cout<<DP[n][1]<<endl;
}