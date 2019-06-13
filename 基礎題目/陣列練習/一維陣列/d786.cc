// 算平均值(Ｃ版本)，型態的介紹與輸出時小數點位數的控制方法
// 完成後接著挑戰 d140
#include<stdio.h>

int main(){
  int T, N, sum, i, x;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    for(sum=i=0;i<N;i++){
      scanf("%d",&x);
      sum+=x;
    }
    printf("%.2lf\n",(double)sum/N);
  }
  return 0;
}