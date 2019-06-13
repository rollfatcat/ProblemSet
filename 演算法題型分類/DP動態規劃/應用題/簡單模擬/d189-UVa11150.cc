// 空酒瓶換酒問題, 但是可以『借空酒瓶』用DP解
#include<iostream>
using namespace std;

int main(){
  int DP[201], N;
  DP[0]=DP[1]=0,  DP[2]=1;
  for(int i=3;i<=200;i++)
    DP[i]=DP[i/3+i%3]+(i/3);
  while(cin>>N)
    cout<<N+DP[N]<<endl;
}