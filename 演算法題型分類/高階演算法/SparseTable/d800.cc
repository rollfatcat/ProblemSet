/* 題目等同 d798，但是Query的次數是前一題的10倍(1000000次)
 * 換句話說 Query的Cost必須從O(㏒N)再降低為O(1) => Sparse Table，問題是不能改動資訊
 * Sparse Table 演算筆記：http://www.csie.ntnu.edu.tw/~u91029/Sequence2.html
 * 博客詳解：https://blog.csdn.net/FlushHip/article/details/81079776
 */
#include<iostream>
#include<cmath>
using namespace std;
#define MaxN 501
#define hN 11

int ST[hN][MaxN][hN][MaxN];
inline bool scanInt(int &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  return c!=EOF;
}
void build(int n,int m){ //O(N*㏒N*M*㏒M)
  //先把每條垂直的建起來
  for(int i=1;i<=m;i++)
    for(int j=1;(1<<j)<=n;j++)
      for(int k=1;k+(1<<j)-1<=n;k++)
        ST[j][k][0][i]=max(ST[j-1][k][0][i],ST[j-1][k+(1<<(j-1))][0][i]);
  //沿著水平方向整合
  for(int i=0;(1<<i)<=n;i++)
    for(int j=1;j+(1<<i)-1<=n;j++)
      for(int k=1;(1<<k)<=m;k++)
        for(int q=1;q+(1<<k)-1<=m;q++)
          ST[i][j][k][q]=max(ST[i][j][k-1][q],ST[i][j][k-1][q+(1<<(k-1))]);
}
int query(int x1,int y1,int x2,int y2){//O(1)
  // __lg(N)：gcc內建函數，回傳最高位1的位置
  int hx=__lg(x2-x1+1), hy=__lg(y2-y1+1);
  return max(max(ST[hx][x1][hy][y1],          ST[hx][x2-(1<<hx)+1][hy][y1]),
             max(ST[hx][x1][hy][y2-(1<<hy)+1],ST[hx][x2-(1<<hx)+1][hy][y2-(1<<hy)+1]));
}
int main(){

  int x1,x2,y1,y2;
  for(int n,m,Q; scanInt(n);){
    scanInt(m);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        scanInt(ST[0][i][0][j]);
    build(n,m);
    for(scanInt(Q); Q--;)
      scanInt(x1),
      scanInt(y1),
      scanInt(x2),
      scanInt(y2),
      printf("%d\n",query(x1,y1,x2,y2));
  }
}