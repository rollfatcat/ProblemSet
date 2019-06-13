// 單點修改和區間查詢(zkwTree版本：1s)
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;
int zkw_tr[3*MAXN]={};
long number[MAXN], data[MAXN];
inline bool scanLong(long &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){

  for(long N,Qx; scanLong(N); ){
    // ---離線處理，預先讀取全部的輸入---
    for(int i=0;i<N;i++)
      scanLong(number[i]), data[i]=number[i];
    sort(number,number+N);
    // --- 排序後轉為大小 ---
    int M=1<<(__lg(N)+1);
    memset(zkw_tr,0,sizeof(zkw_tr));
    for(int i=0;i<N;i++){
      Qx=lower_bound(number,number+N,data[i])-(&number[0]); Qx++;
      // --- 區間查詢，輸出名次 ---
      int sumN=0;
      for(int qL=M,qR=M+Qx; qL^qR^1; qL>>=1,qR>>=1){
        if(~qL&1) sumN+=zkw_tr[qL^1];
        if( qR&1) sumN+=zkw_tr[qR^1];
      }
      printf("%d\n",i+1-sumN);
      // --- 單點修改 ---
      zkw_tr[Qx+M]++;
      for(int pos=(Qx+M)>>1; pos; pos>>=1)
        zkw_tr[pos]++;
    }
  }
}