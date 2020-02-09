// 以下是 zkw-SegmentTree 版本(0.07s)
/* 因為這題的DP性質導致 zkw 收攏時改為遞迴版本
 */
#include<bits/stdc++.h>
using namespace std;

const int INF=1<<30;
const int MAXN=5e5+1;
const int MAXM=1<<(__lg(MAXN)+1);
int N, baseM;

struct PAIR{
  int st, ed; long num;
  PAIR(int a=INF,int b=INF,long c=-INF):st(a),ed(b),num(c){}
  bool operator<(const PAIR &rhs)const{
    if(num!=rhs.num)  return num<rhs.num;
    return (st==rhs.st)?(ed>rhs.ed):(st>rhs.st);
  }
} ANS,contL,contR;
struct ZKWTree{
  PAIR L,M,R;
  long sum_num;
  ZKWTree(PAIR L=PAIR(),PAIR M=PAIR(),PAIR R=PAIR(),long x=0):L(L),M(M),R(R),sum_num(x){}
}zkw[(MAXM|1)<<1];
inline bool scanInt(int &x){ // 測資沒有符合空一格的格式
  char c;
  while((c=getchar())==' ' or c=='\n');
  bool sign=c=='-';
  for(x=(sign)?0:(c-'0');(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
  return c!=EOF;
}
void Query_part(int qL,int qR,int pt=0){ //---遞迴版本，因為右側的範圍要會先偵測出來但要後算---
  if((qL^qR^1)==false) return;

  if(~qL&1){
    pt=qL^1;
    // ---max(連續區間+連左,左右斷)---
    contL=PAIR(contR.st, zkw[pt].L.ed, contR.num+zkw[pt].L.num);
    if(contL<zkw[pt].M)   contL=zkw[pt].M;
    // ---max(新連續(連右),連續＋連續)---
    contR=PAIR(contR.st, zkw[pt].R.ed, contR.num+zkw[pt].sum_num);
    if(contR<zkw[pt].R)   contR=zkw[pt].R;
    if(ANS<contL) ANS=contL;
    if(ANS<contR) ANS=contR;
  }
  Query_part(qL>>1,qR>>1);
  if( qR&1){
    pt=qR^1;
    // ---max(連續區間+連左,左右斷)---
    contL=PAIR(contR.st, zkw[pt].L.ed, contR.num+zkw[pt].L.num);
    if(contL<zkw[pt].M)   contL=zkw[pt].M;
    // ---max(新連續(連右),連續＋連續)---
    contR=PAIR(contR.st, zkw[pt].R.ed, contR.num+zkw[pt].sum_num);
    if(contR<zkw[pt].R)   contR=zkw[pt].R;
    if(ANS<contL) ANS=contL;
    if(ANS<contR) ANS=contR;
  }
}
int main(){
  for(int Q,caseN=1; scanInt(N);caseN++){
    scanInt(Q);
    printf("Case %d:\n",caseN);
    baseM=1<<(__lg(N)+1);
    for(int x,i=1;i<=N;i++)
      scanInt(x),
      zkw[baseM+i].L=PAIR(i,i,x),
      zkw[baseM+i].M=PAIR(i,i,x),
      zkw[baseM+i].R=PAIR(i,i,x),
      zkw[baseM+i].sum_num=x;
    // ---把底層的葉子補齊方便建樹---
    zkw[baseM]=ZKWTree();
    for(int i=N+1;i<baseM;i++)
      zkw[baseM+i]=ZKWTree();
    // ---建樹---
    for(int i=baseM-1;i;i--){
      int Lson=i<<1, Rson=Lson|1;
      zkw[i].sum_num=zkw[Lson].sum_num+zkw[Rson].sum_num;
      zkw[i].L=max(zkw[Lson].L,PAIR( zkw[Lson].L.st, zkw[Rson].L.ed, zkw[Lson].sum_num+zkw[Rson].L.num));
      zkw[i].R=max(zkw[Rson].R,PAIR( zkw[Lson].R.st, zkw[Rson].R.ed, zkw[Rson].sum_num+zkw[Lson].R.num));

      zkw[i].M=PAIR( zkw[Lson].R.st, zkw[Rson].L.ed, zkw[Lson].R.num+zkw[Rson].L.num);
      zkw[i].M=max(zkw[i].M, max(zkw[Lson].M,zkw[Rson].M));
    }
    for(int qL,qR;Q--;){
      scanInt(qL),
      scanInt(qR);
      // 單點查詢
      if(qL==qR){ printf("%d %d\n",qL,qR);  continue; }
      // 區間查詢
      ANS=contL=contR=PAIR();
      Query_part(qL+baseM-1,qR+baseM+1);
      printf("%d %d\n",ANS.st,ANS.ed);
    }
  }
}