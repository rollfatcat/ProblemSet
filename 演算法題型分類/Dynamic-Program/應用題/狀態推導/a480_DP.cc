/* (60%) 直覺作法
 * 每次讀取一個城市座標時，就把該城市分配給離他最近的防衛塔
 * 觀察測資可以發現最後一座城市可以交給兩座防衛塔時，應該要避免擴大防衛塔的範圍
 * 所以得根據哪座塔現有的防衛距離大更新他就好。
 * (100%) 動態規劃：枚舉 nowRr=rec[i].d1+max(D[i+k].d2), 1 ≤ k
 * 每座城市可以選擇要屬於第一座還是第二座保護塔的範圍
 * 邊界情況要特別處理：所有的城市都屬於第一座或是第二座保護塔的範圍
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
struct NODE{
  int d1, d2;
  bool operator<(const NODE &rhs)const{ 
    return (d1==rhs.d1)?(d2<rhs.d2):(d1>rhs.d1); }
}P1, P2, rec[MaxN];

inline int DIS(int x,int y){ return x*x+y*y; }
int main(){
  int N, x, y;

  scanf("%d %d",&P1.d1,&P1.d2),
  scanf("%d %d",&P2.d1,&P2.d2);
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d %d",&x,&y),
    rec[i].d1=DIS(x-P1.d1,y-P1.d2),
    rec[i].d2=DIS(x-P2.d1,y-P2.d2);
  sort(rec,rec+N);
  // 反向更新D2
  for(int i=1;i<N;i++)
    rec[i].d2=max(rec[i].d2,rec[i-1].d2);

  // sumRr 的初始值由極端情況決定
  // rec[ 0 ].d1=全部的城市都屬於第一座保護塔範圍
  // rec[N-1].d2=全部的城市都屬於第二座保護塔範圍
  int nowRr, sumRr=min(rec[0].d1,rec[N-1].d2);
  for(int i=N-1;i>0;i--)
    nowRr=rec[i].d1+rec[i-1].d2,
    sumRr=min(sumRr,nowRr);
  printf("%d\n",sumRr);
}