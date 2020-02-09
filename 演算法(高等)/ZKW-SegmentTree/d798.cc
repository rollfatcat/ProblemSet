// zkw線段樹版本(83ms)
#include<bits/stdc++.h>
using namespace std;

const int INF=1<<30;
const int MAXN=500;
const int MAXM=1<<(__lg(MAXN)+1);
struct SegmentTree{
  int SubMax[MAXM<<1|1]={};
}zkw_tr[MAXM<<1|1];
int R, C, RM, CM, ansMax;

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
void UpdateNode(int leaf_x,int leaf_y){
  // ---把位置調整到zkwTree當中Leaf的位置---
  leaf_x+=RM,
  leaf_y+=CM;
  // ---更新這個點和這個維度(固定 x 維度)的subTree
  for(int y=leaf_y;y>1;y>>=1)
    zkw_tr[leaf_x].SubMax[y>>1]=max(zkw_tr[leaf_x].SubMax[y],zkw_tr[leaf_x].SubMax[y^1]);
  // ---固定 y 維度更新 x 維度的 subTree
  for(int x=leaf_x;x>1;x>>=1)
    for(int y=leaf_y;y;y>>=1)
      zkw_tr[x>>1].SubMax[y]=max(zkw_tr[x].SubMax[y],zkw_tr[x^1].SubMax[y]);
}
void SubQuery(int R,int LC,int RC){
  for(int qLC=LC+CM-1,qRC=RC+CM+1; qLC^qRC^1; qLC>>=1,qRC>>=1){
    if(~qLC&1)  ansMax=max(ansMax,zkw_tr[R].SubMax[qLC^1]);
    if( qRC&1)  ansMax=max(ansMax,zkw_tr[R].SubMax[qRC^1]);
  }
}
void Query_part(int LR,int LC,int RR,int RC){
  for(int qLR=LR+RM-1,qRR=RR+RM+1; qLR^qRR^1; qLR>>=1,qRR>>=1){
    if(~qLR&1) SubQuery(qLR^1,LC,RC);
    if( qRR&1) SubQuery(qRR^1,LC,RC);
  }
}
int main(){

  scanInt(R),
  scanInt(C);
  RM=1<<(__lg(R)+1);
  CM=1<<(__lg(C)+1);
  // ---讀入每個點後做單點更新---
  int Q, v, stx, sty, edx, edy;
  for(int i=1;i<=R;i++)
    for(int j=1;j<=C;j++)
      scanInt(zkw_tr[i+RM].SubMax[j+CM]),
      UpdateNode(i,j);

  // ---根據指令操作---
  for(scanInt(Q); Q--;){
    // ---區間查詢---
    scanInt(stx),
    scanInt(sty),
    scanInt(edx),
    scanInt(edy);
    ansMax=0;
    Query_part(stx,sty,edx,edy);
    printf("%d\n",ansMax);
  }
}
/*
5 6
7 4 3 7 5 1
3 4 7 1 1 6
0 1 8 3 2 5
1 5 9 5 1 5
8 2 6 6 4 5
10
2 4 5 5
1 4 5 5
1 2 3 5
4 2 5 3
4 4 5 5
2 1 5 4
3 4 5 5
2 2 4 2
2 2 2 5
4 3 4 4
*/