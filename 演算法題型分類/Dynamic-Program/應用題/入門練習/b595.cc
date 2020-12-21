#include<stdio.h>

inline int Cost(int x){ return (x-200)*(x-200); }
int main(){
  int pos[31]={0};
  int DP[31]={0};
  short from[31], buff[31];
  for(int N;scanf("%d",&N)!=EOF and N;){
    for(int i=1;i<=N;i++)
      scanf("%d",&pos[i]),
      DP[i]=Cost(pos[i]), from[i]=0;
    // 動態規劃：找最低成本並標記來自於哪個點
    for(int i=2;i<=N;i++)
      for(int j=1;j<i;j++){
        int v=Cost(pos[i]-pos[j])+DP[j];
        if(DP[i]>v) DP[i]=v, from[i]=j;
      }
    // 輸出
    int L=0;
    for(int now=N; now; now=from[now])
      buff[L++]=now;
    putchar('0');
    for(int i=L-1;i>=0;i--)
      printf(" %d",buff[i]);
    puts("");
  }
}