// 與b953的差異是『共同子字串』必須要『連續』只需修改動態規劃規則即可(0.2s/47.1MB)
#include<bits/stdc++.h>
using namespace std;

const int MAXN=3501;
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
      short maxL=0;
      for(int i=0;i<ssL[0];i++)
        for(int j=0;j<ssL[1];j++){
          if(ss[0][i]==ss[1][j])
            DP[0][i+1][j+1]=DP[0][i][j]+1,
            maxL=max(maxL,DP[0][i+1][j+1]);
          else
            DP[0][i+1][j+1]=0;
        }
      cout<<maxL<<'\n';
    }else{
      cin>>ss[2];
      ssL[2]=ss[2].length();
      short maxL=0;
      for(int i=0;i<ssL[0];i++){
        bool now=i&1, pre=now^1;
        for(int j=0;j<ssL[1];j++)
          for(int k=0;k<ssL[2];k++)
            if(ss[0][i]==ss[1][j] and ss[1][j]==ss[2][k])
              DP[now][j+1][k+1]=DP[pre][j][k]+1,
              maxL=max(maxL,DP[now][j+1][k+1]);
            else
              DP[now][j+1][k+1]=0;
      }
      cout<<maxL<<'\n';
    }
  }
}