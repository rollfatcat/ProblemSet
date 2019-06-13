// 數論題：哥德巴赫猜想：(A)任一大於2的偶數都可寫成兩個質數之和
#include<bits/stdc++.h>
using namespace std;

int main(){
  // 前455個質數
  int prime_num=2;
  int prime[455]={2,3};
  for(int now=5;prime_num<455;now+=2){
    int test=1;
    for(;test<prime_num and now%prime[test];test++);
    if(test==prime_num)
      prime[prime_num]=now, prime_num++;
  }
  //
  int T, idx;
  scanf("%d",&T);
  while(T--)
    scanf("%d",&idx),
    printf("%d\n",prime[idx+1]);
}