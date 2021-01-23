/* 給定Ｎ瓣橘子和每個人至少分得Ｍ瓣橘子的限制，每次撥橘子時只能對半分，輸出最多能分到的人數？
 * 解題關鍵：遞迴＋位元運算
 * 題目盲區：為了達到 memorization 加速，但陣列的空間有限只能使用 map<long,long>。
 *         map 的操作都是Ｏ(㏒N)，所以整體無法達成加速。
 * 遞迴模擬橘子分半的過程，分半時可以透過 right-shift 計算。
 */

#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=1e6;
const long MaxN=1e15;
const long MaxM=1e15;
long N, M;
inline long DivideConquer(long x){
  if( M>(x>>1) ) return 1;
  return (x&1)? DivideConquer((x>>1)+1)+DivideConquer(x>>1): DivideConquer(x>>1)<<1;
}
int main(){
  while(scanf("%ld %ld",&N,&M)==2)
    printf("%ld\n", (N<M)? 0:DivideConquer(N) );
}