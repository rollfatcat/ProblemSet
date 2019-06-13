// (X)vector 紀錄caseN 降低查詢成本，但記憶體耗量過大
// (X)set 查詢成本(㏒N)過高
// (O)物品最多20個，暴力法枚舉物品屬於哪一堆(剪枝：先將第一個物品分給A堆，避免對稱性問題)

#include<bits/stdc++.h>
using namespace std;
#define MAXN 20

int N, diff;
int w[MAXN];
void DFS(int idx,int sumA,int sumB){
  if(idx==N){
    diff=min(diff,abs(sumA-sumB) );
    return;
  }
  DFS(idx+1,sumA+w[idx],sumB),
  DFS(idx+1,sumA,sumB+w[idx]);
}
int main(){
  while(scanf("%d",&N)!=EOF){
    for(int i=0;i<N;i++)
      scanf("%d",&w[i]);
    diff=1<<30;
    DFS(1,w[0],0);
    printf("%d\n",diff);
  }
}