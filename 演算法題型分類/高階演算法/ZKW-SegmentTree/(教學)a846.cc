// 用這題說明 為何我們需要 RMQ ?
#include<bits/stdc++.h>
using namespace std;

int score[1000];
int sum[1000];
int main(){
  int T, N, Q, sL;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d",&N,&Q);

    scanf("%d",&score[0]);
    sum[0]=score[0];
    for(int i=1;i<N;i++)
      scanf("%d",&score[i]),
      sum[i]=sum[i-1]+score[i];
    int act, qL, qR;
    while(Q--){
      scanf("%d %d",&act,&qL);
      if(act==1){
        scanf("%d",&qR);
        sL=score[qL];
        for(int i=qL+1;i<=qR;i++)
          sL=max(sL,score[i]);
        printf("%d\n",sL);
      }else if(act==2){
        scanf("%d",&qR),
        sL=(qL)?sum[qL-1]:0;
        printf("%d\n",(sum[qR]-sL)/(qR-qL+1));
      }else printf("%d\n",score[qL]);
    }
  }
}