// Floyd_Wall 做DP解，需要了解Floyd的特性
// http://mypaper.pchome.com.tw/iustlovefish/post/1313374093
#include<iostream>
#include<cstring>
using namespace std;

int DP[51][32][32];
int main(){
  string ss;
  for(int m; cin>>m; ){
    memset(DP,0,sizeof(DP));
    int i,j,st,ed,dis;
    for(i=0;i<m;i++)
      for(cin>>ss, j=0;j<m;j++)
        DP[1][i][j]=ss[j]=='1';
    cin>>st>>ed>>dis;
    for(int step=2;step<=dis;step++)
      for(int k=0;k<m;k++)
        for(int i=0;i<m;i++)
          for(int j=0;j<m;j++)
            DP[step][i][j]+=DP[step-1][i][k]*DP[1][k][j];
    int sum=0;
    for(int i=1;i<=dis;i++)
      sum+=DP[i][st-1][ed-1];
    cout<<sum<<endl;
  }
}