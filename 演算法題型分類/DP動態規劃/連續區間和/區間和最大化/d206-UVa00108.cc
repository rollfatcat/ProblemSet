//
#include<iostream>
using namespace std;
#define MaxN 101

int main(){
  int n, N, maxNum;
  int num[MaxN][MaxN];
  int rowSum[MaxN][MaxN]={0};

  while(cin>>n){
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        cin>>num[i][j];
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        rowSum[i][j]=rowSum[i][j-1]+num[i][j];

    maxNum=0xffffffff;
    for(int i=1;i<=n;i++)
      for(int j=i;j<=n;j++){
        int sum=0;
        //窮舉所有第i行到第j行的所有可能性
        for(int k=1; k<=n ;k++){
          sum+=rowSum[k][j]-rowSum[k][i-1];
          if(sum>maxNum) maxNum=sum;
          if(sum<0) sum=0;
        }
      }
    cout<<maxNum<<endl;
  }
}