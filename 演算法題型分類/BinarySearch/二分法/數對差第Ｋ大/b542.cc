/* 題目給Ｎ(N=1e5)個人的身高，問某兩人的身高差Ｋ的情況是否存在？
 * 數對差第Ｋ大的前置題(某個差值是否存在？)
 * (X) 排序後枚舉兩個數字產生所有的差值，數字有1e5個所以差值最多有5e9個(太多不可能記錄起來)
 * (O) 線性枚舉利用 slide window 移動計算差值是否剛好是查詢的目標(5e7)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int N, Q, diff;
  int num[MAXN];

  scanInt(N),
  scanInt(Q);
  for(int i=0;i<N;i++)
    scanInt(num[i]);
  sort(num,num+N);
  while(Q--){
    scanInt(diff);
    bool hasAns=false;
    for(int st=0,ed=1; ed<N;){
      if(num[ed]-num[st]>diff) st++; //差值太大，ed往後移一個
      else if(num[ed]-num[st]<diff) ed++; //差值太小，ed往後移一個
      else{ hasAns=true; break; } // 找到差值，跳開
    }
    puts( (hasAns)?"YES":"NO" );
  }
}