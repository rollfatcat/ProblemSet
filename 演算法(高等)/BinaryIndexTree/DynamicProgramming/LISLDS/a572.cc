/* 題目要求『嚴格遞增』子序列(不一定連續)，動態規劃的遞增子序列問題
 * 在動態規劃裡面的做法是 DP[i]=max( DP[j] )+num[i] ,if(j<i and num[i]>num[j])，O(n^2)
 * 這題的時間需求要降低到O(n㏒n)，做法類似a596的BIT＋離散化
 * 利用 BIT 查詢比目前數值還要小的 DP[idx] 中數值最大者
 * 原本動態規劃的 DP[idx] idx是指輸入的順序，但是這個版本的 idx 代表的是離散化後的數值順序
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=10001;
int ordN;
int num[MAXN];
int ord[MAXN];
long DP[MAXN];

inline int lowbit(int x){ return -x&x; }
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
inline long Query(int idx,long out=0){
  for(;idx>0; idx-=lowbit(idx))
    out=max(out,DP[idx]);
  return out;
}
inline void Update(int idx,int end,long val){
  for(;idx<=end;idx+=lowbit(idx))
    DP[idx]=max(DP[idx],val);
}
int main(){
  for(int N;scanInt(N);){
    for(int i=1;i<=N;i++)
      scanInt(num[i]), ord[i]=num[i];
    memset(DP,0,sizeof(DP));
    sort(ord,ord+N+1);
    ordN=(unique(ord,ord+N+1)-ord);
    // Main Function
    long prev, best=0;
    for(int i=1;i<=N;i++){
      int now=lower_bound(ord,ord+ordN,num[i])-ord;
      prev=Query(now-1);
      Update(now,ordN,prev+num[i]);
      best=max(best,prev+num[i]);
    }
    printf("%ld\n",best);
  }
}