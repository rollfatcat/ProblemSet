// 2D RMQ => 和 1D RMQ的差異，題目等同 uva-11297(但不需要單點更新)
/* (1)建樹時會出現 lx>rx or ly>ry 的情況
 * (2)Query時的判斷方式
 * 簡單剪枝：某個子區塊的最大值等同現在這區塊的最大值就可以不用比較其他子區塊
 * 利用 d800 的 SparseTable版本(0.3s=>84ms)
 */
#include<iostream>
using namespace std;
#define MaxN 501

int N, M, Qlx, Qly, Qrx, Qry;
int A[MaxN][MaxN];
int node[(MaxN*MaxN)<<1]; // 最大的號碼是 4^(h+1)-1/3, h代表最長的邊對2取log

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
// 模擬(1,3,1,3)的分切
void SetTree(int now,int lx,int rx,int ly,int ry){
  if(lx>rx or ly>ry) return;
  if(lx==rx and ly==ry){ node[now]=A[lx][ly]; return; }
  // 切4塊，但注意idx的推導關係
  int mx=(lx+rx)>>1, my=(ly+ry)>>1, idx=now<<2;
  SetTree(idx-2,  lx,mx,  ly,my);
  SetTree(idx-1,mx+1,rx,  ly,my);
  SetTree(  idx,  lx,mx,my+1,ry);
  SetTree(idx+1,mx+1,rx,my+1,ry);
  node[now]=max( max(node[idx-2],node[idx-1]),max(node[idx],node[idx+1]) );
}
int Query(int now,int lx,int rx,int ly,int ry){
  // 現在搜尋的範圍落在問的範圍內
  if(lx>=Qlx and ly>=Qly and rx<=Qrx and ry<=Qry) return node[now];
  int mx=(lx+rx)>>1, my=(ly+ry)>>1, maxA=0, idx=now<<2;
  if(Qly<=my){
    if(Qlx<=mx) maxA=max(maxA, Query(idx-2,  lx,mx,  ly,my));
    if(maxA==node[now]) return maxA;
    if(Qrx>mx)  maxA=max(maxA, Query(idx-1,mx+1,rx,  ly,my));
    if(maxA==node[now]) return maxA;
  }
  if(Qry>my){
    if(Qlx<=mx) maxA=max(maxA, Query(  idx,  lx,mx,my+1,ry));
    if(maxA==node[now]) return maxA;
    if(Qrx>mx)  maxA=max(maxA, Query(idx+1,mx+1,rx,my+1,ry));
    if(maxA==node[now]) return maxA;
  }
  return maxA;
}
int main(){

  scanInt(N),
  scanInt(M);
  for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
      scanInt(A[i][j]);
  SetTree(1,1,N,1,M);
  int Q;
  for(scanInt(Q);Q--;)
    scanInt(Qlx),
    scanInt(Qly),
    scanInt(Qrx),
    scanInt(Qry),
    printf("%d\n",Query(1,1,N,1,M));
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