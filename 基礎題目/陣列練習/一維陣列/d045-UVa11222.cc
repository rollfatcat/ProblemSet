// 題目保證：題目的號碼<=10000 且 每個人解題的數量<=1000
// 題目查詢『某個數字有沒有出現過』的作法與『眾數』雷同
// 同時介紹 set 的用法
#include<bits/stdc++.h>
using namespace std;

int main(){
  int caseT, N, x;
  int cnt[10001];
  scanf("%d",&caseT);
  for(int caseN=1;caseN<=caseT;caseN++){
    memset(cnt,0,sizeof(cnt));
    vector<short> memo[3];
    for(int usr=0;usr<=2;usr++)
      for(scanf("%d",&N);N--;)
        scanf("%d",&x), memo[usr].push_back(x), cnt[x]++;
    for(int usr=0;usr<=2;usr++){
      int tot=0;
      for(int no:memo[usr])
        if(cnt[no]==1)
          memo[usr][tot++]=no;
      memo[usr].resize(tot);
    }
    int sz=max(memo[0].size(), max(memo[1].size(),memo[2].size()));
    printf("Case #%d:\n",caseN);
    for(int usr=0;usr<=2;usr++)
      if(sz==memo[usr].size()){
        printf("%d %d",usr+1,sz);
        sort(memo[usr].begin(),memo[usr].end());
        for(int no:memo[usr])
          printf(" %d",no);
        puts("");
      }
  }
}
/*
4
3 1 2 3
4 4 5 6 7
5 8 9 10 11 12
2 1 5
2 2 3
3 2 3 1
6 400 401 402 403 404 405
2 101 100
7 400 401 402 403 404 405 406
1 1
1 2
1 3
*/