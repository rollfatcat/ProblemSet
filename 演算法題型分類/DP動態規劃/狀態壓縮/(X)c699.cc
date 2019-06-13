#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define mod 1000000007

long num[7][1<<20]={};
long DP[2][1<<20]={};
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int N, X, Y, type;
  cin>>N>>X>>Y;
  int maxS=(1<<Y)-1;
  vector<int> state[X];
  for(int i=0;i<N;i++){
    int type, property=0, unit;
    cin>>type, type--;
    for(int j=0; j<Y; j++)
      cin>>unit, property=(property<<1)|unit;
    if(num[type][property]==0) state[type].push_back(property);
    num[type][property]++;
  }
  for(int i=0;i<state[0].size();i++)
    DP[0][state[0][i]]=num[0][state[0][i]];
  for(int type=1;type<X;type++){
    bool nowR=type&1, preR=1^nowR;
    memset(DP[nowR],0,sizeof(DP[0]));
    for(int i=0;i<state[type].size();i++)
      for(int nowS=0; nowS<=maxS; nowS++)
        DP[nowR][ state[type][i]|nowS ]=(DP[nowR][ state[type][i]|nowS ]+num[type][ state[type][i] ]*DP[preR][ nowS ])%mod;
  }
  cout<<DP[(X-1)&1][maxS]<<endl;
}