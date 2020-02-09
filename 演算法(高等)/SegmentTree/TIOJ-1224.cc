// Treap教學文件：https://www.byvoid.com/upload/wp/2010/12/treap-analysis-and-application.pdf
/* 第一眼看會以為要做二維線段樹，但是兩個維度的範圍各自都是(0,1e6)
 * (1) 輸入的點最多是1e5個 => 離散化，但是每個點找對應的ID可能會超時且記憶體空間也不夠
 * (2) 以下寫法是將掃描線+線段樹解法：
 *     針對一個維度做排序(X軸)，用掃描的方式分段計算面積
 *     掃描線掃過去，左線段增加，右線段刪除，線段樹維護當前線段長度 & 覆蓋的個數
 *     概念圖片：http://community.topcoder.com/i/education/lineSweep/rects.png
 * 題解：http://cbdcoding.blogspot.com/2015/02/tioj-1224hoj-12.html
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
int qL, qR, qD;
int addtr[MAXN<<2]={};
int segtr[MAXN<<2]={};
struct P{
  int x,d,u,t;
  P(int a=0,int b=0,int c=0,int d=0):x(a),d(b),u(c),t(d){}
  bool operator<(const P &rhs)const{ return x<rhs.x; }
}data[200002];
inline void scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); }
void Update(int nL,int nR,int pt){
  if(qL<=nL and nR<=qR){ addtr[pt]+=qD; return; }
  int mid=(nL+nR)>>1, Lson=pt<<1;
  if(qL<=mid) Update(   nL,mid,  Lson);
  if(mid< qR) Update(mid+1, nR,Lson|1);
  // ---不能做懶人標記，每次更新完會查詢所有區間內的總和，不如就在BottomUp時更新節點的和---
  segtr[pt]=(addtr[ Lson ]? (mid-nL+1) : segtr[Lson])+
            (addtr[Lson|1]? (nR-mid) : segtr[Lson|1]);
}
int main(){
  int N, L,R,D,U;
  scanInt(N);
  for(int i=0;i<N;i++){
    scanInt(L),scanInt(R),
    scanInt(D),scanInt(U);
    // ---將矩形拆成兩個線段---
    data[ i<<1 ]=P(L,D,U-1, 1);
    data[i<<1|1]=P(R,D,U-1,-1);
  }
  sort(data,data+(N<<1));
  //---讓掃描線更新第一次---
  qL=data[0].d,
  qR=data[0].u,
  qD=data[0].t;
  Update(0,MAXN,1);

  long ans=0;
  for(int i=1;i<(N<<1);i++){
    // segtr[1]=現在全部區間中『塗色』的部分
    // 乘以兩點之間的距離差就是兩條掃描線之間構成的個別面積
    ans+=(long)segtr[1]*(data[i].x-data[i-1].x);
    qL=data[i].d,
    qR=data[i].u,
    qD=data[i].t;
    Update(0,MAXN,1);
  }
  printf("%ld\n",ans);
}
/*
3
1 10 1 10
0 2 0 2
7 10 9 11

4
1 4 3 5
1 4 0 2
0 2 1 4
3 5 1 4
// 20

*/