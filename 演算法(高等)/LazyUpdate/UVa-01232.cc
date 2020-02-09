// 注意 Return 時的條件(參考測資更新的情況)
// 原先線段樹紀錄的是點，這題的線段樹紀錄的是長度單位1的區間(n,n+1]
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;
int qL, qR, qH, sum;
struct TreeNode{
  int maxh,minh,setv;
  TreeNode(int a=0,int b=0,int c=0):maxh(a),minh(b),setv(c){}
}seg[MAXN<<2];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
void Update_part(int nL,int nR,int pt){
  int nM=(nL+nR)>>1, Lson=pt<<1, Rson=Lson|1;
  // ---PushDown---
  if(nL!=nR and seg[pt].setv)
    seg[Lson]=TreeNode(seg[pt].setv,seg[pt].setv,seg[pt].setv),
    seg[Rson]=TreeNode(seg[pt].setv,seg[pt].setv,seg[pt].setv),
    seg[pt].setv=0;
  // ---現在建築的高度高於這個區間內的最低高度，代表不需要往下遞迴---
  if(seg[pt].minh>qH)
    return;
  // ---原本的線段樹更新只要更新的區段涵蓋子區段就會停止---
  // 但在某一區段內的高度並不會統一，唯有更新到『可以覆蓋』和『現在高度低於該區段內最低高度時』會停止
  if(qL<=nL and nR<=qR and qH>=seg[pt].maxh){
    sum+=nR-nL+1,
    seg[pt]=TreeNode(qH,qH,qH);
    return;
  }
  // ---Recursive---
  if(qL<=nM) Update_part(  nL,nM,Lson);
  if(nM<qR)  Update_part(nM+1,nR,Rson);
  // ---PushUp---
  seg[pt].maxh=max(seg[Lson].maxh,seg[Rson].maxh);
  seg[pt].minh=min(seg[Lson].minh,seg[Rson].minh);
}
int main(){
  for(int caseN;scanInt(caseN) and caseN;)
    for(int N;caseN--;){
      memset(seg,0,sizeof(seg));
      sum=0;
      for(scanInt(N);N--;)
        scanInt(qL),
        scanInt(qR),qR--,
        scanInt(qH),
        Update_part(1,MAXN,1);
      printf("%d\n",sum);
    }
}
/*
5
4 7 9
8 13 10
6 16 4
7 8 1
12 13 3
*/