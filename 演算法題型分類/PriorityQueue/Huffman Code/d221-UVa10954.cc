// MIN-HEAP：搭配 greater<long>實現
#include<bits/stdc++.h>
using namespace std;

bool operator>(const long &a,const long &b){ return a>b; }
int main(){
  int N, x;
  while(scanf("%d",&N) and N){
    // MIN_HEAP
    priority_queue<long,vector<long>> PQ;
    for(int i=0;i<N;i++)
      scanf("%d",&x),
      PQ.push(x);
    /* 每次都選取數列中最小的兩個( 分兩次取PQ.top() )
     * 合併後放回去PQ並同時把值加入總和的成本
     */
    long sum=0, min_one, min_two;
    while(PQ.size()>1){
      min_one=PQ.top(), PQ.pop();
      min_two=PQ.top(), PQ.pop();
      sum+=min_one+min_two;
      PQ.push(min_one+min_two);
    }
    printf("%ld\n",sum);
  }
}