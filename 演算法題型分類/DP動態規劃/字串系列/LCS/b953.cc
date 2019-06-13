// 改良 a252 的三維DP 降至 二維的實作方式(0.1s/24.4MB)
#include<bits/stdc++.h>
using namespace std;

const int MAXN=2501;
short DP[2][MAXN][MAXN];
int main(){
  string ss[3];
  int N, ssL[3];
  while(cin>>N){
    memset(DP,0,sizeof(DP));
    cin>>ss[0]>>ss[1];
    ssL[0]=ss[0].length(),
    ssL[1]=ss[1].length();
    if(N==2){
      for(int i=0;i<ssL[0];i++)
        for(int j=0;j<ssL[1];j++)
          DP[0][i+1][j+1]=(ss[0][i]==ss[1][j])?(DP[0][i][j]+1):(max(DP[0][i+1][j],DP[0][i][j+1]));
      cout<<DP[0][ssL[0]][ssL[1]]<<'\n';
    }else{
      cin>>ss[2];
      ssL[2]=ss[2].length();
      for(int i=0;i<ssL[0];i++){
        bool now=i&1, pre=now^1;
        for(int j=0;j<ssL[1];j++)
          for(int k=0;k<ssL[2];k++)
            if(ss[0][i]==ss[1][j] and ss[1][j]==ss[2][k])
              DP[now][j+1][k+1]=DP[pre][j][k]+1;
            else
              DP[now][j+1][k+1]=max(max(DP[pre][j+1][k+1],DP[now][j][k+1]),DP[now][j+1][k]);
      }
      cout<<DP[ssL[0]&1^1][ssL[1]][ssL[2]]<<'\n';
    }
  }
}