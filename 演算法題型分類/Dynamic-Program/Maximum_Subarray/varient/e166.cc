/* 『環狀』的連續區間和最大化(至少要選擇一個數字)
 * 初始想法：更新最大區間時紀錄起終點，盡量選擇起點號碼越後面的(X)
 * 暴力法：數量不多(1e3)，利用前綴和枚舉所有的起終點並計算端點內連續和和端點外的
 * 正解：
 * 動態規劃，順向處理時一並紀錄[1,N]在位置Ｎ時和『左端點連接』的連續區間最大和
 * 之後逆向枚舉和『右端點連接』的連續區間最大和＋『左端點連接』的連續區間最大和
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001

int org[MAXN]; // 原始數據
int sum[MAXN]; // sum[i]：代表從org[1]+...org[i]的最大區間和
int main(){
  int N;
  while(scanf("%d",&N) and N){
    memset(sum,0,sizeof(sum));
    int ans_sum=-(1<<30);
    int continuous_sum=0;
    int from_start_sum=0;

    for(int i=1;i<=N;i++){
      scanf("%d",&org[i]);
      from_start_sum+=org[i];
      sum[i]=max(from_start_sum,sum[i-1]);
      continuous_sum=(continuous_sum<0)? org[i]: (org[i]+continuous_sum);
      ans_sum=max(ans_sum,continuous_sum);
    }
    int from_end_sum=0;
    for(int i=N;i>=1;i--)
      from_end_sum+=org[i],
      ans_sum=max(ans_sum,from_end_sum+sum[i-1]);
    printf("%d\n",ans_sum);
  }
}

/*
5
1 2 -4 4 -5
5
1 2 -1 4 -5
5
1 2 -4 4 5
0
*/