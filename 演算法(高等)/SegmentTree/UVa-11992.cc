// 題目的要求應該是支援區間查詢/區間更新/區間設定的二維線段樹(每次都要顯示總和/最大值/最小值)
// 題目保證：(1)矩陣最多20個Rows (2)元素數量最多1e6個且任意操作的總和不會超過1e9 (3)操作有2e4個
/* 不一定要維護一個二維陣列，可以把查詢的二維區間拆解成數個一維的區間操作(題目保證的(1))
***但問題出在要怎麼做『區間設定』呢？
 * 线段树维护的信息:有setv,addv,sumv,maxv,minv.其中对于当前节点的sumv,maxv和minv永远都是最新的信息,setv和addvv是用来下传更新儿子节点的.当setv和addvv一到给定节点的时候就已经更新了maxv和minv的信息.
 * 对于PushDown操作总是先处理setv,再处理addv的.因为如果setv后出现,必然会把addv清0.
 * 注意PushDown的时候记得判断当前i节点是不是叶节点,因为它有可能没有儿子节点了.
 * 而PushUp操作不需要处理setv和addv,只需要维护sumv,maxv和minv信息即可.
 * 這個題目牽涉到 maxv/minv 需要建樹時做初始化
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXR=20;
const int MAXN=1e6;
const int INF=1<<30;
const int Unset=-INF;
const int MAXSize=(1<<(__lg(MAXN)+1)|1)<<1;
int N, qL, qR, dev;
struct SegmentTree{
  int sumv, maxv, minv, addv, setv;
  SegmentTree(int a=0,int b=0,int c=0,int d=0,int e=Unset):sumv(a),maxv(b),minv(c),addv(d),setv(e){}
}seg[MAXSize], ANS;

inline bool scanInt(int &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  bool sign=c=='-';
  for(x=(sign)?0:(c-'0');(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
  return c!=EOF;
}
void BuildTree(int nL,int nR,int pt){
  seg[pt]=SegmentTree();
  if(nL==nR)  return;
  int nM=(nL+nR)>>1;
  BuildTree(  nL,nM,  pt<<1);
  BuildTree(nM+1,nR,pt<<1|1);
}
void PushDown(int nL,int nR,int pt){ //更新兩個子結點的資訊且順序是setv優先判定
  int nM=(nL+nR)>>1, Lson=pt<<1, Rson=Lson|1;
  if(seg[pt].setv!=Unset)
    seg[Lson]=SegmentTree( (nM-nL+1)*seg[pt].setv, seg[pt].setv, seg[pt].setv, 0, seg[pt].setv),
    seg[Rson]=SegmentTree(   (nR-nM)*seg[pt].setv, seg[pt].setv, seg[pt].setv, 0, seg[pt].setv),
    seg[pt].setv=Unset;
  if(seg[pt].addv)
    seg[Lson].sumv+=(nM-nL+1)*seg[pt].addv,
    seg[Lson].maxv+=seg[pt].addv,
    seg[Lson].minv+=seg[pt].addv,
    seg[Lson].addv+=seg[pt].addv,
    seg[Rson].sumv+=(nR-nM)*seg[pt].addv,
    seg[Rson].maxv+=seg[pt].addv,
    seg[Rson].minv+=seg[pt].addv,
    seg[Rson].addv+=seg[pt].addv,
    seg[pt].addv=0;
}
void PushUp(int pt){ // 更新這個節點的資訊
  seg[pt].sumv=    seg[pt<<1].sumv+seg[pt<<1|1].sumv;
  seg[pt].maxv=max(seg[pt<<1].maxv,seg[pt<<1|1].maxv);
  seg[pt].minv=min(seg[pt<<1].minv,seg[pt<<1|1].minv);
}
void Update_part(int nL,int nR,int pt){ //--- lazy-propogate ---
  if(qL<=nL and nR<=qR){
    seg[pt].addv+=dev,
    seg[pt].maxv+=dev,
    seg[pt].minv+=dev,
    seg[pt].sumv+=(nR-nL+1)*dev;
    return;
  }
  int nM=(nL+nR)>>1;
  PushDown(nL,nR,pt);
  if(qL<=nM) Update_part(  nL,nM,  pt<<1);
  if(nM<qR ) Update_part(nM+1,nR,pt<<1|1);
  PushUp(pt);
}
void Set_part(int nL,int nR,int pt){
  if(qL<=nL and nR<=qR){
    seg[pt]=SegmentTree( (nR-nL+1)*dev, dev, dev, 0, dev);
    return;
  }
  int nM=(nL+nR)>>1;
  PushDown(nL,nR,pt);
  if(qL<=nM) Set_part(  nL,nM,  pt<<1);
  if( nM<qR) Set_part(nM+1,nR,pt<<1|1);
  PushUp(pt);
}
void Query_part(int nL,int nR,int pt){
  if(qL<=nL and nR<=qR){
    ANS.sumv+=seg[pt].sumv;
    ANS.maxv=max( ANS.maxv, seg[pt].maxv);
    ANS.minv=min( ANS.minv, seg[pt].minv);
    return;
  }
  int nM=(nL+nR)>>1;
  PushDown(nL,nR,pt);
  if(qL<=nM) Query_part(  nL,nM,  pt<<1);
  if( nM<qR) Query_part(nM+1,nR,pt<<1|1);
  PushUp(pt);
}
int main(){
  for(int R,C,Q; scanInt(R);){
    scanInt(C),
    scanInt(Q);
    N=R*C;
    // ---建樹---
    BuildTree(1,N,1);
    // ---根據二維資訊做分段操作(更新/設定/查詢)---
    for(int qLx,qLy,qRx,qRy;Q--;){
      char cmd=getchar()-'0';
      scanInt(qLx),
      scanInt(qLy),
      scanInt(qRx),
      scanInt(qRy);
      if(cmd==3){
        ANS=SegmentTree(0,-INF,INF);
        for(int idx=qLx-1; idx<qRx; idx++){
          qL=idx*C+qLy,
          qR=idx*C+qRy;
          Query_part(1,N,1);
        }
        printf("%d %d %d\n",ANS.sumv,ANS.minv,ANS.maxv);
      }else{
        scanInt(dev);
        if(cmd==2){
          for(int idx=qLx-1; idx<qRx; idx++){
            qL=idx*C+qLy,
            qR=idx*C+qRy;
            Set_part(1,N,1);
          }
        }else{
          for(int idx=qLx-1; idx<qRx; idx++){
            qL=idx*C+qLy,
            qR=idx*C+qRy;
            Update_part(1,N,1);
          }
        }
      }
    } // 操作結束
  }
}
/*
4 4 8
1 1 2 4 4 5
3 2 1 4 4
1 1 1 3 4 2
3 1 2 4 4
3 1 1 3 4
2 2 1 4 4 2
3 1 2 4 4
1 1 1 4 3 3
*/