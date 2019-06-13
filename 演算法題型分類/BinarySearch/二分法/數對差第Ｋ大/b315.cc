// 作法等同a277，查詢Kth大的差值
// 暴力法嘗試『可能的差值』，最後範圍會收斂於 nR
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100001;
const int INF=1<<30;
int num[MAXN];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  int N, K;
  scanInt(N);
  scanInt(K);
  int maxv=0, minv=INF;
  for(int i=0;i<N;i++)
    scanInt(num[i]),
    maxv=max(maxv,num[i]),
    minv=min(minv,num[i]);
  // 排序不影響數對差值
  sort(num,num+N);
  long R=(long)N*(N-1)/2-K+1; // 將第Ｋ大轉換成需要贏過多少個
  int nL=0, nR=maxv-minv;
  while(nL<=nR){
    int nM=(nL+nR)>>1;
    int st, idx;
    long Cnt=0;
    for(idx=st=0;st<N;st++)
      idx=lower_bound(num+idx,num+N,num[st]+nM)-num,
      Cnt+=idx-1-st;
    (Cnt<R)?(nL=nM+1):(nR=nM-1);
  }
  // 維持原本的合法性：右端點合法，左端點未知
  printf("%d\n",nR);
}
/*
4 5
1 5 8 10
*/