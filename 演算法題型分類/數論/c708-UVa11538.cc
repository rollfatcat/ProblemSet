// 用算的且(Q1,Q2)位置交換有效
#include<iostream>
using namespace std;

int main(){
  for(long R,C;scanf("%lu %lu",&R,&C)!=EOF and R;){
    if(R>C) R^=C^=R^=C;
    long ans=R*C*(R+C-2);// 直線＋橫線
     // 對角線：1*2+2*3+3*4+...+(R-1)*(R-2) + (C-R+1)*R*(R-1)
     // 1*2+2*3+3*4+...+(R-1)*(R-2) = (2*2-2)+(3*3-3)+(4*4-4)+...+(R-1)*(R-1)-(R-1)
     // = 4*( (R-1)*R*(2*R-1)/6 - (R-1)*R/2 )
    ans+=2*(2*R*(R-1)*(R-2)/3+R*(R-1)*(C-R+1));
    printf("%lu\n",ans);
  }
}