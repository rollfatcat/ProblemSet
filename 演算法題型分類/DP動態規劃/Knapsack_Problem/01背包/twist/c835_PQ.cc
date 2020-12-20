// 觀察可以發現背包的空間是1048576(2^20)而物品的數量高達1,000,000個不可能用01背包做法完成
// 想法與題目：ZJ-824 相同
// 作法則是用 PriorityQueue 實現程式碼會更加簡潔
// 不需做重量離散化的步驟
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000001;
int N, W, tot=0;
struct ITEM{
  int w, v;
  bool operator<(const ITEM &rhs)const{ return (w==rhs.w)?(v>rhs.v):(w<rhs.w); }
}items[MAXN];

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
struct compare{ bool operator()(long &a,long &b){ return a<b; } };
int main(){

  scanInt(N),
  scanInt(W);
  for(int i=0;i<N;i++){
    scanInt(items[tot].w),
    scanInt(items[tot].v);
    if(items[tot].w<=W)
      tot++;
  }
  if(tot==0){ puts("0"); return 0; }

  // 依據重量由小到大排序，讓相同則依據價值由大到小排序
  sort(items,items+tot);
  if(items[tot-1].w<W)
    items[tot++]={W,0};
  N=tot;
  // 交替使用兩個 PriorityQueue
  priority_queue<long,vector<long>,compare> pool[2];
  bool nowP=0, nxtP=1;
  int now_w=items[0].w;
  pool[nowP].push(items[0].v);

  for(int buff,idx=1;idx<N and items[idx].w<=W;idx++){
    if(items[idx].w!=now_w){
      buff=items[idx].w-now_w;
      buff=(buff<20)?(1<<buff):MAXN;
      // 清空現在這個 PriorityQueue，以buff為單位Merge後推到另個 PriorityQueue
      int unit=0;
      long cv=0;
      while(pool[nowP].empty()==0){
        unit++,
        cv+=pool[nowP].top(),
        pool[nowP].pop();
        if(unit==buff)
          pool[nxtP].push(cv),
          unit=cv=0;
      }
      if(unit)
        pool[nxtP].push(cv);
      // 更新 now_w，並交換兩個值
      now_w=items[idx].w;
      swap(nowP,nxtP);
    }
    pool[nowP].push(items[idx].v);
  }
  printf("%ld\n",pool[nowP].top());
}
/*
9 13
10 5
10 12
11 3
11 21
12 14
12 14
13 17
14 37
14 1000
*/