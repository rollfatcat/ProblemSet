// 題解：巴斯卡三角數列+快速幕次加速計算取模：https://home.gamer.com.tw/creationDetail.php?sn=4082950
/* 觀察 N=3 的方法，可以發現其架構等同於以下：
 * 從 1~2 取0個數放到3的後面( 123 )+ 1~2 取1個數放到3的後面( 231 及 132 )+ 1~2 取2放到3後面( 321 )
 * 也就是總方法數為 C2取0 + C2取1 + C2取2 = 4 = 2^2。
 */
#include<iostream>
using namespace std;
#define MOD 1234567

bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){

  for(int N; scanInt(N);){
    if(N==0){ printf("0\n"); continue; }
    N--;
    long base=2, num=(N&1)?2:1;
    for(N/=2; N>0; N/=2){
      base=base*base%MOD;
      if(N&1)
        num=base*num%MOD;
    }
    printf("%ld\n",num);
  }
}