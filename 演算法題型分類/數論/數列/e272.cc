/* 題目求：GCD(Fm,Fn)的最大公因數並保證『答案』落在 unsigned long long 範圍內
 * 觀察輾轉相除法的過程搭配『費波那契數列』的特性：
 * F(30) = 1xF(29)＋1xF(28) =  F(2)xF(29)＋ F(1)xF(28)
 *       = 2xF(28)＋1xF(27) =  F(3)xF(28)＋ F(2)xF(27)
 *       = 3xF(27)＋2xF(26) =  F(4)xF(27)＋ F(3)xF(26)
 *                ...       = F(11)xF(20)＋F(10)xF(19)
 * GCD(F(30),F(20)) = GCD(F(11)xF(20)＋F(10)xF(19),F(20)) = GCD(F(20),F(10))，因為F(19)和F(20)互質
 * 推廣：F(n) = F(n-m+1)xF(m)＋F(n-m)xF(m-1)
 * wiki 的定理推廣部分：
 * gcd(Fm,Fn)=F_gcd(m,n)
 * 任意連續三個費波那契數兩兩互質，亦即，對於每一個n，gcd(Fn,Fn+1) = gcd(Fn,Fn+2) = gcd(Fn+1,Fn+2) = 1
 */
#include<bits/stdc++.h>
using namespace std;

vector<unsigned long long> FIB={0,1,1}; // 0 1 1 2 3 5 8
int main(){
  for(int idx=2; FIB[idx-1]<=FIB[idx]; idx++)
    FIB.push_back(FIB[idx-1]+FIB[idx]);
  FIB.pop_back(); // FIB.size()=94
  int n, m;
  while(scanf("%d %d",&n,&m)==2)
    printf("%llu\n",FIB[__gcd(n,m)]);
}