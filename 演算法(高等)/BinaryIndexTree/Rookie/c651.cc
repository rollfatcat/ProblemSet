/* 注意：題目時間壓得很死，需要優化輸入
 * 利用 XOR 的計算特性可以和前綴和相同
 * 拿到BIT的模板應該都是求區間和，假設要求[L,R]的區間和是不是只要 sum(R)−sum(L−1)
 * 這題改成區間 XOR BIT 初始化就改成 XOR，然後把求前綴和的+改成 XOR就變成前綴XOR
 * (1)區間查詢： xxor(R) ⊕ xxor(L−1)
 * (2)單點修改： 先把原本的數字跟要變成的數字做XOR變成val，利用歸零律跟自反性，後面需要更新的數字，統一跟val做XOR
 */

#include<bits/stdc++.h>
using namespace std;

int org_data[1000002]={}, BIT_data[1000002]={};
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
inline int lowbit(int x){ return x&-x; }
int query_suffix(int x){
  int sum;
  for(sum=0; x; x-=lowbit(x))
    sum^=BIT_data[x];
  return sum;
}
int main(){
  int N, Q, act;
  scanInt(N),
  scanInt(Q);
  for(int i=1;i<=N;i++)
    scanInt(org_data[i]),
    BIT_data[i]=org_data[i];
  // Build BinaryIndexTree---------
  for(int i=1;i<=N;i++){
    int up_layer=i+lowbit(i);
    if(up_layer<=N)
      BIT_data[up_layer]^=BIT_data[i];
  }
  for(int act,a,b; Q--; ){
    scanInt(act),
    scanInt(a),
    scanInt(b);
    // 單點修改：先查詢同位置的原始數值(交換輸入的值)和要修改成的值作XOR，
    // 之後根據拜訪過的區間作XOR的值修改
    if(act){
      b^=org_data[a],
      org_data[a]^=b;
      // update----------
      for(int now=a; now<=N; now+=lowbit(now))
        BIT_data[now]^=b;
    }else // 區間查詢：suffix(1,b)^suffix(1,a-1)
      printf("%d\n",query_suffix(b)^query_suffix(a-1));
  }
}