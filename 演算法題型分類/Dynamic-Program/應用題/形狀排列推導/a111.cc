#include<bits/stdc++.h>
using namespace std;

int main(){
  int DP[101]={};
  for(int i=1;i<=100;i++)
    DP[i]=DP[i-1]+i*i;
  for(int n; cin>>n and n;)
    cout<<DP[n]<<'\n';
}