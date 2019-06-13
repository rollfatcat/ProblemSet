// ZJ-c203/UVa13185 的加強版，需要剪枝(0.2s/1.3MB)
#include<bits/stdc++.h>
using namespace std;

vector<int> prime; // 999983 is 78498th prime.
int main(){
  // seive(): 1,000,000以內的質數
  vector<bool> NotPrime(1000001,0);
  prime.push_back(2);
  for(int i=3;i<=1000;i+=2)
    for(int j=3;i*j<=1000000;j+=2)
      NotPrime[i*j]=1;
  for(int i=3;i<=1000000;i+=2)
    if(NotPrime[i]==0)
      prime.push_back(i);
  // 根據輸入做質因數分解
  int caseT, idx, sz=prime.size();
  long N, num, sum, p;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%ld",&N);
    sum=1, num=N, N<<=1;
    for(idx=0;idx<sz and prime[idx]*prime[idx]<=num;idx++){ // <- 剪枝
      if(num%prime[idx]) continue;
      for(p=prime[idx];num%prime[idx]==0;p*=prime[idx],num/=prime[idx]);
      sum*=(p-1)/(prime[idx]-1);
      if(sum>N) break; // 避免sum overflow，只要超過2倍的N就可以跳開
    }
    if(num>1) sum*=(num+1); // num還沒整除，代表還有一個因數可以用

    if(N>sum) puts("deficient");
    else if(N==sum) puts("perfect");
    else puts("abundant");
  }
}
/*
9
999900007063
934053120000
999900003719
349621272000
560431872000
999900001643
999900003863
539630239744
137438691328

888870586725
*/