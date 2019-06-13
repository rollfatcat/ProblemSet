// 設法讓 b 分解成兩個互質的因數 => 方法數＝2^(#質因數個數)

#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
int GCD(int a,int b){ return(a%b)?GCD(b,a%b):b; }
void sieve(){  //數值落在1e6 -> 建表範圍是1e3
  prime.push_back(2);
  vector<bool> isP(1e3+1,1);
  for(int i=3;i<=31;i++)
    if(isP[i])
      for(int k=i<<1,j=k+i;j<=1e3;j+=k)
        isP[j]=0;
  for(int i=3;i<=1e3;i+=2)
    if(isP[i])
      prime.push_back(i);
}
int main(){
  sieve();
  for(int a,b; scanf("%d %d",&a,&b)!=EOF;){
    // 注意題目會給非法輸入導致錯誤的情況
    if(a>b or b%a){ puts("0"); continue; }
    b/=a;
    // 質因數分解
    int cnt=0;
    for(int i=0;i<prime.size() and prime[i]*prime[i]<=b;i++){
      int p=0;
      for(; b%prime[i]==0; b/=prime[i], p++);
      if(p) cnt++;
    }
    if(b>1) cnt++;
    printf("%d\n",1<<cnt);
  }
}