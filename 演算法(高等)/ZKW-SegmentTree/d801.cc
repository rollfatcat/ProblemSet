// 1 ≦Ｎ,Ｍ≦ 1000,000，數組中的元素絕對值均不超過1,000,000,000
// 將『刪除節點』轉為『單點修改』＋『號碼查詢』
/* 作法：需要兩棵線段樹去維護：維護最大最小值的查詢/紀錄實際應該查找的區間。
 * 一開始很傻的用 BIT 去維護，但是後來想是想錯了，那個複雜度是O(logN*logN)，會吃TLE
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000001;
const int MAXM=1<<(__lg(MAXN)+1)|1;
const int INF=1<<30;
struct NODE{
  int maxv, minv;
  NODE(int a=-INF,int b=INF):maxv(a),minv(b){}
}zkw[MAXM<<1];
int zkn[MAXM<<1], M;

inline void scanInt(int &x){
  char c=getchar();
  bool sign=c=='-';
  for(x=sign?0:(c-'0');(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
}
inline int GetID(int idx,int pos=1){ // 將輸入的節點號碼轉為zkw樹的號碼
  while(pos<M) // 和左節點總數比較
    if(zkn[pos<<1]<idx)
      idx-=zkn[pos<<1],
      pos=pos<<1|1;
    else
      pos=pos<<1;
  return pos-M;
}
int main(){
  int N, Q;
  scanInt(N);
  scanInt(Q);
  M=1<<(__lg(N)+1);
  zkw[M]=NODE();
  for(int u,i=1;i<=N;i++)
    scanInt(zkw[M+i].maxv),
    zkw[M+i].minv=zkw[M+i].maxv,
    zkn[M+i]++;
  // 補齊最底層的葉節點避免建表時出現錯誤資訊
  for(int i=M+N+1;i<(M<<1);i++)
    zkw[i]=NODE();
  // zkw的標準建樹
  for(int i=M-1;i;i--)
    zkw[i].maxv=max(zkw[i<<1].maxv,zkw[i<<1|1].maxv),
    zkw[i].minv=min(zkw[i<<1].minv,zkw[i<<1|1].minv),
    zkn[i]=zkn[i<<1]+zkn[i<<1|1];

  // 在線查詢
  int act, qL, qR;
  while(Q--){
    scanInt(act),
    scanInt(qL);
    if(act==1){
      qL=M+GetID(qL);
      zkn[qL]=0,
      zkw[qL]=NODE();
      for(qL>>=1;qL;qL>>=1)
        zkn[qL]--,
        zkw[qL].maxv=max(zkw[qL<<1].maxv,zkw[qL<<1|1].maxv),
        zkw[qL].minv=min(zkw[qL<<1].minv,zkw[qL<<1|1].minv);
    }else{
      scanInt(qR);
      qL=GetID(qL)+M-1;
      qR=GetID(qR)+M+1;
      NODE rec=NODE();
      for(;qL^qR^1;qL>>=1,qR>>=1){
        if(~qL&1)
          rec.maxv=max(rec.maxv,zkw[qL^1].maxv),
          rec.minv=min(rec.minv,zkw[qL^1].minv);
        if( qR&1)
          rec.maxv=max(rec.maxv,zkw[qR^1].maxv),
          rec.minv=min(rec.minv,zkw[qR^1].minv);
      }
      printf("%d %d\n",rec.minv,rec.maxv);
    }
  }
}
/*
10 4
1 5 2 6 7 4 9 3 1 5
2 2 8
1 3
1 6
2 2 8
*/