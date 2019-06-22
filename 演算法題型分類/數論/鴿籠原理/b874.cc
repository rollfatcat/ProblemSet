/* 題目給定N(MAXN=1e5)個數字，問是否存在任意個數的數字總合可以被M整除
 * (X) 枚舉所有可能的數字總和？
 * (O) 前綴和＋鴿籠原理
 * 令Ｓi為前 i 個數字之和，能定義出Ｓ0-Ｓn這 n+1 個前綴。依據鴿籠原理，在模 K ≤ N 時至少有兩前綴同餘。
 * 而Ｓa ≡ Ｓb(mod k)(a<b) 自然代表 (a,b] 是一組解了。整體能在線性時間下解決。
 */

#include<bits/stdc++.h>
using namespace std;

const int MAXM=1e4;
bool IsIn[MAXM+1];

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int caseT, N, M, v;

  scanInt(caseT);
  while(caseT--){
    scanInt(N),
    scanInt(M);

    fill(IsIn,IsIn+M+1,0);
    IsIn[0]=1;
    int pre_sum=0;
    bool getIt=false;
    while(N--){
      scanInt(v);
      pre_sum=(pre_sum+v%M)%M;
      getIt|=IsIn[pre_sum];
      IsIn[pre_sum]=1;
    }
    puts((getIt)?"YES":"NO");
  }
}