/* 在解這一題時，相信很多人都觀察出紙張的切割方法只有2x2或1x4
 * 但注意在切割時，切割後的四個相同正方形邊長可以是非整數
 *   3
 * 1 4
 * 2 6
 * 2 7
 */
#include<iostream>
using namespace std;
#define esp 1e-8

double MinL(double w,double h){
  double tmp;
  // 固定w是長邊, h是短邊
  if(w<h) tmp=h, h=w, w=tmp;
  // 嘗試三種情況：(1)現在形狀切成2x2 (2)現在形狀切成1x4 (3)現在形狀切半拼到下面，形成2h x w/2
  return max(h/2.0,max(min(h,w/4.0),min(h,w/2.0)/2.0));
}
int main(){
  for(int cnt; scanf("%d",&cnt) and cnt; ){
    int maxI=1;
    double maxL, L, w, h;

    scanf("%lf %lf",&w,&h);
    maxL=MinL(w,h);
    for(int i=2;i<=cnt;i++){
      scanf("%lf %lf",&w,&h);
      L=MinL(w,h);
      if(L>maxL)
        maxI=i, maxL=L;
    }
    printf("%d\n",maxI);
  }
}