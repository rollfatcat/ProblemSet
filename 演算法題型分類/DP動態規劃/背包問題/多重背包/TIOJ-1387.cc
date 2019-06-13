// 多重背包時間成本：O(VN), 背包最大容量V, N件物品
// 一般解法：將第Ｎ項物品數量『二進位化』將時間成本O(V㏒CN), C是第Ｎ件物品可取用數量
// 教學文件：https://www.zybuluo.com/RabbitHu/note/857837
/* 解法的核心思想：單調列隊，將原先的時間成本下降到O(VN) => 前提是物品的重量不能太大
 * 將背包的最大重量以 item[i].wgt 呈為一組循環(餘數相同時分在同一組)
 * 保持每組內的紀錄 item[i].cnt 個，且此時DQ[rem].front() 是最大值
 * j = k*wi+r, 0≤r≤wi−1
 * DP[i][j] = max{ DP[i−1][j]         , DP[i−1][j−wi]+pi            ,⋯, DP[i−1][j−ci*wi]    +ci*pi    }
            = max{ DP[i−1][k*wi+r]    , DP[i−1][(k−1)*wi+r]+pi      ,⋯, DP[i−1][(k−ci)*wi+r]+ci*pi    }
            = max{ DP[i−1][k*wi+r]−kpi, DP[i−1][(k−1)*wi+r]+(k−1)*pi,⋯, DP[i−1][(k−ci)*wi+r]−(k−ci)*pi}+k*pi
 * 隨著式子的轉移，我們發現每一個取值將不依賴相對位置，只跟自身的位置有關，那麼可以使用單調堆(monotone queue)運行
 * O(1)的 sliding windows 查找極值。最後，將相同餘數分堆處理，單調堆中最多存在O(c)個元素。
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define MAXM 1000001
#define INF 1<<30

struct DATA{ int rem, val; };
struct ITEM{
  int w, v, n;
}item[MAXN];
vector<int> DP(MAXM,-INF);

int main(){
  int N, W;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d",&item[i].w),
    scanf("%d",&item[i].v),
    scanf("%d",&item[i].n);
  scanf("%d",&W);

  DP[0]=0;
  deque<DATA> DQ[1001]; //同一件物品最多1000個(?)
  for(int i=0;i<N;i++){
    for(int now_w=0;now_w<=W;now_w++){
      if( now_w<item[i].w ){
        DQ[now_w].clear();
        DQ[now_w].push_back( {now_w,DP[now_w]} );
        continue;
      }
      // 只保留前 item[i].n 個DP的值做動態規劃時的狀態轉移，多的從前端拿走
      int rem=now_w%item[i].w;
      while(DQ[rem].front().rem+item[i].n*item[i].w<now_w)
        DQ[rem].pop_front();
      // DQ[rem].front()紀錄的是最大值
      int now_v=DQ[rem].front().val+( now_w-DQ[rem].front().rem )/item[i].w*item[i].v;
      // 從尾端開始pop，注意pop時的條件是以舊的紀錄為主
      while(DQ[rem].empty()==0 and DQ[rem].back().val+( now_w-DQ[rem].back().rem )/item[i].w*item[i].v<=DP[now_w])
        DQ[rem].pop_back();
      // 注意：更新DP前先將『舊的紀錄』推入DQ才更新 !!
      DQ[rem].push_back( {now_w,DP[now_w]} );
      DP[now_w]=max(DP[now_w],now_v);
    }

  }
  int ans=-INF;
  for(int i=0; i<=W; i++)
    ans=max(ans,DP[i]);
  printf("%d\n",ans);
}
/*
3
2 1 2
3 4 1
4 3 1
6
*/