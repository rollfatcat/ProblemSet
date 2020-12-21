/* 一開始看Ｎ不大以為是要預處理一次用BruteForce解所有方法數
 * 測資的方法數有高達 1e7 個且題目只算方法數應該可以用動態規劃解
 * 假設新增使用者最矮，若最矮的可以插入 DP[n-1][p][r] 的 n-1 人中間的任何位置，位置有(n-2)個，DP[n-1][p][r]*(n-2)；
 * 若最矮的人排在最前面則為 DP[n-1][p-1][r]；若最矮的人排在最後面則為 DP[n-1][p][r-1]
 */
#include<bits/stdc++.h>
using namespace std;

long DP[14][14][14]={};
int main(){
  DP[1][1][1]=1;
  for(int n=2;n<14;n++)
    for(int p=1;p<=n;p++)
      for(int r=1;r<=n;r++)
        DP[n][p][r]=DP[n-1][p][r]*(n-2)+DP[n-1][p-1][r]+DP[n-1][p][r-1];
  int T, n, p, r;
  scanf("%d",&T);
  while(T--)
    scanf("%d %d %d",&n,&p,&r),
    printf("%ld\n",DP[n][p][r]);
}