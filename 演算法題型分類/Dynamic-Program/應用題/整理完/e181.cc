/* 把錢袋分群(只能和相鄰的合併但沒有數量限制)，但是同一群的總金額不能超過 m
 * 以目前這袋的角度出發，決定要不要往左合併(直到整群的金額超過 m 就停止)
 * 計算的過程中找到最小的合併成本後記錄到陣列中
 * 分析：目標金額最多是100元，而每袋錢最少是1元，換句話說最多往左邊掃描100格做動態規劃，時間成本是 1e6
 */

#include<bits/stdc++.h>
using namespace std;
#define MAXN 10001

int target;
int org[MAXN];
int dpn[MAXN];

inline int pow2(int x){ return (target-x)*(target-x); }
int main(){
  int N;
  while(scanf("%d",&N)!=EOF){
    for(int i=1;i<=N;i++)
      scanf("%d",&org[i]);
    scanf("%d",&target);

    dpn[1]=pow2(org[1]);
    int sum_money=org[1];
    for(int i=2;i<=N;i++){
      sum_money+=org[i];

      int nowv=org[i];
      dpn[i]=pow2(nowv)+dpn[i-1];
      for(int j=i-1;j>0;j--){
        nowv+=org[j];
        if(nowv>target) break;
        dpn[i]=min(dpn[i],pow2(nowv)+dpn[j-1]);
      }
    }
    (sum_money>=dpn[N])? printf("%d\n",sum_money-dpn[N]): puts("QQ");
  }
}
/*
4
1 3 1 3
4
4
1 1 3 3
4
5
2 2 2 2 5
6
4
1 1 1 1
3
2
1 1
100

6
1 2 3 4 5 4
6
*/