/* 乍看之下以為需要使用特殊圖論的演算法避免環的偵測問題，但忽略了解題關鍵
 * 關鍵：這些城市能到達的城市編號都大於本身城市編號小於等於N
 * 利用動態規劃思考這個問題
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define MOD 1234567

int cnt[MAXN]={0,1};
inline void scanInt(int &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
}
int main(){
  int N, M, x;
  int sum_cnt=0;
  scanInt(N);
  for(int i=1;i<=N;i++){
    scanInt(M);
    while(M--)
      scanInt(x),
      cnt[x]=(cnt[x]+cnt[i])%MOD;
  }
  printf("%d\n",cnt[N]);
}
/*
5 2 2 3 4 8
6 3 3 3 3 5 7
5 4 6 7 7 7
4 5 5 7 8
5 6 6 6 7 8
1 7
3 8 8 8
0
*/