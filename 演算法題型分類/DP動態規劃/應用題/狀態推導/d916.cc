// 彩色煙火之間要間隔至少Ｍ個單色煙火
// 動態規劃解：f(x)=f(x-1)+f(x-1-m)
/* 狀態轉移方式：間隔至少Ｍ個單色煙火 => Ｍ+1種狀態(只有單色煙火/ 有彩色煙火+連續0-(Ｍ-1)個單色煙火)
 * 狀態轉移時，對於當下的狀態只會有選擇『單色』和『彩色』兩類 => 需要滾動陣列實作
 */

#include<bits/stdc++.h>
using namespace std;
#define MOD 10000

inline int solve2D(int N,int M,int ret=1){ // 狀態轉移的推導＋滾動陣列實作
  bool now, pre;
  int DP[2][3001]={{},{}};
  // 總數小於等於Ｍ個時只有Ｍ+1種可能的狀態
  for(int i=0;i<M;i++)
    DP[M&1][i]=1;
  // 總數大於Ｍ個時會出現『限制』的情況需要考慮狀態轉移問題
  for(int i=M+1;i<=N;i++){
    now=i&1, pre=now^1;
    for(int j=0;j<M;j++)
      DP[now][j+1]=DP[pre][j];
    DP[now][0]=(1+DP[pre][M])%MOD;
    DP[now][M]=(DP[now][M]+DP[pre][M])%MOD;
  }
  for(int i=0;i<=M;i++)
    ret=(ret+DP[N&1][i])%MOD;
  return ret;
}
inline int solve1D(int N,int M){ // 規律性公式解
  int DP[3001]={1};
  for(int i=1;i<=M;i++)
    DP[i]=DP[i-1]+1;
  for(int i=M+1;i<=N;i++)
    DP[i]=(DP[i-1]+DP[i-1-M])%MOD;
  return DP[N];
}

int main(){
  int N, M;
  while(scanf("%d%d",&N,&M)==2)
    //printf("%d  ",solve1D(N,M)),
    printf("%d\n",solve2D(N,M));
}