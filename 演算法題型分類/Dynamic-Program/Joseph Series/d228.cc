// 動態規劃版本的喬瑟夫問題練習
#include<bits/stdc++.h>
using namespace std;

int main(){
  int caseT, N, K, M;
  scanf("%d",&caseT);
  for(int caseN=1;caseN<=caseT;caseN++){
    scanf("%d",&N);
    scanf("%d",&K);
    scanf("%d",&M);
    int num=N-M;
    for(int t=N-M+1;t<=N;t++)
      num=(num+K)%t;
    printf("Case %d: %d\n",caseN,num+1);
  }
}
/*
4
6 3 3
8 6 6
11 99 11
23 13 23
*/