// 注意極端的測資：(1)m=0 (2) overflow的情況
/* 原本以為要根據算式做質因數分解：
 * 1+(1+m)+(1+2m)+...(1+km)= n = (k+1)(1+mn/2)，質因數分解暴力嘗試
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  long n, m;
  while(scanf("%ld %ld",&n,&m)==2){
    long now=1;
    if(m==0){ puts("Go Kevin!!"); continue; }
    while(now+m<=n)
      now+=m;
    puts((now==n)?"Go Kevin!!":"No Stop!!");
  }
}