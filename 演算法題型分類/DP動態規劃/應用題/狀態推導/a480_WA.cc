/* (60%) 直覺作法
 * 每次讀取一個城市座標時，就把該城市分配給離他最近的防衛塔
 * 觀察測資可以發現最後一座城市可以交給兩座防衛塔時，應該要避免擴大防衛塔的範圍
 * 所以得根據哪座塔現有的防衛距離大更新他就好。
 * (100%) 動態規劃
 */
#include<bits/stdc++.h>
using namespace std;

inline int DIS(int x,int y){ return x*x+y*y; }
int main(){
  int x1, y1, r1, d1;
  int x2, y2, r2, d2;
  int N, x, y, rec;

  scanf("%d %d",&x1,&y1);
  scanf("%d %d",&x2,&y2);
  scanf("%d",&N);
  r1=r2=rec=0;
  while(N--){
    scanf("%d %d",&x,&y);
    d1=DIS(x-x1,y-y1),
    d2=DIS(x-x2,y-y2);
    if(d1>d2) r2=max(r2,d2);
    if(d1<d2) r1=max(r1,d1);
    if(d1==d2)rec=max(rec,d1);
  }
  if(r1<r2) swap(r1,r2);
  r1=max(r1,rec);
  printf("%d\n",r1+r2);
}
/*
0 0
0 2
4
0 3
1 -1
1 0
1 1
*/