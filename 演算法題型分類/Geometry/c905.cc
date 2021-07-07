// 高二數學，二維平面的圓和直線的數學問題
// 題解：https://home.gamer.com.tw/creationDetail.php?sn=4254624
#include<bits/stdc++.h>
using namespace std;

const double esp=1e-6;
int main(){
  int T;
  for(scanf("%d",&T); T--;){
    int Cx, Cy, Cr;
    int Lx1, Lx2, Ly1, Ly2;
    scanf("%d %d %d",&Cx,&Cy,&Cr);
    scanf("%d %d %d %d",&Lx1,&Ly1,&Lx2,&Ly2);
    // --- 直線的係數：mx+c=y, m=Δy/Δx ---
    // --- 直線方程式：mx-y+c=0 => Δy*x-Δx*y+C=0, (A,B,C)=(Δy,Δx,Δx*Ly1-Δy*Lx1)
    long A=Ly1-Ly2, B=Lx1-Lx2, C=B*Ly1-A*Lx1;
    // ---判斷相交---
    bool Is_Cross=(A*Cx-B*Cy+C)*(A*Cx-B*Cy+C)<=(A*A+B*B)*Cr*Cr;
    if(!Is_Cross) puts("No Intersect");
    // ---找交點並輸出---
    else{
      //
      double Lx, Ly,
             denominator=sqrt(A*A+B*B),
             distance=abs(A*Cx-B*Cy+C)/denominator,
             disL=sqrt(Cr*Cr-distance*distance);
      // --- (Lx,Ly)是圓心投影在直線上的點 ---
      // --- 但是求點的時候要先判斷圓心落在直線的左/右邊 ---
      if(A*Cx-B*Cy+C>=0)
        Lx=Cx-distance*A/denominator,
        Ly=Cy+distance*B/denominator;
      else
        Lx=Cx+distance*A/denominator,
        Ly=Cy-distance*B/denominator;
      // --- 直線切在圓上(只有一點) ---
      if(abs(distance-Cr)<=esp){ printf("%.5lf %.5lf %.5lf %.5lf\n",Lx,Ly,Lx,Ly); }
      else{
        double LCx1=Lx+disL*B/denominator,
               LCy1=Ly+disL*A/denominator,
               LCx2=Lx-disL*B/denominator,
               LCy2=Ly-disL*A/denominator;
        // --- 題目規定 x值小的先輸出 ---
        if(LCx2>=LCx1+esp) printf("%.5lf %.5lf %.5lf %.5lf\n",LCx1,LCy1,LCx2,LCy2);
        else printf("%.5lf %.5lf %.5lf %.5lf\n",LCx2,LCy2,LCx1,LCy1);
      }
    }
  }
}