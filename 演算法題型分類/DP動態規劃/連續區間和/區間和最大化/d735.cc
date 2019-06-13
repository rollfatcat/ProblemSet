// 類似d206，目標是改為輸出區域內最小的區域
#include<bits/stdc++.h>
using namespace std;
const int MaxN=101;

int main(){
  int n, N, minNum;
  int num[MaxN][MaxN];
  int rowSum[MaxN][MaxN]={0};

  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  while(cin>>n){
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        cin>>num[i][j], rowSum[i][j]=rowSum[i-1][j]+num[i][j];
    minNum=0x7fffffff;
    for(int i=0;i<n;i++)
      for(int j=i+1;j<=n;j++){
        int sum=0;
        //窮舉所有第i列到第j列的所有可能性
        for(int k=1; k<=n ;k++){
          if(sum>0) sum=0;
          sum+=rowSum[j][k]-rowSum[i][k];
          if(minNum>sum) minNum=sum;
        }
      }
    cout<<minNum<<endl;
  }
}
/*
4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
*/