// 判斷二為平面上三點共線：取兩點算斜率，斜率一樣即共線(兩條線都共同通過一個點)
// 斜率做除法 => 相乘後判斷相等
#include<bits/stdc++.h>
using namespace std;

inline void scanInt(int &x){
  char c=getchar();
  bool sign=c=='-';
  for(x=(sign)?0:c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
}
inline bool judge(int dx1,int dy1,int dx2,int dy2){
  return (dx1*dy2)==(dx2*dy1);
}
int main(){
  int N, x[3], y[3];
  scanInt(N);
  while(N--)
    scanInt(x[0]),
    scanInt(y[0]),
    scanInt(x[1]),
    scanInt(y[1]),
    scanInt(x[2]),
    scanInt(y[2]),
    puts( judge(x[1]-x[0],y[1]-y[0],x[2]-x[0],y[2]-y[0])?"collinear":"not collinear");
}