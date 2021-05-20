// https://blog.csdn.net/qq_29694475/article/details/74619897?utm_source=copy
// 用兩個一維陣列交替的方式模擬DP
/*
dp[i][s]为当i-1行满时,i行的状态是s的方案数
i状态是now_s,i-1状态是pre_s,在第i行横向扫描时,
1.
一个位置若是横着放,则下一个状态是now_s<<2|3
且对应i-1的状态是pre_s<<2|3 (上一行这个两个位置必不为空才能不放)
2.
一个位置若是竖着放,则下一个状态是now_s<<1|1
且对应i-1的状态是pre_s<<1 (上一行这个位置必为空才能放)
3.
一个位置不放,则下一个状态是now_s<<1
且对应i-1的状态是pre_s<<1|1 (上一行这个位置必不为空才能不放)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N=12;
typedef long long llt;
llt dp[2][1<<N];
int n, m, now;


void dfs(int col, int now_s, int pre_s){
  if(col>m) return;
  if(col==m){
    dp[now][now_s]+=dp[!now][pre_s];  return;
  }
  // 從0狀態回推到所有匹配的狀態
  dfs(col+1, now_s<<1,   pre_s<<1|1); //(3) 這一格不放,代表因為前一行已經放一個直豎的卡著
  dfs(col+1, now_s<<1|1, pre_s<<1);   //(2) 這一格放直豎, 代表前一行必須是空的
  dfs(col+2, now_s<<2|3, pre_s<<2|3); //(1) 這一格放橫豎, 因為上一行必須維持填滿的狀態, 必定是 11
}

int main(){
  while(scanf("%d %d", &n, &m)){
    if(n==0 && m==0) break;
    if(n<m) swap(n, m);
    memset(dp, 0, sizeof(dp));
    dp[0][(1<<m)-1]=1;//假设上一行一开始是全满的(第一次是虚拟的上一行)
    now=1;
    for(int i=0; i<n; i++){
      dfs(0, 0, 0);
      memset(dp[!now],0,sizeof(dp[!now]));
      now=!now;
    }
    printf("%lld\n", dp[!now][(1<<m)-1]);
  }
}