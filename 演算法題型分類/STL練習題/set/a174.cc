// 利用 C++ 的STL 實作 HashTable (0.5s)
#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, Q, opt, num, bucket;
  while(scanf("%d%d",&Q,&N)!=EOF){
    set<int> memo[N];
    while(Q--){
      scanf("%d",&opt);
      if(opt==3){ // 輸出哈希表，若有兩個以上的數字在同一個區間內輸出時由小到大
        puts("===== s =====");
        for(int i=0;i<N;i++){
          printf("[%03d]:",i);
          int tot=0;
          for(set<int>::iterator it=memo[i].begin();it!=memo[i].end();it++,tot++){
            if(tot) printf(" -> ");
            printf("%d",*it);
          }
          if(tot) printf(" -> ");
          puts("NULL");
        }
        puts("===== e =====");
      }
      else{
        scanf("%d",&num), bucket=num%N;
        if(opt==1){ //若在存入時，發現數字重複，則不予理會
          if(memo[bucket].count(num)==0)
            memo[bucket].insert(num);
        }
        else{ //若在刪除時，發現數字不存在，則不予理會
          if(memo[bucket].count(num))
            memo[bucket].erase(num);
        }
      }
    }
  }
}
/*
13 5
1 17
1 8
3
3
1 18
1 24
3
1 37
1 64
1 84
3
2 18
3
*/