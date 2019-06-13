/* 原題型：BZOJ-3211
 * 預備知識：數值開多次根號後會快速收斂變成1
 * 換句話說更新的停止條件是該區段內的所有數值都是1或0時就不需要更新，否則會持續到葉節點。
 * Query()和一般線段樹相同，Update()方式遵從上述方式，更新後再做push_up
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 300000

long sumn[MAXN<<2];
long isrt[MAXN<<2];
int qL, qR;

void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
void scanLong(long &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
void push_up(int pt){
  sumn[pt]=sumn[pt<<1]+sumn[pt<<1|1];
  isrt[pt]=isrt[pt<<1]&isrt[pt<<1|1];
}
void build(int nL,int nR,int pt){
  if(nL==nR){
    scanLong(sumn[pt]);
    isrt[pt]=sumn[pt]<=1;
    return;
  }
  int nM=nL+nR>>1;
  build(  nL,nM,  pt<<1);
  build(nM+1,nR,pt<<1|1);
  push_up(pt);
}
void update(int nL,int nR,int pt){
  // 開根號收斂的很快，所以停止條件變更為更新到葉節點或者目前這節點數值小於等於1
  if(isrt[pt]) return;
  if(nL==nR){
    sumn[pt]=sqrt(sumn[pt]);
    isrt[pt]=sumn[pt]<=1;
    return;
  }
  int nM=nL+nR>>1;
  if(qL<=nM) update(  nL,nM,  pt<<1);
  if(qR>nM ) update(nM+1,nR,pt<<1|1);
  push_up(pt);
}
long query(int nL,int nR,int pt){
  if(qL<=nL and nR<=qR) return sumn[pt];
  int nM=nL+nR>>1; long ret=0;
  if(qL<=nM) ret+=query(  nL,nM,  pt<<1);
  if(qR>nM ) ret+=query(nM+1,nR,pt<<1|1);
  return ret;
}
int main(){
  int N, Q;
  scanInt(N);
  scanInt(Q);
  build(1,N,1);
  for(int opt;Q--;){
    scanInt(opt),
    scanInt(qL),
    scanInt(qR);
    if(opt)   update(1,N,1);
    else  printf("%ld\n",query(1,N,1));
  }
}
/*
5 3
16 9 1 5 3
0 1 5
1 1 5
0 1 5
*/