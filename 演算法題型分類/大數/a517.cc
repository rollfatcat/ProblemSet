// 特殊題: 乍看之下是需要做大數開根號但題目【額外】給了邊長之間的一些條件
/* 不可能是大數開根號且無法用 __uint128存儲資料(計算時是3個平方相加)
 * 討論區有由答案反推的公式
 * 設 a是最短邊，b-a=x^2，c-a=y^2 (x,y 屬於正整數or零)
 * (a^2+b^2+c^2)^0.5 = b+c-a
 * a^2+b^2+c^2 = (b+c-a)^2
 * b*c-a*c-a*b = 0
 * (x^2+a)(y^2+a) = a*(x^2+a) + a*(y^2+a)
 * x^2*y^2=a^2
 * a = x*y  -> 題目給的第三個條件式
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
  unsigned long L[3], minL;
  while(scanf("%lu %lu %lu",&L[0],&L[1],&L[2])!=EOF)
    sort(L,L+3),
    printf("%lu\n",L[2]-L[0]+L[1]);
}