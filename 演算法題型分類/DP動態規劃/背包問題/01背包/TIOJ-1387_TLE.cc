// 10%(AC)+90%(TLE)
// 多重背包有一個二進制優化，也就是當物品限制最多拿Ｃ個時，我們可以利用二進制組合的方式
//，轉換到0/1背包問題，因此我們會得到新的 N㏒C 個物品跑一次0/1背包，因此複雜度落在O(N㏒CW)

#include<bits/stdc++.h>
using namespace std;

struct ITEM{
  int w, v, n;
}item[50];
int DP[10001]={};

int main(){
  int N, W;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d",&item[i].w),
    scanf("%d",&item[i].v),
    scanf("%d",&item[i].n);
  scanf("%d",&W);
  for(int i=0;i<N;i++){
    int nown=min(item[i].n,W/item[i].w);
    for(int k=1; nown>0; k>>=1){
      if(k>nown)
        k=nown;
      nown-=k;
      for(int j=W; j>=item[i].w*k; j--)
        DP[j]=max(DP[j], DP[j-item[i].w*k]+item[i].v*k);
    }
  }
  printf("%d\n",DP[W]);
}
/*
5
1 1 1
2 2 1
3 3 1
4 4 1
5 5 1
15
*/