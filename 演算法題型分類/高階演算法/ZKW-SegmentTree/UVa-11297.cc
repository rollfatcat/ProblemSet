// 題目要求：區域查詢＋單點更新，二維zkw線段樹版本
// 題解：http://mypaper.pchome.com.tw/zerojudge/post/1322951791
#include<bits/stdc++.h>
using namespace std;

const int INF=1<<30;
const int MAXN=500;
const int MAXM=1<<(__lg(MAXN)+1);
struct SegmentTree{
  int SubMax[MAXM<<1|1];
  int SubMin[MAXM<<1|1];
}zkw_tr[MAXM<<1|1];
int N, M;
int ansMax, ansMin;

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
void UpdateNode(int leaf_x,int leaf_y,int v){
  // ---把位置調整到zkwTree當中Leaf的位置---
  leaf_x+=M, leaf_y+=M;
  // ---更新這個點和這個維度(固定 x 維度)的subTree
  zkw_tr[leaf_x].SubMax[leaf_y]=v,
  zkw_tr[leaf_x].SubMin[leaf_y]=v;
  for(int y=leaf_y;y>1;y>>=1)
    zkw_tr[leaf_x].SubMax[y>>1]=max(zkw_tr[leaf_x].SubMax[y],zkw_tr[leaf_x].SubMax[y^1]),
    zkw_tr[leaf_x].SubMin[y>>1]=min(zkw_tr[leaf_x].SubMin[y],zkw_tr[leaf_x].SubMin[y^1]);
  // ---固定 y 維度更新 x 維度的 subTree
  for(int x=leaf_x;x>1;x>>=1)
    for(int y=leaf_y;y>0;y>>=1)
      zkw_tr[x>>1].SubMax[y]=max(zkw_tr[x].SubMax[y],zkw_tr[x^1].SubMax[y]),
      zkw_tr[x>>1].SubMin[y]=min(zkw_tr[x].SubMin[y],zkw_tr[x^1].SubMin[y]);
}
void SubQuery(int R,int LC,int RC){
  for(int qLC=LC+M-1,qRC=RC+M+1; qLC^qRC^1; qLC>>=1,qRC>>=1){
    if(~qLC&1)
      ansMax=max(ansMax,zkw_tr[R].SubMax[qLC^1]),
      ansMin=min(ansMin,zkw_tr[R].SubMin[qLC^1]);
    if( qRC&1)
      ansMax=max(ansMax,zkw_tr[R].SubMax[qRC^1]),
      ansMin=min(ansMin,zkw_tr[R].SubMin[qRC^1]);
  }
}
void Query_part(int LR,int LC,int RR,int RC){
  for(int qLR=LR+M-1,qRR=RR+M+1; qLR^qRR^1; qLR>>=1,qRR>>=1){
    if(~qLR&1) SubQuery(qLR^1,LC,RC);
    if( qRR&1) SubQuery(qRR^1,LC,RC);
  }
}
int main(){

  while(scanInt(N)){
    M=1<<(__lg(N)+1);
    // ---建樹---
    for(int x=M<<1;x;x--)
      for(int y=(M<<1)-1;y;y--)
        zkw_tr[x].SubMax[y]=0,
        zkw_tr[x].SubMin[y]=INF;
    // ---讀入每個點後做單點更新---
    int Q, v, stx, sty, edx, edy;
    for(int i=1;i<=N;i++)
      for(int j=1;j<=N;j++)
        scanInt(v),
        UpdateNode(i,j,v);
    // ---根據指令操作---
    for(scanInt(Q); Q--;){
      char cmd=getchar(); getchar();
      if(cmd=='q'){ // ---區間查詢---
        scanInt(stx),
        scanInt(sty),
        scanInt(edx),
        scanInt(edy);
        ansMax=0, ansMin=INF;
        Query_part(stx,sty,edx,edy);
        printf("%d %d\n",ansMax,ansMin);
      }else // ---單點更新---
        scanInt(stx),
        scanInt(sty),
        scanInt(v),
        UpdateNode(stx,sty,v);
    }
  }
}
/*
5 5
1 2 3 4 5
0 9 2 1 3
0 2 3 4 1
0 1 2 4 5
8 5 3 1 4
4
q 1 1 2 3
c 2 3 10
q 1 1 5 5
q 1 2 2 2
*/