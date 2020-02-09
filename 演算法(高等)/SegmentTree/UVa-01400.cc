// 題解：http://mypaper.pchome.com.tw/zerojudge/post/1324552065
// http://www.voidcn.com/article/p-ynznmuvj-hh.html
// 和 a164 相同，但只需要輸出最小區間的『範圍』不需要數值

#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+1;
const int INF=1<<30;
int N, qL, qR;
int data[MAXN];
struct PAIR{
  int st, ed; long num;
  PAIR(int a=0,int b=0,long c=0):st(a),ed(b),num(c){};
  bool operator<(const PAIR &rhs)const{ // 選取最佳解:max(num)->min(st)->min(ed)
    if(rhs.num!=num) return num<rhs.num;
    return (rhs.st==st)?(ed>rhs.ed):(st>rhs.st);
  }
} ANS,contL,contR;
/* sum_num：現在這個連續數列的和
 * L:與現在的『左邊界』連接的最大連續數列
 * R:與現在的『右邊界』連接的最大連續數列
 * M:與現在的『左邊界』『右邊界』都不連接的最大連續數列
 */
struct SegmentTree{
  PAIR L, M, R;
  long sum_num;
}seg[MAXN+(MAXN<<1)];
inline bool scanInt(int &x){ // 測資沒有符合空一格的格式
  char c;
  while((c=getchar())==' ' or c=='\n');
  bool sign=c=='-';
  for(x=(sign)?0:(c-'0');(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
  return c!=EOF;
}
void SetTree(int nL,int nR,int pt){
  // ---判斷是不是到達葉節點，是的話設定完後就回上層---
  if(nL==nR){
    seg[pt].sum_num=data[nL];
    seg[pt].L=(PAIR){nL,nL,data[nL]},
    seg[pt].M=(PAIR){nL,nL,data[nL]},
    seg[pt].R=(PAIR){nL,nL,data[nL]};
    return;
  }
  // ---(不需要紀錄邊界)往下遞迴---
  int nM=(nL+nR)>>1, Lson=pt<<1, Rson=Lson|1;
  SetTree(  nL,nM,Lson),
  SetTree(nM+1,nR,Rson);
  // ---合併問題---
  seg[pt].sum_num=seg[Lson].sum_num+seg[Rson].sum_num;

  seg[pt].L=PAIR(nL, seg[Rson].L.ed, seg[Lson].sum_num+seg[Rson].L.num);
  if(seg[pt].L<seg[Lson].L) seg[pt].L=seg[Lson].L;

  seg[pt].R=PAIR(seg[Lson].R.st, nR, seg[Rson].sum_num+seg[Lson].R.num);
  if(seg[pt].R<seg[Rson].R) seg[pt].R=seg[Rson].R;

  seg[pt].M=PAIR(seg[Lson].R.st, seg[Rson].L.ed, seg[Lson].R.num+seg[Rson].L.num);
  if(seg[pt].M<seg[Lson].M) seg[pt].M=seg[Lson].M;
  if(seg[pt].M<seg[Rson].M) seg[pt].M=seg[Rson].M;

}
void Query_part(int nL,int nR,int pt){
  if(qL<=nL and nR<=qR){
    // ---max(連續區間+連左,左右斷)---
    contL=PAIR(contR.st, seg[pt].L.ed, contR.num+seg[pt].L.num);
    if(contL<seg[pt].M)   contL=seg[pt].M;
    // ---max(新連續(連右),連續＋連續)---
    contR=PAIR(contR.st, nR, contR.num+seg[pt].sum_num);
    if(contR<seg[pt].R)   contR=seg[pt].R;

    if(ANS<contL) ANS=contL;
    if(ANS<contR) ANS=contR;
    return;
  }
  int nM=(nL+nR)>>1, Lson=pt<<1;
  if(qL<=nM) Query_part(  nL,nM,  Lson);
  if( nM<qR) Query_part(nM+1,nR,Lson|1);
}
int main(){
  for(int Q,caseN=1; scanInt(N);caseN++){
    scanInt(Q);
    for(int i=1;i<=N;i++)
      scanInt(data[i]);
    SetTree(1,N,1);
    printf("Case %d:\n",caseN);
    while(Q--){
      scanInt(qL),
      scanInt(qR);
      ANS=contL=contR=PAIR(qL,qR,-INF);
      Query_part(1,N,1); // 查詢區間的左/右邊界遞迴時再算就好，省記憶體空間
      printf("%d %d\n",ANS.st,ANS.ed);
    }
  }
}