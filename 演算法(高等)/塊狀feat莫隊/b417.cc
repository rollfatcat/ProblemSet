// 莫隊算法(僅支援離線+塊狀處理，以下是不帶修改版本)
// 教學文件：https://blog.csdn.net/u011815404/article/details/88317786
/* 1. 維護curL,curR兩個指針代表當前所維護的區間左界和右界，當要處理下一個詢問時，我們邊將左右界移動到該次詢問的左右界，
 * 邊處理進來當前維護區間的元素和出去當前維護區間的元素；處理進來和出去的元素這件事情應該可以快速完成(O(1) or O(lgn) )
 * 2. 當curL和curR成功移動到目前詢問的左右界，我們應該可以快速獲得該次詢問的答案(O(1) or O(lgn))。
 * 3. 莫隊算法的精華所在：該如何安排詢問順序使得curL和curR的移動次數不會太多次？
 * 運用分塊思想，假設將序列切成K塊，對於詢問左界在同一塊的詢問放在一起，右界則遞增排序。
 * 這樣做的話時間會是怎麼樣呢？
 * 先分析左界移動次數：在同一塊的詢問中，每次curL移動到詢問左界的移動次數不會超過(N/K)次(該塊的大小就只有N/K)，
 * 不同塊的左界移動最多總共也只有N次，所以左界移動的時間複雜度為O(Q*N/K)
 * 而同一塊中的右界因為是遞增的，移動次數最多N次，對於不同塊因為最多也只有K塊，每次最多花費O(N)，那麼總體時間就是O(K*N)。
 * 取Ｋ=sqrt(N)，我們有了一個時間複雜度O(Q*sqrt(N)+N*sqrt(N))的作法！
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define MAXQ 1000001

int ans_now;
int num[MAXN];  // 原始資料
int cnt[MAXN];  // 每個數字的個數
int show[MAXN]; // 出現最多次數的數字個數
int ansn[MAXQ]; // 每個查詢中最多的數字
int ansc[MAXQ]; // 每個查詢中最多數字的個數
struct QUERY{
  int qL,qR,qID,qK;
  bool operator<(const QUERY &rhs)const{ return(qK<rhs.qK) or (qK==rhs.qK and qR<rhs.qR); }
} query[MAXQ];

inline void add(int x){
  show[cnt[x]++]--; // 原本的數量-1
  show[ cnt[x] ]++; // 更新後數量+1
  if(show[ cnt[x] ]==1) ans_now=max(ans_now,cnt[x]); // 某個數量從0變成1，代表最多個數的答案需要更新
}
inline void sub(int x){
  show[cnt[x]--]--; // 更新後數量+1
  show[ cnt[x] ]++; // 原本的數量-1
  if(show[cnt[x]+1]==0 and ans_now==cnt[x]+1) // 因為移除了這個數字後導致代表最多個數的答案需要更新
     ans_now=cnt[x];
}
int main(){
  int N, Q, K;
  scanf("%d",&N);
  scanf("%d",&Q);
  for(int i=1;i<=N;i++)
    scanf("%d",&num[i]);
  K=sqrt(N);
  for(int i=0;i<Q;i++)
    scanf("%d",&query[i].qL),
    scanf("%d",&query[i].qR),
    query[i].qID=i,
    query[i].qK=query[i].qL/K;
  // Mo's algorithm：先根據同個區間排序，再依據右端點由小到大(教學文件中提到加速方式：可以依據奇偶性交替)
  sort(query,query+Q);
  // 初始化：每個數字的出現數字都是0
  show[0]=N;
  memset(cnt,0,sizeof(cnt));
  int nowL=0, nowR=0;
  for(int i=0;i<Q;i++){
    while(nowL<query[i].qL) sub(num[nowL++]);
    while(nowL>query[i].qL) add(num[--nowL]);
    while(nowR>query[i].qR) sub(num[nowR--]);
    while(nowR<query[i].qR) add(num[++nowR]);
    ansc[ query[i].qID ]=ans_now;
    ansn[ query[i].qID ]=show[ans_now];
  }
  // 輸出
  for(int i=0;i<Q;i++)
    printf("%d %d\n",ansc[i],ansn[i]);
}
/*
10 10
2 3 1 1 1 2 1 2 1 1
5 8
1 10
6 9
5 9
1 5
3 10
1 9
1 1
6 9
2 3
*/