// 問題等同 c055-uva00568，但是輸入範圍是10^15
// 初步想法是有規律可循 => (v2)數論的規則解：https://home.gamer.com.tw/creationDetail.php?sn=4238935
/* N! = 1 x 2 x 3 x 4 x 5 x 6 x 7 x 8 x 9 x 10 …… x N
 * 因為 1x2x3x4=24 尾數為4，6x7x8x9=3024 尾數為4
 * 且以5個為一組時可以改寫會發現含有20的因數，20=2 x 10，問題可以被縮減為子問題
 * (1 x 2 x 3 x 4 x 5)x(6 x 7 x 8 x 9 x 10)x(11 x 12 x 13 x 14 x 15)x(16 x 17 x 18 x 19 x 20)
 * = 20 x 40 x 60 x 80 x.... = 2 x 10 x(1 x 2 x 3 x 4 x 5....)
 * 解法：ƒ(N)內包含(N/5)組，問題可以拆解成：ƒ(N)=2^(N/5) x ƒ(N/5) x 餘數的部分
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int digit[10]={1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
int cycle2[4]={6,2,4,8}; // 2->4->8->6 => 調整一下順序即可
/*
int lastNon0Digit(long n){
  if(n<10)  return digit[n];
  // Check whether tens (or second last) digit
  // is odd or even
  // If n = 375, So n/10 = 37 and (n/10)%10 = 7
  // Applying formula for even and odd cases.
  if (((n/10)%10)%2==0) return (6*lastNon0Digit(n/5)*dig[n%10])%10;
  return (4*lastNon0Digit(n/5)*dig[n%10])%10;
}
*/
// v2
int lastNon0Digit(long n){
  if(n<10)  return digit[n];
  long out=1, x=n/5, y=n%5;
  for(int i=0; i<y; i++)
    out*=(n-i)%10;
  return (out*cycle2[x%4]*lastNon0Digit(x) )%10;
}
int main(){
  for(int n; cin>>n; )
    for(long m; n--; )
      cin>>m, cout<<lastNon0Digit(m)<<endl;
}