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
  vector<long> pool[2];
  bool nowP=0, nxtP=1;
  int now_w=items[0].w;
  pool[nowP].push_back(items[0].v);

  for(int buff,idx=1;idx<N and items[idx].w<=W;idx++){
    if(items[idx].w!=now_w){
      buff=items[idx].w-now_w;
      buff=(buff<20)?(1<<buff):MAXN;
      // 清空現在這個 PriorityQueue，以buff為單位Merge後推到另個 PriorityQueue
      int unit=0;
      long cv=0;
      pool[nxtP].clear();
      sort(pool[nowP].begin(),pool[nowP].end(),compare);
      for(int i=0;i<pool[nowP].size();i++){
        unit++,
        cv+=pool[nowP][i];
        if(unit==buff)
          pool[nxtP].push_back(cv),
          unit=cv=0;
      }
      if(unit)
        pool[nxtP].push_back(cv);
      // 更新 now_w，並交換兩個值
      now_w=items[idx].w;
      swap(nowP,nxtP);
    }
    pool[nowP].push_back(items[idx].v);
  }
  sort(pool[nowP].begin(),pool[nowP].end(),compare);
  printf("%ld\n",pool[nowP][0]);
}
