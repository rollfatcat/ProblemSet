// 觀察可以發現背包的空間是1048576(2^20)而物品的數量高達1,000,000個不可能用01背包做法完成
// 想法與題目：ZJ-824 相同，
//    作法用Queue＋MergeSort合併方式實現(0.2s)
//    作法用vector＋sort實現(0.8s)
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
bool compare(long a,long b){ return a>b; }
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
  queue<long> Q[2];
  int now_w=items[0].w;
  Q[0].push(items[0].v);

  for(int buff,idx=1;idx<N and items[idx].w<=W;idx++){
    if(items[idx].w!=now_w){
      while(Q[1].empty()==0)
        Q[0].push(Q[1].front()),
        Q[1].pop();

      buff=items[idx].w-now_w;
      buff=(buff<20)?(1<<buff):MAXN;
      // 清空現在這個 PriorityQueue，以buff為單位Merge後推到另個 PriorityQueue
      int unit=0;
      long cv=0;
      while(Q[0].empty()==0){
        unit++,
        cv+=Q[0].front(),
        Q[0].pop();
        if(unit==buff)
          Q[1].push(cv),
          unit=cv=0;
      }
      if(unit)
        Q[1].push(cv);
      // 更新 now_w
      now_w=items[idx].w;
    }
    while(Q[1].empty()==0 and Q[1].front()>items[idx].v)
      Q[0].push(Q[1].front()),
      Q[1].pop();
    Q[0].push(items[idx].v);
  }
  printf("%ld\n",Q[0].front());
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