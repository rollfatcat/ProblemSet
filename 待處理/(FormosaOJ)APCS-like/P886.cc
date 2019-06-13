/* 大數乘法(或者__int128)
 * C(N,K) 且 0 ≦ K ≦ N ≦ 100 => 極限值：C(100,50)＝100!/50!/50!< 1e30(__int128)
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  int caseT, N, K, L;
  char ss[40];

  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d %d",&N,&K);
    K=min(K,N-K);

    vector<int> number;
    for(int i=N-K+1;i<=N;i++)
      number.push_back(i);
    for(int i=2;i<=K;i++)
      for(int j=0, x=i; x>1 and j<number.size(); j++){
        if(number[j]==1) continue;
        int GCD=__gcd(x,number[j]);
        if(GCD>1)
          number[j]/=GCD,
          x/=GCD;
      }
    // 將沒被約分的分子累積
    __int128 ans=1;
    for(int x:number)
      ans*=x;
    // 輸出答案
    for(L=0;ans>0;ans/=10)
      ss[L++]=(char)(ans%10+'0');
    while(L)
      putchar(ss[--L]);
    putchar('\n');
  }
}