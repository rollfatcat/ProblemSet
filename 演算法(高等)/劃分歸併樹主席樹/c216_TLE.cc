// (72%) TLE的主因是因為區間查詢時最糟情況是會一直往下到葉節點才會收斂
// 關鍵是更新時是『整個區間』一起增加某個高度
/* 正解：將區間查詢轉換成：區間內有幾個點加完高度後會『爆掉』。
 * 區間和＝前綴和+要增加的高度x區間個數-(區間個數-沒爆料)x1e5
 */

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001

int N, Q, qH=0, qL, qR;
int remn[MAXN<<2];
long sumn[MAXN<<2];

void build(int nL,int nR,int pt){
  if(nL==nR){
    scanf("%ld",&sumn[pt]),
    remn[pt]=MAXN-1-sumn[pt];
    return;
  }
  int nM=nL+nR>>1, Lson=pt<<1;
  build(  nL,nM,  Lson);
  build(nM+1,nR,Lson|1);
  // push_up
  sumn[pt]=sumn[Lson]+sumn[Lson|1];
  remn[pt]=min(remn[Lson],remn[Lson|1]);
}
long query(int nL,int nR,int pt){
  if(nL==nR){ // 到達葉節點就直接計算回傳值
    long ret=sumn[pt]+qH; ret=(ret>100000)? ret-100000: ret;
    return ret;
  }
  if(qL<=nL and nR<=qR and remn[pt]>=qH) // 落在區間內且查詢高度必須小於等於區間內的『容忍度』
    return sumn[pt]+qH*(nR-nL+1);
  int nM=nL+nR>>1;
  long ret=0;
  if(qL<=nM) ret+=query(  nL,nM,  pt<<1);
  if(qR>nM ) ret+=query(nM+1,nR,pt<<1|1);
  return ret;
}
int main(){
  scanf("%d%d",&N,&Q);
  build(1,N,1);

  int opt, h;
  while(Q--){
    scanf("%d",&opt);
    if(opt==2)
      scanf("%d%d",&qL,&qR),
      printf("%ld\n",query(1,N,1));
    else
      scanf("%d",&h),
      qH=(qH+h)%100000;
  }
}