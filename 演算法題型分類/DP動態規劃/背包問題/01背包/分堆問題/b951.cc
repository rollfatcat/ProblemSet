// 題目保證每筆測資數量是5000 總合不會超過200000(相較於b941，無法用Brute-Force DFS解題)
/* 題目需求是將所有樹枝分成『兩堆』一堆構成長另一組構成寬，
 * 目標是長寬乘積(面積)最大化 => 長寬的差距最小化 => 分堆的01背包問題
 * 一維陣列(4.1s/1.1MB) vs 映射表＋vector(6s/972KB)
 */
#include<bits/stdc++.h>
using namespace std;

int DP[200002];
int main(){

  string ss;
  int num[5002], N, sum;
  while(getline(cin,ss)){
    N=sum=num[0]=0;
    for(int i=0;i<ss.length();i++)
      if(ss[i]>='0' and ss[i]<='9')
        num[N]=(num[N]<<3)+(num[N]<<1)+ss[i]-'0';
      else
        sum+=num[N], num[++N]=0;
    sum+=num[N++];
    // 01 knapsack
    memset(DP,0,sizeof(DP));
    int HS=sum>>1;
    for(int i=0;i<N;i++)
      for(int j=HS;j>=num[i];j--)
        DP[j]=max(DP[j], DP[j-num[i]]+num[i]);
    cout<<(long)DP[HS]*(sum-DP[HS])<<'\n';
  }
}