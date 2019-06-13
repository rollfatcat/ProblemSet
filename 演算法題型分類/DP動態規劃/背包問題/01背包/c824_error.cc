// (X)猜測：用 Huffman-Decode 的方式但是以 c223 變異版本方式達到 O(1) 取最小值和 Push_Heap
// 51%(49% WA)

#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
int N, W;
int idx=0;
struct ITEM{
  int w2; long v;
  bool operator<(const ITEM &rhs)const{ return (w2==rhs.w2)?(v>rhs.v):(w2<rhs.w2); }
  void merge(const ITEM &rhs){ w2=max(rhs.w2,w2)+1, v+=rhs.v; }
}items[MAXN], now1, now2, tmp;
//struct compare{ bool operator()(ITEM &a, ITEM &b){ return (a.w2==b.w2)?(a.v<b.v):(a.w2>b.w2); }};
priority_queue<ITEM,vector<ITEM>> PQ;

ITEM PopITEM(){
  if(PQ.empty()){  return items[idx++]; }
  if(idx==N or PQ.top()<items[idx]){
    tmp=PQ.top(); PQ.pop(); return tmp;
  }
  return items[idx++];
}

int main(){
  scanf("%d %d",&N,&W);
  for(int i=0;i<N;i++)
    scanf("%d %ld",&items[i].w2,&items[i].v);
  sort(items,items+N);
  //
  while(idx<N or PQ.size()>1){
    now1=PopITEM();
    if(now1.w2==W){ printf("%ld\n",now1.v); break; }

    now2=PopITEM();
    if(now2.w2==W){ printf("%ld\n",now2.v); break; }

    if(now1.w2<now2.w2)
      now1.w2=now2.w2,
      PQ.push(now1),
      now1=PopITEM();
    now1.merge(now2);
    PQ.push(now1);
  }
  if(idx==N and PQ.size()==1)
    printf("%ld\n",PQ.top().v);
}
/*
7 2
0 5
1 4
1 3
2 1
2 2
2 3
2 4

9 13
11 21
10 12
12 14
14 37
12 14
10 5
11 3
13 17
14 1000
*/