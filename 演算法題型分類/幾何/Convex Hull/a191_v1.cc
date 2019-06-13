// 對比：找『最近』的兩點距離 => CDQ
/* 作法 : 作凸包，拿凸包上的點來窮舉 <= 最糟情況是每個點都落在凸包的範圍呢？
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000

struct NODE{
  int x, y, o;
  bool operator<(const NODE &rhs)const{ return (x<rhs.x) or (x==rhs.x and y<rhs.y); }
}node[MAXN], CH_U[MAXN+1], CH_L[MAXN+1]; // CH for Convex Hull
int N, maxD[MAXN]={};

// 每個新掃到的點跟前面的點作叉積(Cross Product)，判斷是否是以逆時針旋轉，也就是叉積值大於 ０
inline int cross(NODE a, NODE b, NODE o){ return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x); }

/* Andrew's Monotone Chain
 * (1) 以 X 座標大小排序，當 X 座標相同則以 Y 座標大小排序
 * (2) 先從起點開始，按照順序掃描，找到下半凸包。
 * (3) 再從終點開始，按照相反順序掃描，找到上半凸包。合起來就是完整的凸包。
 * 分析：可處理有重疊的點、共線的點、退化成線段和點的問題，排序時間O(N㏒N)＋包覆時間O(N)
 */
inline int Monotone_Chain(int L=0,int U=0){
  sort(node,node+N);
  // 同時包下半部＋上半部
  for(int i=0;i<N;i++){
    while(L>=2 and cross(CH_L[L-2],CH_L[L-1],node[i])<=0)  L--;
    while(U>=2 and cross(CH_U[U-2],CH_U[U-1],node[i])>=0)  U--;
    CH_L[L++]=node[i];
    CH_U[U++]=node[i];
  }
  // 把上半部的部分複製到下半部的陣列後面(兩個起終點是相同的)
  for(--U;U;)
    CH_L[L++]=CH_U[--U];
  return L;
}
inline int NodeDis(NODE &a,NODE &b){ return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y); }
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  while(scanInt(N)){
    for(int i=0;i<N;i++)
      scanInt(node[i].x),
      scanInt(node[i].y),
      node[i].o=i, maxD[i]=0;
    int CHnum=Monotone_Chain();
    // 枚舉每個點，對應到凸包涵蓋的點
    for(int i=0;i<N;i++){
      int nowD=0;
      for(int j=0;j<CHnum;j++)
        nowD=max(nowD,NodeDis(node[i],CH_L[j]));
      maxD[ node[i].o ]=nowD;
    }
    // 輸出
    for(int i=0;i<N;i++)
      printf("%d\n",maxD[i]);
  }
}
/*
12
2 1
3 1
1 2
2 2
3 2
4 2
1 3
2 3
3 3
4 3
2 4
3 4

10
18 18
 1 15
10 14
18 13
19 12
 7 10
 8  9
20  9
10  6
 4  5
*/