#include<bits/stdc++.h>
using namespace std;

int main(){
  int caseT, N, M, act, x;
  scanf("%d",&caseT);
  for(int caseN=1;caseN<=caseT;caseN++){
    printf("Case %d:\n",caseN);
    scanf("%d %d",&N,&M);
    // 預設是MAX_HEAP
    priority_queue<int,vector<int>> PQ;
    for(int i=0;i<N;i++)
      scanf("%d",&x),
      PQ.push(x);
    // 根據指令操作
    for(int i=0;i<M;i++){
      scanf("%d",&act);
      if(act==2){
        if(PQ.empty())
          puts("It's empty!");
        else
          printf("Max: %d\n",PQ.top()),
          PQ.pop();
      }
      else
        scanf("%d",&x),
        PQ.push(x);
    }
    //
    if(PQ.empty())
      puts("It's empty!");
    else{
      while(PQ.empty()==0)
        printf("%d ",PQ.top()),
        PQ.pop();
      puts("");
    }
  }
}
/*
3 10
3 2 1
2
2
2
2
1 8
2
2
1 20
2
2
*/