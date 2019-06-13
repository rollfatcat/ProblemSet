// 合適的DP練習題目, n必須記錄
#include<iostream>
#include<cstring>
using namespace std;

int DP[1000001];
int TopDown(int n){
  if(DP[n]==-1)
    DP[n]=TopDown(n-TopDown(n-1))+TopDown(n-1-TopDown(n-2));
  return DP[n];
}
int main(){
  memset(DP,0xff,sizeof(DP));
  DP[1]=DP[2]=1;
  for(int i=3;i<=1000000;i++)
    TopDown(i);
  int n;
  while(cin>>n and n)
    cout<<TopDown(n)<<endl;
}