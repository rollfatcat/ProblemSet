// 解二元一次方程式，根據係數討論無限解/無解/唯一解
#include<bits/stdc++.h>
using namespace std;

// ax+by=c
// dx+ey=f
int main(){
  int a, b, c, d, e, f;
  scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
  // 內建最大公因數
  int x1=__gcd(__gcd(a,b),c), x2=__gcd(__gcd(d,e),f);
  // 注意除以最大公因數時，公因數必須大於0
  if(x1) a/=x1, b/=x1, c/=x1;
  if(x2) d/=x2, e/=x2, f/=x2;
  if((long)a*e==(long)b*d)
    puts( ((long)a*f==(long)c*d)?"Too many":"No answer");
  else{
    double x=(double)(c*e-f*b)/(a*e-d*b),
           y=(double)(c*d-f*a)/(b*d-a*e);
    printf("x=%.2lf\ny=%.2lf\n",x,y);
  }
}