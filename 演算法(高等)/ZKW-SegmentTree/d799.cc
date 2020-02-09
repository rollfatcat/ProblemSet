// ZKW式版本(0.3s)
#include<bits/stdc++.h>
using namespace std;

const long MAXN=500000;
const long M=1<<(__lg(MAXN)+1);
struct nn{ long num,add; } zkw_tr[M<<1|1];
inline void scanLong(long &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  long N, Q;
  // --- 讀取＋建樹 ---
  scanLong(N);
  for(int i=M+1;i<=M+N;i++)
    scanLong(zkw_tr[i].num), zkw_tr[i].add=0;
  for(int i=M-1;i;i--)
    zkw_tr[i].num=zkw_tr[i<<1].num+zkw_tr[i<<1|1].num;
  // --- 區間查詢＋區間修改 ---
  long act, qL, qR, d;
  for(scanLong(Q); Q--;){
    scanLong(act), scanLong(qL), scanLong(qR);
    long nL=0, nR=0, len=1;
    if(act==1){ // 修改
      scanLong(d);
      for(qL+=M-1,qR+=M+1; qL^qR^1; ){
        if(~qL&1) zkw_tr[qL^1].add+=d, nL+=len;
        if( qR&1) zkw_tr[qR^1].add+=d, nR+=len;
        qL>>=1, qR>>=1, len<<=1;
        zkw_tr[qL].num+=d*nL;
        zkw_tr[qR].num+=d*nR;
      }
      for(nL+=nR,qL>>=1; qL; qL>>=1)
        zkw_tr[qL].num+=d*nL;

    }else{// 查詢：區間和單點不需要分開處理
      long sumN=0;
      for(qL+=M-1,qR+=M+1; qL^qR^1; ){
        if(~qL&1) sumN+=zkw_tr[qL^1].num+zkw_tr[qL^1].add*len, nL+=len;
        if( qR&1) sumN+=zkw_tr[qR^1].num+zkw_tr[qR^1].add*len, nR+=len;
        qL>>=1,qR>>=1,len<<=1;
        if(zkw_tr[qL].add) sumN+=zkw_tr[qL].add*nL;
        if(zkw_tr[qR].add) sumN+=zkw_tr[qR].add*nR;
      }
      for(nL+=nR,qL>>=1; qL; qL>>=1)
        if(zkw_tr[qL].add)
          sumN+=zkw_tr[qL].add*nL;
      printf("%ld\n",sumN);
    }
  }
}