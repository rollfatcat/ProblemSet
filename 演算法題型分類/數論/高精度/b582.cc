// 題目要曼哈頓距離實際就是求下面的問題：注意點數是偶數時會有小數點問題
// 數論：高一數學 y=｜x-1｜+｜x-2｜+｜x-3｜+｜x-4｜求極小值
// 實作時要避開小數點問題有兩種做法(1)計算時單位是double 但輸出要改回來long (2)數值都10倍化
// 不用怕精確度問題：最糟糕是 xxx.5 但是二進位時其實只用小數點後的一個位數而已
#include<iostream>
#include<algorithm>
using namespace std;
#define MaxN 1000000

inline void scanInt(int &x){
  char c;
  while((c=getchar())==' ');
  bool sign=c=='-';
  for(x=sign?0:c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
}
int main(){
  int t, n;
  int x[MaxN], y[MaxN];

  for(scanInt(t); t--; ){
    scanInt(n);
    for(int i=0;i<n;i++)
      scanInt(x[i]),
      scanInt(y[i]);
    sort(x,x+n),
    sort(y,y+n);
    // 中位數可能是  xxx.5
    int pos=n>>1;
    double tx=(n&1)? x[pos]:( (x[pos-1]+x[pos])/2.0 ),
           ty=(n&1)? y[pos]:( (y[pos-1]+y[pos])/2.0 );
    double dis=0.0;
    for(int i=0;i<n;i++)
      dis+=abs(x[i]-tx)+abs(y[i]-ty);
    printf("%ld\n",(long)dis);
  }
}