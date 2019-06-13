// 題目相同：ZJ-835，觀察測資的輸入數量高達1e6個應該是Greedy可解
/* 這是包裝成01背包問題的Greedy
 * 對於重量2^k時，我們把價值最大的兩個合在一起湊出重量2^(k+1)的物品，
 * 一直做到重量2^k的剩下一個或零個。如果剩一個我們再考慮加入一個重量2^k價值為0的物品，
 * 讓剩的那個也可以合上去，這樣直接看重量2^M中，價值最大的那個物品就好。
 * 因為可以證明在每個重量最多加入一個價值為0的東西時，用最優解選完選到一些價值為0的東西並不會影響答案
 * 下述是原始的作法( 0.7s/65.2MB )，可以參考 ZJ-835 的三種版本
 * ( 0.3s/11.3MB ) PriorityQueue 版本
 * ( 0.3s/ 8.8MB ) Queue＋mergeSort合併版本
 * ( 0.8s/26.5MB ) vector＋sort 版本
 */

#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000001;
int N, W, tot=0;
int node[MAXN];
struct ITEM{ int w, v; }items[MAXN];
vector<long> bucket[MAXN], Q[2];

bool compare(long a,long b){ return a>b; }
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  // tot是重量小於等於W的物品才會納入選取的考慮範圍
  scanInt(N),
  scanInt(W);
  for(int i=0;i<N;i++){
    scanInt(items[tot].w),
    scanInt(items[tot].v),
    node[tot]=items[tot].w;
    if(items[tot].w<=W)
      tot++;
  }
  N=tot;

  // 離散化有效的重量
  sort(node,node+tot);
  node[tot++]=W;
  tot=unique(node,node+tot)-node;
  // 把對應重量的物品價值丟到對應的 vector 中(此時未由大到小排序)
  for(int pos,i=0;i<N;i++)
    pos=lower_bound(node,node+tot,items[i].w)-node,
    bucket[pos].push_back(items[i].v);

  /* (1) 排序這個 bucket[] 裡面的價值(大到小)
   * (2) 因為是第一次另一個vector是空的就直接以 buff 個為單位Merge後丟到現在的vector
   */
  sort(bucket[0].begin(),bucket[0].end(),compare);
  int unit=0, buff=node[1]-node[0];
  buff=(buff<20)?(1<<buff):MAXN;
  for(int i=0;i<bucket[0].size();i++,unit=(unit+1)%buff){
    if(unit)Q[0].back()+=bucket[0][i];
    else    Q[0].push_back(bucket[0][i]);
  }
  for(int nowB=1;nowB<tot-1;nowB++){
    // MergeVectorBucket
    // 排序這個 bucket[] 裡面的價值(大到小)
    sort(bucket[nowB].begin(),bucket[nowB].end(),compare);
    // 計算需要『2^buff』個Merge在一起( 1<<20 = 1048576 超過N的上限 )
    int buff=node[nowB+1]-node[nowB];
    buff=(buff<20)?(1<<buff):MAXN;

    /* 模仿MergeSort的合併方式：合併 Q[preQ] 和 bucket[nowB]
     * 注意：一樣是以 buff 為一組單位Merge後才推到 Q[nowQ] 內
     */
    int nowQ=nowB&1, preQ=nowQ^1;
    int i=0, j=0, unit=0;
    Q[nowQ].clear();
    for(; i<bucket[nowB].size() and j<Q[preQ].size(); unit=(unit+1)%buff){
      long tmpv=(bucket[nowB][i]>Q[preQ][j])?bucket[nowB][i++]:Q[preQ][j++];
      if(unit)Q[nowQ].back()+=tmpv;
      else    Q[nowQ].push_back(tmpv);
    }
    for(; i<bucket[nowB].size(); unit=(unit+1)%buff){
      if(unit)Q[nowQ].back()+=bucket[nowB][i++];
      else    Q[nowQ].push_back(bucket[nowB][i++]);
    }
    for(; j<Q[preQ].size(); unit=(unit+1)%buff){
      if(unit)Q[nowQ].back()+=Q[preQ][j++];
      else    Q[nowQ].push_back(Q[preQ][j++]);
      unit=(unit+1)%buff;
    }
  }
  // 從重量＝背包上限的 bucket[] 和 Q[] 裡面找出最大的價值即可
  long ans=0;
  for(auto x:Q[tot&1])
    ans=max(ans,x);
  for(auto x:bucket[tot-1])
    ans=max(ans,x);
  printf("%ld\n",ans);
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