// 題解：http://baluteshih.blogspot.com/2018/01/zj-c259-kevin.html
/* 解法的巧妙處在於紀錄區間內第二小的數值(secv)以及最小數值的個數(mcnt)
 * 搭配 LazyUpdate，避免每次作區間更新時都要更新到葉節點，把需要更新的值暫時存到 lazy 值
 * 更新區間資訊時要維護區間內最小和第二小值
 * minv ≧ lazy       ，代表這個值對於 sumv 沒有任何作用，DoNothing
 * secv > lazy ≧ minv，代表需要更新 minv 和 sumv
 * lazy ≧ secv       ，往左右節點 PushDown 後再做 PushUp 保證資訊的正確性
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=300000;
const long INF=(long)1<<60;
int N, Q, qL, qR;
long qK;
bool IsLeaf[MAXN<<2];
struct NODE{
  long sumv, minv, secv, mcnt, lazy;
  NODE(long a=0,long b=0,long c=INF,long d=1,long e=0):sumv(a),minv(b),secv(c),mcnt(d),lazy(e){}
}node[MAXN<<2];

/* 該節點的資訊來自源於左右節點 sumv 直接相加，minv 和 secv 和 mcnt 根據情況合併
 * 葉節點沒有左右子樹，所以 sumv=0，且 secv=INF 和 mcnt=1 不會有任何變動
 */
void PushUp(int pt){
  if(IsLeaf[pt])
    node[pt].sumv=0;
  else{
    int Lson=pt<<1, Rson=Lson|1;
    node[pt].sumv=node[Lson].sumv+node[Rson].sumv;
    if(node[Lson].minv>node[Rson].minv)
      node[pt].minv=node[Rson].minv,
      node[pt].secv=min(node[Lson].minv,node[Rson].secv),
      node[pt].mcnt=node[Rson].mcnt;
    else if(node[Lson].minv<node[Rson].minv)
      node[pt].minv=node[Lson].minv,
      node[pt].secv=min(node[Rson].minv,node[Lson].secv),
      node[pt].mcnt=node[Lson].mcnt;
    else
      node[pt].minv=node[Rson].minv,
      node[pt].secv=min(node[Lson].secv,node[Rson].secv),
      node[pt].mcnt=node[Lson].mcnt+node[Rson].mcnt;
  }
}

/* 更新
 *
 */
void PushDown(int pt){
  if(node[pt].lazy==0) return; //不須更新的狀態
  if(IsLeaf[pt]==0){
    int Lson=pt<<1, Rson=Lson|1;
    // 更新左節點
    if(node[Lson].minv>=node[pt].lazy);
    else if(node[Lson].secv>node[pt].lazy)
      node[Lson].sumv+=(node[pt].lazy-node[Lson].minv)*node[Lson].mcnt,
      node[Lson].minv=node[Lson].lazy=node[pt].lazy;
    else
      node[Lson].lazy=node[pt].lazy,
      PushDown(Lson),
      PushUp(Lson);
    // 更新右節點
    if(node[Rson].minv>=node[pt].lazy);
    else if(node[Rson].secv>node[pt].lazy)
      node[Rson].sumv+=(node[pt].lazy-node[Rson].minv)*node[Rson].mcnt,
      node[Rson].minv=node[Rson].lazy=node[pt].lazy;
    else
      node[Rson].lazy=node[pt].lazy,
      PushDown(Rson),
      PushUp(Rson);
  }
  node[pt].lazy=0;
}
void BuildSegTree(int nL,int nR,int pt){
  if(nL==nR){
    scanf("%ld",&node[pt].minv),
    node[pt]=NODE(node[pt].minv,node[pt].minv);
    IsLeaf[pt]=1;
    return;
  }
  int nM=(nL+nR)>>1;
  BuildSegTree(  nL,nM,  pt<<1);
  BuildSegTree(nM+1,nR,pt<<1|1);
  PushUp(pt);
}
void ShowTree(int nL,int nR,int pt){
  if(nL==nR){ printf("%d %ld %ld %ld %ld %ld\n",pt,node[pt].sumv,node[pt].minv,node[pt].secv,node[pt].mcnt,node[pt].lazy); return;}
  int nM=(nL+nR)>>1;
  ShowTree(nL,nM,pt<<1);
  ShowTree(nM+1,nR,pt<<1|1);
  printf("%d %ld %ld %ld %ld %ld\n",pt,node[pt].sumv,node[pt].minv,node[pt].secv,node[pt].mcnt,node[pt].lazy);
}
long Query(int nL,int nR,int pt){
  PushDown(pt);
  if(qL<=nL and nR<=qR) return node[pt].sumv;
  int nM=(nL+nR)>>1;
  if(qR<=nM)     return Query(  nL,nM,  pt<<1);
  else if(qL>nM) return Query(nM+1,nR,pt<<1|1);
  else return Query(nL,nM,pt<<1)+Query(nM+1,nR,pt<<1|1);
}
void Update(int nL,int nR,int pt){
  PushDown(pt);
  if(qL<=nL and nR<=qR){
    if(node[pt].minv>=qK);
    else if(node[pt].secv>qK)
      node[pt].sumv+=(qK-node[pt].minv)*node[pt].mcnt,
      node[pt].minv=node[pt].lazy=qK;
    else
      node[pt].lazy=qK,
      PushDown(pt),
      PushUp(pt);
    return;
  }
  int nM=(nL+nR)>>1;
  if(qL<=nM)Update(  nL,nM,  pt<<1);
  if(qR>nM )Update(nM+1,nR,pt<<1|1);
  PushUp(pt);
}

int main(){
  scanf("%d",&N);
  scanf("%d",&Q);
  BuildSegTree(1,N,1);
  //
  int act;
  while(Q--){
    scanf("%d",&act),
    scanf("%d",&qL),
    scanf("%d",&qR);
    if(act==1)
      scanf("%ld",&qK),
      Update(1,N,1);
    else
      printf("%ld\n",Query(1,N,1));
  }
}
/*
8 7
1 2 2 4 5 6 6 8
2 1 8
1 2 4 7
2 2 2
1 2 3 4
2 5 8
1 3 7 10
2 1 8
*/