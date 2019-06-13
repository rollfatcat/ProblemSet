#include<stdio.h>
int main(){
  int i,j,temp;
  int N_len,stop,carry_in;
  int now_N[1000];

  // initail
  N_len=1;
  now_N[0]=1;

  scanf("%d",&stop);
  //main
  for(i=1;i<=stop;i++){
    for(carry_in=j=0;j<N_len;j++){
      temp=now_N[j]*i+carry_in;
      carry_in=temp/10000;
      now_N[j]=temp%10000;
    }
    if(carry_in>0)
      now_N[N_len++]=carry_in;
  }
  //output
  printf("%d",now_N[N_len-1]);
  for(j=N_len-2;j>=0;j--)
    printf("%04d",now_N[j]);
  return 0;
}