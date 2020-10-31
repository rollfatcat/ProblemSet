#include<bits/stdc++.h>
using namespace std;

int cnt[101];
int main(){
  int N;
  while(scanf("%d",&N) and N){
    memset(cnt,0,sizeof(cnt));
    int all_cnt=0;
    for(int x,i=0;i<N;i++)
      scanf("%d",&x), x%=100,
      all_cnt+=(x)?cnt[100-x]:cnt[0],
      cnt[x]++;
    printf("%d\n",all_cnt);
  }
}