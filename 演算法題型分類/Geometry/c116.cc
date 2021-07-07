// 給你不共線的三個點的座標，你的任務是算出通過這三個點的唯一圓的週長是多少。
// (1) 外心(三中垂線交點)：需要兩條方程式根據斜率找出中垂線...
// (2) 公式解：三角形外接圓半徑 R = abc/4S，a,b,c 為三角形三邊長，S 為三角形面積
#include<bits/stdc++.h>
using namespace std;

const double PI=3.141592653589793;
int main(){
  double x1, y1, x2, y2, x3, y3;
  while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)==6){
    // 由三點推出三邊長
    double a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)),
           b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)),
           c=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    // 海龍三角面積公式：一半的周長
    double s=(a+b+c)/2.0,
           area=sqrt(s*(s-a)*(s-b)*(s-c));
    // R=abc/4S
    printf("%.2lf\n",2.0*PI*a*b*c/4.0/area);
  }
}