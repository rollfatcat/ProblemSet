// 簡單DFS模擬 不需要剪枝處理
#include<stdio.h>
int N, val[5], num[5];
void DFS(int turn,int rem){
  int i, cnt;
  if(turn==N){
    if(rem==0){
      printf("(%d",num[0]);
      for(i=1;i<N;i++)
        printf(",%d",num[i]);
      printf(")\n");
    }
    return;
  }
  for(i=0,cnt=rem/val[turn];i<=cnt;i++)
    num[turn]=i,  DFS(turn+1,rem-val[turn]*i);
}
int main(){
  scanf("%d",&N);
  int i, money;
  for(i=0;i<N;i++)
    scanf("%d",&val[i]);
  scanf("%d",&money);
  DFS(0,money);
}
