// 題目要算出構成三角形的任兩點間連線「剛好」可以和方格的整數座標形成焦點的個數
/* 而我們可以觀察出從 A 到 B 的邊上（或是其他條邊），
 * 經過的格子點數目跟「A、B 的 x 座標差」(以下稱dx)和「A、B的 y 座標差」(以下稱dy)的最大公因數有關。
 * 若 dx、dy互質，那麼這條線上只會包含 A、B 兩個格子點，其原由為 dx、dy 沒有共同的因數可以讓其他線上的點的座標為整數（因為互質）。
 * 若 dx、dy不互質，取兩者的最大公因數 GCD，並將兩數除以便可得到互質的情況。
 * 而原本的線就只是互質的線延長數倍的結果。因為延長了 GCD 倍，所以總共經過 GCD+1 個格子點（可以看作有 GCD 條互質的線首尾相連）。
 * 但是如果 dx、dy有一數為零，則經過的格子點即是另一數+1 。
 */
#include<bits/stdc++.h>
using namespace std;

inline int NodeCount(int dx,int dy){
  if(dx<0) dx=-dx;
  if(dy<0) dy=-dy;
  if(dx==0) return dy+1;
  if(dy==0) return dx+1;
  return __gcd(dx,dy)+1;
}

int main(){
  int Ax, Ay, Bx, By, Cx, Cy;
  while(scanf("%d %d %d %d %d %d",&Ax,&Ay,&Bx,&By,&Cx,&Cy)!=EOF){
    if(Ax==0 and Ay==0 and Bx==0 and By==0) // 因為題目保證給的三點一定可以構成三角形
      break;
    printf("%d\n",NodeCount(Ax-Bx,Ay-By)+NodeCount(Ax-Cx,Ay-Cy)+NodeCount(Bx-Cx,By-Cy)-3);
  }
}