// 標準動態規劃解(狀態轉換＋反向總和)
// 枚舉合法狀態(連續0~2個U)，再用全部狀態(2^N)扣除合法狀態即是非法狀態的總和。

#include<bits/stdc++.h>
using namespace std;

int DP[31]={};
int status[31][3]={};
int main(){
  // 前處理
  status[0][0]=1;
  for(int i=1;i<=30;i++){
    status[i][0]=status[i-1][0]+status[i-1][1]+status[i-1][2],
    status[i][1]=status[i-1][0],
    status[i][2]=status[i-1][1];
    DP[i]=(1<<i)-status[i][0]-status[i][1]-status[i][2];
  }
  int N;
  while(scanf("%d",&N) and N)
    printf("%d\n",DP[N]);
}