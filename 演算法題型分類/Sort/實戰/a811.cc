/* 給定Ｔ筆測資和Ｎ個數字形成的數列，最大化數列中可能的公因數？
 * 排序後取相鄰項相減可以消除"雜訊"保留下的數字取最大公因數即可，過程中最大公因數變成１時可以提早結束。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxQ=1e2;
const int MaxN=1e4;
const long MaxV=1<<60;
long num[MaxN];
int main(){
  
  int Q, N;
  scanf("%d\n",&Q);
  while(Q-->0){
    scanf("%d\n",&N);
    for(int i=0;i<N;i++)
      scanf("%ld",&num[i]);
    sort(num,num+N);
    
    long ans=num[1]-num[0];
    for(int i=2;i<N and ans>1;i++)
      ans=__gcd(ans,num[i]-num[i-1]);
    printf("%ld\n",ans);
  }
}