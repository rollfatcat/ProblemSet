#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000000;
int M=1<<(__lg(MAXN)+1);
int zkw_tr[MAXN<<2]={};
inline bool scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); return c!=EOF; }
int DFS(long now){
  if(now<=1000000){ //計算過程中不重複算過的部分
    int pos=now+M;
    if(!zkw_tr[pos])
      zkw_tr[pos]=DFS( (now&1)?(3*now+1):(now>>1) )+1;
    return zkw_tr[pos];
  }
  return DFS( (now&1)?(3*now+1):(now>>1) )+1;
}
int main(){
  zkw_tr[M+1]=1;
  for(int idx=2; idx<=1000000; idx++)
    if(!zkw_tr[M+idx])
      zkw_tr[M+idx]=DFS( (idx&1)?(3*idx+1):(idx>>1) )+1;
  // --- 建樹 --- <-題目在建樹完之後就不會修改，支援可修改版本寫法會降速(91ms)
  for(int idx=M-1; idx; idx--)
    zkw_tr[idx]=max(zkw_tr[idx<<1],zkw_tr[idx<<1|1]),
    zkw_tr[idx<<1]-=zkw_tr[idx],
    zkw_tr[idx<<1|1]-=zkw_tr[idx];
  for(int qL,qR; scanInt(qL);){
    scanInt(qR);
    printf("%d %d ",qL,qR);
    if(qL>qR) qL^=qR^=qL^=qR;
    // 區間查詢/單點查詢
    int L=0, R=0, maxN=0;
    qL+=M, qR+=M;
    if(qL!=qR){
      for(; qL^qR^1; qL>>=1,qR>>=1){
        L+=zkw_tr[qL] ,R+=zkw_tr[qR];
        if(~qL&1) L=max(L,zkw_tr[qL^1]);
        if(qR&1)  R=max(R,zkw_tr[qR^1]);
      }
    }
    maxN=max(L+zkw_tr[qL],R+zkw_tr[qR]);
    for(qL>>=1; qL; qL>>=1)
      maxN+=zkw_tr[qL];
    printf("%d\n",maxN);
  }
}