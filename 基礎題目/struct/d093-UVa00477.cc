// 練習 strcut 使用，判斷點是不是落在圖形(圓形或矩形)
#include<bits/stdc++.h>
using namespace std;

inline double SQU(double x){ return x*x; }
struct OBJC{
  double cx, cy, r;
  bool IsIn(double px,double py){ return SQU(r)>=SQU(cx-px)+SQU(cy-py); }
} circle[11];
struct OBJR{
  double lx,ly,rx,ry; // 左上＋右下
  bool IsIn(double px,double py){ return lx<=px and px<=rx and ry<=py and py<=ly; }
} rectangle[11];
int main(){
  int num=0, table[11];
  for(char ch; scanf("%c",&ch) and ch!='*';getchar())
    if(ch=='r')
      table[++num]=10+num,
      scanf("%lf",&rectangle[num].lx),
      scanf("%lf",&rectangle[num].ly),
      scanf("%lf",&rectangle[num].rx),
      scanf("%lf",&rectangle[num].ry);
    else// (ch=='c')
      table[++num]=num,
      scanf("%lf",&circle[num].cx),
      scanf("%lf",&circle[num].cy),
      scanf("%lf",&circle[num].r);

  double x, y;
  for(int id=1;scanf("%lf%lf",&x,&y)==2;id++){
    if(x==9999.9 and y==9999.9) break;
    bool NoFig=true;
    for(int i=1;i<=num;i++)
      if(table[i]>=10){ // rectangle
        if(rectangle[ table[i]-10 ].IsIn(x,y))
          NoFig=false,
          printf("Point %d is contained in figure %d\n",id,table[i]-10);
      }
      else{ // circle
        if(circle[ table[i] ].IsIn(x,y))
          NoFig=false,
          printf("Point %d is contained in figure %d\n",id,table[i]);
      }
    if(NoFig)
      printf("Point %d is not contained in any figure\n",id);
  }
}
/*
r 8.5 17.0 25.5 -8.5
c 20.2 7.3 5.8
r 0.0 10.3 5.5 0.0
c -5.0 -5.0 3.7
r 2.5 12.5 12.5 2.5
c 5.0 15.0 7.2
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
9999.9 9999.9
*/
