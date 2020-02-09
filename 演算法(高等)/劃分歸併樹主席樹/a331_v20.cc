// 靜態區間第Ｋ大數：主席樹解法(模板題)
// 原文說明：https://www.jianshu.com/p/e1d46a714fa8
/* 每一次修改會根據前一次的 root 增加一個新的 root'，這是一個相當重要的一環，
 * 每一次修改會產生新的一棵線段樹，而這個新線段樹大部分節點會使用前一個線段樹的節點，
 * 因此只要針對走訪不影響的情況下，我們仍然會經過舊有的節點。為了找到區間 K 大，
 * 使用函數式線段樹有點類似於掃描線算法，對於某個時間點依序將數字放進去，
 * 然後對於區間查詢 K 大的時候，相當於對某個時間點之間作減法運算。
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001

int rt[MAXN*20];
int lson[MAXN*20];
int rson[MAXN*20];
int sumn[MAXN*20];

int org[MAXN], srt[MAXN];
int tot, qP;
void showtree(int nL,int nR,int &no){
  printf("%2d %d %2d %2d\n",no,sumn[no],lson[no],rson[no]);
  if(nL==nR) return;
  int nM=nL+nR>>1;
  showtree(  nL,nM,lson[no]);
  showtree(nM+1,nR,rson[no]);
}
void buildtree(int nL,int nR,int &no){
  no=++tot;
  sumn[no]=0;
  if(nL==nR) return;
  int nM=nL+nR>>1;
  buildtree(  nL,nM,lson[no]);
  buildtree(nM+1,nR,rson[no]);
}
void update(int nL,int nR,int &no,int last){
  no=++tot;
  lson[no]=lson[last],
  rson[no]=rson[last],
  sumn[no]=sumn[last]+1;
  if(nL==nR) return;
  int nM=nL+nR>>1;
  if(qP<=nM) update(  nL,nM,lson[no],lson[last]);
  else       update(nM+1,nR,rson[no],rson[last]);
}
int query(int nL,int nR,int qL,int qR,int k){
  if(nL==nR) return nL;
  int nM=nL+nR>>1;
  int cnt=sumn[ lson[qR] ]-sumn[ lson[qL] ];
  if(k<=cnt) return query(  nL,nM,lson[qL],lson[qR],k);
  else       return query(nM+1,nR,rson[qL],rson[qR],k-cnt);
}

int main(){
  int N, Q, uniN;
  while(scanf("%d %d",&N,&Q)==2){
    for(int i=1;i<=N;i++)
      scanf("%d",&org[i]),
      srt[i]=org[i];
    // 離散化
    sort(srt+1,srt+1+N);
    uniN=unique(srt+1,srt+1+N)-srt;
    // 建第０棵線段樹(全部都是空的樹)
    tot=0;
    buildtree(1,uniN,rt[0]);

    for(int i=1;i<=N;i++)
      qP=lower_bound(srt+1,srt+uniN,org[i])-srt,
      update(1,uniN,rt[i],rt[i-1]);

    int x, y, k;
    for(int i=1;i<=Q;i++)
      scanf("%d %d %d",&x,&y,&k),
      printf("%d\n",srt[ query(1,uniN,rt[x-1],rt[y],k) ]);
  }
}
/*
7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3
*/