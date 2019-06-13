// 莫隊離散處理
#include<bits/stdc++.h>
using namespace std;
#define MAXN 30005
#define MAXQ 200005
#define MAXNUM 1000001

int Bsz, now_cnt=0;
int org[MAXN]={};
short ans[MAXQ]={};
short cnt[MAXNUM]={};
struct QUERY{
  int L, R, ID, bn;
  QUERY(int L=0,int R=0,int o=0,int b=0):L(L),R(R),ID(o),bn(b){}
  bool operator<(const QUERY &rhs)const{ return bn<rhs.bn or (bn==rhs.bn and R<rhs.R); }
}query[MAXQ];

inline void add(int x){
  cnt[x]++;
  if(cnt[x]==1)
    now_cnt++;
}
inline void sub(int x){
  cnt[x]--;
  if(cnt[x]==0)
    now_cnt--;
}

int main(){

  int N, Q, L, R;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d",&org[i]);
  Bsz=sqrt(N);
  // 讀取查詢
  scanf("%d",&Q);
  for(int i=0;i<Q;i++)
    scanf("%d %d",&L,&R),
    query[i]=QUERY(L-1,R-1,i,(L-1)/Bsz);
  sort(query,query+Q);
  // 莫隊
  int nowL=0, nowR=0;
  add(org[0]);
  for(int i=0;i<Q;i++){
    while(nowL<query[i].L) sub(org[nowL++]);
    while(nowL>query[i].L) add(org[--nowL]);
    while(nowR<query[i].R) add(org[++nowR]);
    while(nowR>query[i].R) sub(org[nowR--]);
    ans[ query[i].ID ]=now_cnt;
  }
  for(int i=0;i<Q;i++)
    printf("%d\n",ans[i]);
}
/*
5
1 1 2 1 3
3
1 5
2 4
3 5
*/