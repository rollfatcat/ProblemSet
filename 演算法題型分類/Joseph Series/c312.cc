
/* 題目是標準的『Joseph Problem』
 * MAXN = MAXK = 1e5
 * 50%(vector模擬) / 100%(動態規劃)
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  while(scanf("%d %d",&N,&K)!=EOF){
    int now=0;
    for(int t=2;t<=N;t++)
      now=(now+K)%t;
    printf("%d\n",now+1);
  }
}