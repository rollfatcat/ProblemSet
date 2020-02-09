// 前綴和+BIT維護數據結構+離散化+排容算法(30ms)
// BIT維護數據結構的做法類似 ZJ-a596，而離散化的概念來自於 ZJ-a572
// 題解：https://www.ptt.cc/bbs/C_and_CPP/M.1548864389.A.A52.html
/* 所有數減完上/下限各自做 PrefixSum (最前面的位置補0)
 * 對減完上限的 upperSum[] 找 #decreasing pair (找到現在的數值減掉後會出現正的 => 比現在數值小的個數)
 * 對減完下限的 lowerSum[] 找 #iecreasing pair (找到現在的數值減掉後會出現負的 => 比現在數值大的個數)
 * 這些pair就是不符合的(排容)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100001;
long upperSum[MAXN]={};
long lowerSum[MAXN]={};
long upperOrd[MAXN]={};
long lowerOrd[MAXN]={};
long upperBIT[MAXN]={};
long lowerBIT[MAXN]={};
int upperCnt, lowerCnt;
inline void scanInt(int &x){
  char c=getchar();
  bool sign=c=='-';
  for(x=(sign)?0:(c-'0');(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
}
inline int lowbit(int x){ return -x&x; }
inline long Query(int now,long *arr,long out=0){
  for(;now>0;now-=lowbit(now))
    out+=arr[now];
  return out;
}
inline void Update(int now,long *arr,int &cnt){
  for(;now<=cnt;now+=lowbit(now))
    arr[now]++;
}
int main(){
  int N, x, Lbound, Ubound;
  scanInt(N),
  scanInt(Lbound),
  scanInt(Ubound);
  for(int i=1;i<=N;i++)
    scanInt(x),
    lowerOrd[i]=lowerSum[i]=lowerSum[i-1]+x-Lbound,
    upperOrd[i]=upperSum[i]=upperSum[i-1]+x-Ubound;
  sort(lowerOrd,lowerOrd+N+1);
  sort(upperOrd,upperOrd+N+1);
  upperCnt=unique(upperOrd,upperOrd+N+1)-upperOrd;
  lowerCnt=unique(lowerOrd,lowerOrd+N+1)-lowerOrd;

  long cnt=(long)N*(N+1)>>1;
  for(int i=0;i<=N;i++){
    // 找到的位置+1，BIT的位置從1開始使用
    int lowerIdx=lower_bound(lowerOrd,lowerOrd+lowerCnt,lowerSum[i])-lowerOrd+1;
    int upperIdx=lower_bound(upperOrd,upperOrd+upperCnt,upperSum[i])-upperOrd+1;
    // Query
    cnt-=i-Query(lowerIdx,lowerBIT); // #increasing pair
    cnt-=Query(upperIdx-1,upperBIT); // #decreasing pair
    // Update
    Update(lowerIdx,lowerBIT,lowerCnt);
    Update(upperIdx,upperBIT,upperCnt);
  }
  printf("%ld\n",cnt);
}
/*
3 3 7
1 5 15
*/