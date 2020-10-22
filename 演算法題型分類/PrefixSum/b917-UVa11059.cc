/* 給定Ｎ個數字(−10 ≤ Si ≤ 10)，輸出連續區間最大的乘積(找不到正數區間時輸出0)？
 * 解題關鍵：暴力法，枚舉區間的起點和結尾
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=18;
int num[MaxN];
int main(){

  int N;
  for(int caseI=1; scanf("%d\n",&N)!=EOF; caseI++){
    for(int i=0; i<N; i++)
      scanf("%d",&num[i]);
    long max_mul=0;
    for(int st=0; st<N; st++){
      long ths_mul=1;
      for(int ed=st; ed<N and num[ed]!=0; ed++){
        ths_mul*=num[ed];
        max_mul=max(max_mul,ths_mul);
      }
    }
    printf("Case #%d: The maximum product is %ld.\n\n",caseI,max_mul);
  }
}