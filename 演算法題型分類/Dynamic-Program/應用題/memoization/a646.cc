// 等同空酒瓶換酒問題,但是是給轉換率(和c350.cc/d189-uva11150.cc比較, 難度完全不同)
// 方程:dp[n] = max(dp[n + floor(i*p) - i] + floor(i*p)), 0<i<=n,
// 狀態:dp[n] 表示 n 張包裝紙的最大糖果數，i 是拿多少去兌換。
// 精確度問題：千萬不要用 double 去計算, 用兩個int 紀錄

#include<iostream>
using namespace std;
#define MaxN 1001

int DP[MaxN], a, b;
string ss;
int TopDown(int c){
  if(DP[c]==-1)
    for(int i=1;i<=c;i++){
      int tmp=i*a/b;
      DP[c]=max(DP[c],TopDown(c-i+tmp)+tmp);
    }
  return DP[c];
}
int main(){
  int c;
  while(cin>>c>>ss){
    fill(DP,DP+1+c,-1), DP[0]=0;
    a=0, b=1;
    for(int i=2;i<ss.length();i++)
      a=a*10+(ss[i]-'0'), b*=10;
    cout<<TopDown(c)+c<<endl;
  }
}