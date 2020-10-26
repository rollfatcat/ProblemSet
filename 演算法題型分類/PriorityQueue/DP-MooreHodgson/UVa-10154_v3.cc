// 中文題意網址：http://luckycat.kshs.kh.edu.tw/homework/q10154.htm
/* 經典問題：烏龜塔，經典算法解：Moore-Hodgson’s Algorithm。
 * 參考演算筆記的 Non-Squashing Stack of Boxes
 * N個工作要完成　　　　  <---> N個烏龜要疊
 * 工作的處理時間　　　　 <---> 烏龜的重量
 * 工作的完工期限　　　　 <---> 烏龜的力量
 * 如期完工的工作越多越好 <---> 烏龜疊越多越好
 * 作法： O(NlogN)
 * (1) 先依照力量將烏龜排序
 * (2) 遍歷烏龜們，將 turtle[i].w 加入到 priority queue 中
 * (3) 將目前 sumw 加上 turtle[i].w
 * (4) 檢查此烏龜是否可以負荷上層與本身的重量 ( sumw 是否大於 turtle[i].p )
 * (5) 若超重，則從 priority queue 中去除最大者，將 sumw 扣掉他。
 * (6) 重複步驟 2，直到遍歷完烏龜們
 * (7) 輸出 : 最後在 T 中尋找到最大的 k 值且 T[k] 是合法狀態，k 即為最大層數
 */

#include<bits/stdc++.h>
using namespace std;

const int INF=0x7f7f7f7f;
const int MAXN=5610;
int DP[MAXN];
struct TURTLE{
  int w, p;
  bool operator<(const TURTLE &rhs)const{ return (p==rhs.p)?(w<rhs.w):(p<rhs.p); }
}turtle[MAXN];

int main(){
  int N, L;
  for(N=1;scanf("%d %d",&turtle[N].w,&turtle[N].p)==2;N++);

  sort(turtle,turtle+N);
  priority_queue<int> PQ;
  for(int sumw=0,i=1;i<=N;i++){
    PQ.push(turtle[i].w);
    sumw+=turtle[i].w;
    if(sumw>turtle[i].p)
      sumw-=PQ.top(),
      PQ.pop();
  }
  printf("%lu\n",PQ.size());
}
/*
300 1000
1000 1200
200 600
100 101

20 20
20 40
10 60
140 150
*/