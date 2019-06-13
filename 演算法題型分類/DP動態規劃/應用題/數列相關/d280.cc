// 詢問N顆骰子出現點數總和是M的方法數，N<=20方法數可以用long紀錄就好
#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<long> DP[21];
  DP[1].push_back(0);
  for(int i=1;i<=6;i++)
    DP[1].push_back(1);
  for(int idx=2,nowPoint,prePoint=6; idx<=20; idx++){
    nowPoint=(idx<<2)+(idx<<1);
    DP[idx].assign(nowPoint+1,0);
    for(int i=1;i<=6;i++)
      for(int j=idx-1;j<=prePoint;j++)
        DP[idx][j+i]+=DP[idx-1][j];
    prePoint=nowPoint;
  }
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int T,n,m;
  for(cin>>T; T--; )
    cin>>n>>m, cout<<DP[n][m]<<endl;
}