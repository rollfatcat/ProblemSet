// 多重背包問題
// 題目同 TIOJ-1387

#include<bits/stdc++.h>
using namespace std;
#define INF 1<<30

const int MAXT=1e6;
const int MAXN=1e5;
const int MAXW=1e3;
struct NN{ int wgt,val; };
struct ITEM{
  int wgt,val,cnt;
}item[MAXN];
vector<int> DP(MAXT+1,-INF); // 假設每個物品都是最高CP值 (w,v)=(1,1e3)取1e5個

int main(){
  int N, W;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d",&item[i].wgt),
    scanf("%d",&item[i].val),
    scanf("%d",&item[i].cnt);
  scanf("%d",&W);
  deque<NN> DQ[MAXW+1];
  DP[0]=0;
  for(int i=0;i<N;i++){
    // 初始化 DoubleQueue
    for(int now_w=0;now_w<item[i].wgt;now_w++)
      DQ[now_w].clear(),
      DQ[now_w].push_back( (NN){now_w,DP[now_w]} );
    //
    for(int now_w=item[i].wgt;now_w<=W;now_w++){
      int rem=now_w%item[i].wgt;
      while(DQ[rem].empty()==0 and DQ[rem].front().wgt<now_w-item[i].wgt*item[i].cnt )
        DQ[rem].pop_front();

      int now_v=DQ[rem].front().val+(now_w-DQ[rem].front().wgt)/item[i].wgt*item[i].val;
      while(DQ[rem].empty()==0 and DQ[rem].back().val+( now_w-DQ[rem].back().wgt )/item[i].wgt*item[i].val<=DP[now_w])
        DQ[rem].pop_back();

      DQ[rem].push_back( (NN){now_w,DP[now_w]} );
      DP[now_w]=max(DP[now_w],now_v);

    }
  }
  int ans=0;
  for(int now_w=1;now_w<=W;now_w++)
    ans=max(ans,DP[now_w]);
  printf("%d\n",ans);

}