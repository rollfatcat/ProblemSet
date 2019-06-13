// MergeTree to solve Online Query(0.11/22MB)
// MergeTree is SegmentTree with vectors.

#include<bits/stdc++.h>
using namespace std;
#define MAXN 30005

vector<int> node[MAXN<<2];
int qL, qR, qK;

void BuildTree(int nL,int nR,int pt){
  // 到達葉節點時讀取數據後就回傳
  if(nL==nR){ scanf("%d",&qK); node[pt].push_back(qK); return; }
  // 未到達葉節點時繼續遞迴分治
  int nM=nL+nR>>1;
  BuildTree(  nL,nM,  pt<<1);
  BuildTree(nM+1,nR,pt<<1|1);
  // 合併區間資訊(等同MergeSort)
  merge(node[ pt<<1 ].begin(), node[ pt<<1 ].end(),
        node[pt<<1|1].begin(), node[pt<<1|1].end(), back_inserter(node[pt]));
}
int QueryTree(int nL,int nR,int pt){
  if(qL<=nL and nR<=qR){ return node[pt].size()-( upper_bound(node[pt].begin(),node[pt].end(),qK)-node[pt].begin() ); }
  int nM=nL+nR>>1, ret=0;
  if(qL<=nM) ret+=QueryTree(  nL,nM,  pt<<1);
  if(qR>nM ) ret+=QueryTree(nM+1,nR,pt<<1|1);
  return ret;
}
int main(){
  int N, Q;

  scanf("%d",&N);
  BuildTree(1,N,1);

  scanf("%d",&Q);
  int pre_ans=0;
  while(Q--){
    scanf("%d%d%d",&qL,&qR,&qK);
    // 和前一個答案取 XOR 轉換成正確的範圍和數值
    qL^=pre_ans; if(qL<1) qL=1;
    qR^=pre_ans; if(qR>N) qR=N;
    qK^=pre_ans;
    //
    pre_ans=(qL>qR)? 0: QueryTree(1,N,1);
    printf("%d\n",pre_ans);
  }
}
/*
6
8 9 3 5 1 9
5
2 3 5
3 3 7
0 0 11
0 0 2
3 7 4
*/