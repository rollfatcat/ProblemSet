// 在線查詢 => 持久化線段樹(2.3s/20.7MB)
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005

int uN, tot, tag, qL, qR;
int org[MAXN];
int srt[MAXN];
int root[MAXN];
int lson[20*MAXN];
int rson[20*MAXN];
int sumn[20*MAXN];

void update(int nL,int nR,int &now,int pre){
  now=++tot;
  lson[now]=lson[pre];
  rson[now]=rson[pre];
  sumn[now]=sumn[pre]+1;
  if(nL==nR) return;
  int nM=nL+nR>>1;
  (tag<=nM)? update(nL,nM,lson[now],lson[pre]): update(nM+1,nR,rson[now],rson[pre]);
}
int QuerySeg(int nL,int nR,int vL,int vR){
  if(qL<=nL and nR<=qR)
    return sumn[vR]-sumn[vL];
  int nM=nL+nR>>1, ret=0;
  if(qL<=nM) ret+=QuerySeg(  nL,nM,lson[vL],lson[vR]);
  if(qR>nM ) ret+=QuerySeg(nM+1,nR,rson[vL],rson[vR]);
  return ret;
}

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int N, Q, vL, vR, numL, numR;
  scanInt(N);
  scanInt(Q);
  for(int i=0;i<N;i++)
    scanInt(org[i]),
    srt[i]=org[i];
  // 離散化
  sort(srt,srt+N);
  uN=unique(srt,srt+N)-srt;
  // 建立Ｎ棵持久化線段樹
  tot=0;
  for(int i=0;i<N;i++)
    tag=lower_bound(srt,srt+uN,org[i])-srt,
    update(0,uN-1,root[i+1],root[i]);
  // 在線查詢
  while(Q--){
    scanInt(vL),
    scanInt(vR),
    scanInt(qL),
    scanInt(qR);
    // 注意這邊的lower_bound()和upper_bound 的搭配：可以解決 Query=(8,9,3,3)/(3,4,7,9) 這類的情況
    qL=lower_bound(srt,srt+uN,qL)-srt,
    qR=upper_bound(srt,srt+uN,qR)-srt-1;
    printf("%d\n",QuerySeg(0,uN-1,root[vL-1],root[vR]));
  }
}
/*
10 10
4 4 5 1 4 1 5 1 2 1
5 9 1 2 // 3
3 4 7 9 // 0
4 4 2 5 // 0
2 3 4 7 // 2
5 10 4 4 //1
3 9 1 1 // 3
1 4 5 9 // 1
8 9 3 3 // 0
2 2 1 6 // 1
8 9 1 4 // 2
*/