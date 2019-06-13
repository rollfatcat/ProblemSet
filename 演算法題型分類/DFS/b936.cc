/* Recursive version(1.7s)
 * 測資的輸入量高達1e6個，每筆測資最大是1e15，遞迴㏒(1e15)=50
 * 實際測試結果不能用cin/cout加速讀取 且 必須採用位元運算最後一筆才不會吃TLE
 * 函數內的判斷式不能超過2個(因為測資數量過大)
 * 核心就只是基本遞迴，花時間在這題加速沒有意義
 */

#include<bits/stdc++.h>
using namespace std;

long N, M;
inline long CDQ(long x){
  if( M>(x>>1) ) return 1;
  return (x&1)? CDQ(x+1>>1)+CDQ(x-1>>1): CDQ(x>>1)<<1;
}
inline bool scanLong(long &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); return c!=EOF;}
int main(){
  while(scanf("%ld %ld",&N,&M)==2)
    (N<M)? puts("0"): printf("%ld\n",CDQ(N));

}