/* 『共同子序列』和『共同序列』的差異在於『連續性』
 * b953是前者而本題(b954)是屬於後者。
 * 注意：本題 scanf()讀取時會出現格式錯誤需要 cin 才會正確(原因不明？)
 * 狀態轉移：dp[x][y]=( ss[0][x]==s[1][y] )? d[x-1][y-1]: 0;
 *         dp[x][y][z]=( ss[0][x]==s[1][y]==ss[2][z] )? d[x-1][y-1][z-1]: 0;
 *  三個字串的因為記憶體空間有限，需要搭配滾動陣列處理。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=3500;
string ss[3];
short dp[2][MaxL][MaxL];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	
  for(int T;cin>>T;){
    cin>>ss[0]>>ss[1];
    memset(dp,0,sizeof(dp[0]));
    short maxL=0;
    if(T==2){	
      for(int i=1;i<=ss[0].length();i++)
        for(int j=1;j<=ss[1].length();j++)
          if(ss[0][i-1]==ss[1][j-1])
          	dp[0][i][j]=dp[0][i-1][j-1]+1,
          	maxL=max(maxL,dp[0][i][j]);
          else
          	dp[0][i][j]=0;
    }else{
      cin>>ss[2];
      short pre=0, now=1;
      for(int i=1;i<=ss[0].length();i++,swap(pre,now)){
        for(int j=1;j<=ss[1].length();j++)
        	for(int k=1;k<=ss[2].length();k++)
            if(ss[0][i-1]==ss[1][j-1] and ss[0][i-1]==ss[2][k-1])
              dp[now][j][k]=dp[pre][j-1][k-1]+1,
              maxL=max(maxL,dp[now][j][k]);
            else
              dp[now][j][k]=0;
      }
    }
    cout<<maxL<<'\n';
  }
}