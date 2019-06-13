#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<unsigned long> DP;
  DP.push_back(1), DP.push_back(1);
  for(int i=1; i<50; i++)
    DP.push_back(DP[i]+DP[i-1]);
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(int n;cin>>n and n;)
    cout<<DP[n]<<endl;
}