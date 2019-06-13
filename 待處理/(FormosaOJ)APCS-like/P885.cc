#include<bits/stdc++.h>
using namespace std;

int main(){
  int caseT, N, len;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d",&N);
    int max_len=0;
    long sum_len=0;
    for(int i=0;i<N;i++)
      scanf("%d",&len),
      max_len=max(len,max_len),
      sum_len+=len;
    puts( (sum_len>(max_len<<1))?"YES":"NO" );
  }
}