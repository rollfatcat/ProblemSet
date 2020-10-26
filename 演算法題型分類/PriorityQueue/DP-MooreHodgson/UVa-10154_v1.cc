// 中文題意網址：http://luckycat.kshs.kh.edu.tw/homework/q10154.htm
/* 經典問題：烏龜塔(紙箱堆疊)，題目可以轉換成單機排成問題。
 * 參考演算筆記的 Non-Squashing Stack of Boxes
 * N個工作要完成　　　　  <---> N個箱子要疊
 * 工作的處理時間　　　　 <---> 箱子的內容物重量
 * 工作的完工期限　　　　 <---> 箱子的抗壓力量＋箱子的內容物重量
 * 如期完工的工作越多越好 <---> 箱子疊越多越好
 * 作法： O(NlogN+NL)
 * (1)依照『承重能力』由『小到大』排序，依序疊紙箱，由上往下疊，求出LIS
 * 由上往下疊紙箱的過程當中，需要不斷的累計紙箱的總重量，
 * 如果發現一個更好的疊法，就要更新總重量，並且讓總重量越小越好，如此一來下方就可以更容易添上紙箱。
 * 添上紙箱的條件，是該紙箱能夠承受上方全部紙箱的總重量，才能添上紙箱。
 */

#include<bits/stdc++.h>
using namespace std;

const int INF=0x7f7f7f7f;
const int MAXN=5610;
int DP[MAXN];
struct TURTLE{
  int w, p; //原題目給的Ｐ代表烏龜的力量，而我讀取時會扣除自身重量代表負重能力
  bool operator<(const TURTLE &rhs)const{ return (p==rhs.p)?(w<rhs.w):(p<rhs.p); }
}turtle[MAXN];

int main(){
  int N, L;
  for(N=1;scanf("%d %d",&turtle[N].w,&turtle[N].p)==2;N++);
    turtle[N].p-=turtle[N].w;
  // 依據負重能力排序，若相同則依據自身重量
  sort(turtle+1,turtle+N+1);

  // 動態規劃：DP[i][j]＝min( DP[i-1][j], DP[i][j-1]+Ｗi ), dp[i][j-1]≤Ｐi
  // 下面只用一維陣列實現算法，DP[j]紀錄第j層時最佳的烏龜總重量

  // 初始化時因為烏龜從1號開始算，所以DP[0]代表沒有烏龜重量＝0，其餘給最大值
  memset(DP,0x7f,sizeof(DP)), DP[0]=0;
  // 紀錄目前可以更新的位置
  int nowL=0;
  for(int i=1;i<=N;i++){
    if(DP[nowL]<=turtle[i].w) nowL++;
    for(int j=nowL;j;j--)// 由上往下更新
      if(DP[j-1]<=turtle[i].p)// 現在的烏龜可以負擔上層所有烏龜的重量總和
        DP[j]=min(DP[j],DP[j-1]+turtle[i].w);
  }
  printf("%d\n",nowL);
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