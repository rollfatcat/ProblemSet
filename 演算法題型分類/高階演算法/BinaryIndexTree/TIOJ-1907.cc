// 二維版本的逆數對問題
// 因為範圍不大所以第一個維度用CountSort概念，第二維度用BIT維護
// 題目要求是嚴格偏序，所以當Ｘ相同時要全部查詢完後再一次全部更新
// BIT 紀錄的是『區段』的資訊，所以運算符號是 max()，代表區間內的最大值
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1001;
short BIT[MAXN];
inline int lowbit(int x){ return x&-x; }
inline int query(int x,short out=0){
  for(;x;x-=lowbit(x))
    out=max(out,BIT[x]);
  return out;
}
inline void update(int x,short out){
  for(;x<=1000;x+=lowbit(x))
    BIT[x]=max(BIT[x],out);
}
int main(){
  int caseT, N, w, h;
  scanf("%d",&caseT);
  while(caseT--){
    vector<short> bucket[MAXN];
    scanf("%d",&N);
    for(int i=0;i<N;i++)
      scanf("%d %d",&w,&h),
      bucket[w].push_back(h);
    memset(BIT,0,sizeof(BIT));
    for(short x: bucket[1])
      update(x,1);
    for(short i=2;i<=1000;i++){
      vector<short> rec(bucket[i].size(),0);
      for(short j=0;j<bucket[i].size();j++)
        rec[j]=query(bucket[i][j]-1)+1;
      for(short j=0;j<bucket[i].size();j++)
        update(bucket[i][j],rec[j]);
    }
    printf("%d\n",query(1000));
  }
}
/*
4
3
20 30 40 50 30 40
4
20 30 10 10 30 20 40 50
3
10 30 20 20 30 10
4
10 10 20 30 40 50 39 51
*/