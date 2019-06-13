// Floyed-Warshall的經典題(All Pairs Shortest Path)＋離線處理
// Node 數量不多約500個，處理任意兩個Node間的多條連線時只要保留cost最低的即可(2D array處理)
// 看完題目後可以發現問題點出在於 Query 數量高達 200000，可以把每次讀取暴動的攻擊力而做Dijkstra方法排除
/* 關鍵：因為暴動的攻擊力會決定能不能經過某個機場而更新最短路徑 => 排序所有機場的防禦力和暴動的攻擊力
 * 由最高攻擊力的Query開始往下更新，能夠承受這次攻擊力的機場時就嘗試去看看能不能經過該機場去更新最短路徑 => Floyed-Warshall
 * 問題從 200000次的單次 Dijkstr 轉換為一次的 Floyed-Warshall
 * 注意更新在暴動v的情況下機場a到機場b的最短時間成本，除了最短路徑存在之外，機場a和機場b也得都是開啟的狀態
 */
// (X)離散化：只有當暴動的攻擊力大於機場的防禦力時點才會癱瘓，換句話說有意義的數值是由機場的防禦力切開的區段，成本是攻擊力做查詢是O(㏒N)
// 沒做離散化時也不影響更新順序，只是多一些無意義判斷而已。 93ms(離散化) vs. 85ms(無意義判斷)

#include<bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f; //更新邊的值會相加，避免overflow所以上限設定的值改為此
const int maxN=505;
int N, M, Q;
int cost[maxN][maxN], minCost[200000];
struct one_city{
  int no, DEF;
  bool operator<(const one_city &other)const{ return DEF<other.DEF; }
} city[maxN];
struct one_query{ //紀錄號碼，映射回原本的順序
  int no, st, ed, ATK;
} query[200000];
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
bool compare_by_ATK(one_query a,one_query b){ return a.ATK<b.ATK; }
int main(){
  int a, b, v;

  scanInt(N),
  scanInt(M),
  scanInt(Q);
  // 讀取各機場的防禦力
  city[0].no=0, city[0].DEF=INF; // city[0]存值是無限大 當作二分法時的右極限值
  for(int i=1;i<=N;i++)
    scanInt(city[i].DEF), city[i].no=i;
  sort(city,city+N+1);
  // 讀取任意機場之間的時間成本，且取最小值
  memset(cost,0x3f,sizeof(cost));
  for(int i=0;i<M;i++){
    scanInt(a), scanInt(b), scanInt(v);
    if(cost[a][b]>v)
      cost[a][b]=cost[b][a]=v;
  }
  // 讀取暴動的攻擊力和起點/終點，並且把攻擊力離散化
  for(int i=0;i<Q;i++)
    query[i].no=i,
    scanInt(query[i].ATK),
    scanInt(query[i].st),
    scanInt(query[i].ed);
  sort(query,query+Q,compare_by_ATK);

  memset(minCost,0xff,sizeof(minCost));
  vector<bool> on(N+1,0);
  for(int now_ATK=INF, update_city=N-1, q=Q-1; q>=0; q--){
    if(query[q].ATK!=now_ATK){
      now_ATK=query[q].ATK;
      // Floyed Warshall
      for(;update_city>=0 and city[update_city].DEF>=now_ATK; update_city--){
        int now_city=city[update_city].no;
        on[now_city]=true;
        for(int u=1;u<=N;u++)
          for(int v=u+1;v<=N;v++){ //更新(u,v)時也一併更新(v,u)
            int tmpCost=cost[u][now_city]+cost[now_city][v];
            if(cost[u][v]>tmpCost)
              cost[u][v]=cost[v][u]=tmpCost;
          }
      }
    }
    // 『只有當端點的機場都是開啟時』且有最短路徑存在時才紀錄該路徑存在
    if(on[query[q].st] and on[query[q].ed] and cost[query[q].st][query[q].ed]!=INF)
      minCost[query[q].no]=cost[query[q].st][query[q].ed];
  }
  for(int i=0;i<Q;i++)
    printf("%d\n",minCost[i]);
}
/*
6 5 5
5 4 1 3 2 6
1 3 3
1 4 1
2 4 6
2 5 1
3 5 2
1 1 2
2 1 2
3 1 2
4 1 2
1 5 3
*/