// 簡單模擬：輸出數字是偶數且大於0的個數

#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M, x;
  while(scanf("%d%d",&N,&M)==2){
    vector<int> cnt(N+1,0);
    while(M--)
      scanf("%d",&x),
      cnt[x]++;
    int ans_cnt=0;
    for(int i=1;i<=N;i++)
      if(cnt[i] and (cnt[i]&1)==0)
        ans_cnt++;
    printf("%d\n",N-ans_cnt);
  }
}