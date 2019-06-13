// 標準的線段樹算法，需要思考的是區間合併時的資訊問題
// 單節點紀錄的是區間內的括號配對數和落單的左括號和落單的右括號數量

#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005

char ss[MAXN];
int qL, qR;
struct NODE{
  int Pcrs, Lcrs, Rcrs;
  NODE(int P=0,int L=0,int R=0):Pcrs(P),Lcrs(L),Rcrs(R){}
} node[MAXN<<2], ans;
void BuildTree(int nL,int nR,int pt){
  if(nL==nR){
    node[pt]=NODE();
    (ss[nL-1]=='(')? node[pt].Lcrs=1: node[pt].Rcrs=1;
    return;
  }
  int nM=nL+nR>>1, Lson=pt<<1, Rson=Lson|1;
  BuildTree(  nL,nM,Lson);
  BuildTree(nM+1,nR,Rson);
  int new_pair=min(node[Lson].Lcrs, node[Rson].Rcrs);
  node[pt].Pcrs=node[Lson].Pcrs+node[Rson].Pcrs+new_pair;
  node[pt].Lcrs=node[Lson].Lcrs+node[Rson].Lcrs-new_pair;
  node[pt].Rcrs=node[Lson].Rcrs+node[Rson].Rcrs-new_pair;
}
NODE QuerySeg(int nL,int nR,int pt){
  if(qL<=nL and nR<=qR) return node[pt];
  int nM=nL+nR>>1;
  if(qR<=nM)     return QuerySeg(  nL,nM,  pt<<1);
  else if(qL>nM) return QuerySeg(nM+1,nR,pt<<1|1);
  else{
    NODE nodeL=QuerySeg(  nL,nM,  pt<<1);
    NODE nodeR=QuerySeg(nM+1,nR,pt<<1|1);
    int new_pair=min(nodeL.Lcrs, nodeR.Rcrs);
    return NODE(nodeL.Pcrs+nodeR.Pcrs+new_pair,
                nodeL.Lcrs+nodeR.Lcrs-new_pair,
                nodeL.Rcrs+nodeR.Rcrs-new_pair);
  }
}
int main(){
  int N, Q;

  scanf("%s",ss);
  N=strlen(ss);
  BuildTree(1,N,1);
  scanf("%d",&Q);
  while(Q--)
    scanf("%d%d",&qL,&qR),
    ans=QuerySeg(1,N,1),
    printf("%d\n",ans.Pcrs<<1);
}
/*
())(())(())(
7
1 1
2 3
1 2
1 12
8 12
5 11
2 10
*/