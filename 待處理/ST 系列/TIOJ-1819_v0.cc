// 線段樹(類似b526)
// 題解：http://cbdcoding.blogspot.com/2015/02/tioj-1819.html
#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+5;
int qL, qR;
int node_L[MAXN];
int node_R[MAXN];
int seg[12*MAXN], tag[12*MAXN];
int ptL[12*MAXN], ptR[12*MAXN];
vector<int> node;

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
void Update(int nL,int nR,int pt){
  if(qL<=nL and nR<=qR){
    seg[pt]+=1-ptL[pt]-ptR[pt];
    tag[pt]^=1, ptL[pt]^=1, ptR[pt]^=1;
    return;
  }
  int mid=(nL+nR)>>1, Lson=pt<<1, Rson=Lson|1;
  // ---線段合併---
  if(tag[pt]){
    seg[Lson]+=1-ptL[Lson]-ptR[Lson];
    tag[Lson]^=1, ptL[Lson]^=1, ptR[Lson]^=1;
    seg[Rson]+=1-ptL[Rson]-ptR[Rson];
    tag[Rson]^=1, ptL[Rson]^=1, ptR[Rson]^=1;
    tag[pt]=0 ;
  }
  if(qL<=mid) Update(   nL,mid,Lson);
  if(mid< qR) Update(mid+1, nR,Rson);
  seg[pt]=seg[Lson]+seg[Rson];
  ptL[pt]=ptL[Lson],
  ptR[pt]=ptR[Rson];
  if(ptL[Rson] and ptR[Lson]) seg[pt]--;
}
int main(){
  int Q, N;

  scanInt(Q),
  scanInt(N);
  node.push_back(1),
  node.push_back(N);
  for(int i=0;i<Q;i++){
    scanInt(node_L[i]),
    scanInt(node_R[i]);
    // ---題目不保證測資的線段端點是給左/右---
    if(node_L[i]>node_R[i])
      node_L[i]^=node_R[i]^=node_L[i]^=node_R[i];
    node.push_back(node_L[i]),
    node.push_back(node_R[i]),
    node.push_back(node_L[i]-1),
    node.push_back(node_R[i]-1);
  }
  // --- 離散化 ---
  sort(node.begin(),node.end());
  node.resize(unique(node.begin(),node.end())-node.begin());
  int ans=0;
  for(int i=0;i<Q;i++){
    qL=lower_bound(node.begin(),node.end(),node_L[i])-node.begin(),
    qR=lower_bound(node.begin(),node.end(),node_R[i])-node.begin();
    Update(0,MAXN,1);
    ans=max(ans,seg[1]);
  }
  printf("%d\n",ans);
}
/*
5 10
2 4
7 9
5 6
3 4
7 8
*/