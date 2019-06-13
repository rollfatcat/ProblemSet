/* (1)這題要找的是區間和 Prefix sum ( 前綴和 )
 * => 可以先建一個陣列 sum[], 其中 sum[i]=array[i]+sum[i-1];
 * 如此可以 sum[a]-sum[b-1] , O(1) 查詢區間 [a,b] 的和
 * (2)因為求最小的且數字皆為正 => 可能有一決定性的位置滿足題目要求
 * 故可利用 Binary Search ( 二分搜 )
*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000001;
const int INF=1<<30;
long preSum[MAXN];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  int N, M;
  scanInt(N),
  scanInt(M);
  for(int x,i=1;i<=N;i++)
    scanInt(x),
    preSum[i]=preSum[i-1]+x;
  int interval=INF;
  for(int st=0;st<=N;st++){
    int ed=lower_bound(preSum,preSum+N+1,preSum[st]+M)-preSum;
    if(preSum[ed]-preSum[st]<M) break;
    interval=min(interval,ed-st);
  }
  if(interval==INF) puts("GGGGGZ");
  else printf("%d\n",interval);
}
/*
6 8
1 3 2 4 0 3
*/