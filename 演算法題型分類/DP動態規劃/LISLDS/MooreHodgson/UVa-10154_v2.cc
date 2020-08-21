// 中文題意網址：http://luckycat.kshs.kh.edu.tw/homework/q10154.htm
/* 經典問題：烏龜塔，題目可以轉換成單機排成問題。
 * 參考演算筆記的 Non-Squashing Stack of Boxes
 * N個工作要完成　　　　  <---> N個箱子要疊
 * 工作的處理時間　　　　 <---> 箱子的內容物重量
 * 工作的完工期限　　　　 <---> 箱子的抗壓力量＋箱子的內容物重量
 * 如期完工的工作越多越好 <---> 箱子疊越多越好
 * 作法： O(NlogN+NL)
 * (2) 依照『承受能力』由『大到小』排序。依序疊紙箱，由下往上疊，求出LIS。
 * 由上往下疊紙箱的過程當中，需要不斷的更新紙箱的抗壓力量，如果發現一個更好的疊法，
 * 就要更新抗壓力量，並且讓抗壓力量越大越好，如此一來上方就可以更容易添上紙箱。
 * 添上紙箱的條件，是該下方紙箱都能夠承受該紙箱的重量，才能添上紙箱。
 */

#include<bits/stdc++.h>
using namespace std;

const int INF=0x7f7f7f7f;
const int MAXN=5610;
int DP[MAXN];
struct TURTLE{
  int w, p;
  bool operator<(const TURTLE &rhs)const{ return p>rhs.p; }
}turtle[MAXN];

int main(){
  int N, L;
  for(N=1;scanf("%d %d",&turtle[N].w,&turtle[N].p)==2;N++)
    turtle[N].p-=turtle[N].w;
  // 依據負重能力排序，若相同則依據自身重量
  sort(turtle+1,turtle+N+1);

  // 動態規劃以DP[j]＝第j層(由下往上數)紙箱的負重能力來思考，目標是最大化這個數值

  DP[0]=INF; // 地面的抗壓能力無限大
  int nowL=0;// 紀錄目前可以更新的位置
  for(int i=1;i<=N;i++){
    if(DP[nowL]>=turtle[i].w) nowL++;
    for(int j=nowL;j;j--)// 由下往上更新
      if(DP[j-1]>=turtle[i].w)// 視情況更新紙箱的承受力量
        DP[j]=max(DP[j],
                  min(DP[j-1]-turtle[i].w,turtle[i].p) ); // 這層紙箱的負重能力
  }
  printf("%d\n",nowL-1); // 最頂層不放東西所以減一
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