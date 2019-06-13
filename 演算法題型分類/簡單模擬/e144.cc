// 物理題(角度轉換弧度，精確度判斷問題)
// 注意題目的惡意測資：-2 0.0 0 ，輸出時是 x: -0.00, y: -0.00  at 0(s) falling

#include<bits/stdc++.h>
using namespace std;

const double ESP=1e-6;
const double PI=acos(-1);
const double G=9.8;
int main(){
  int caseT, v0, degree, t;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d %d %d",&v0,&degree,&t);
    double x0=v0*cos(degree*PI/180.0);
    double y0=v0*sin(degree*PI/180.0);

    double x=x0*t;
    double y=y0*t-0.5*G*t*t;

    if(0.0>=x and x>-0.014-ESP) x=0.0;
    if(0.0>=y and y>-0.014-ESP) y=0.0;
    printf("x: %.2lf, y: %.2lf  at %d(s) ",x,y,t);

    y0-=G*t;
    if(y0>=ESP) puts("rising");
    else if(y0<=-ESP) puts("falling");
    else //(-ESP<=y0 and y0<=ESP)
      puts("rest");
  }
}