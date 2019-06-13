// 莫隊離線作法＋tree結構實現KthTree(70% AC+20% WA+10% TLE)

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define MAXN 100005
#define MAXQ 5005

int Bsz;
int org[MAXN];
int ans[MAXQ];
struct QUERY{
  int L,R,v,o;
  QUERY(int L=0,int R=0,int v=0,int o=0):L(L),R(R),v(v),o(o){}
  bool operator<(const QUERY &rhs)const{ return (L/Bsz)<(rhs.L/Bsz) or (L/Bsz)==(rhs.L/Bsz) and R<rhs.R; }
} query[MAXQ];

int main(){
  int N, Q, L, R, v;
  while(scanf("%d%d",&N,&Q)==2){
    ordered_set<int>  store;
    Bsz=ceil(sqrt(N));
  	for(int i=0;i<N;i++)
  	  scanf("%d",&org[i]);
  	for(int i=0;i<Q;i++)
  	  scanf("%d%d%d",&L,&R,&v),
  	  query[i]=QUERY(L-1,R-1,v-1,i);
  	sort(query,query+Q);

  	int nowL=query[0].L;
  	int nowR=query[0].R;
  	for(int i=nowL;i<=nowR;i++)
  	  store.insert(org[i]);
  	ans[ query[0].o ]=*store.find_by_order(query[0].v);
  	for(int i=1;i<Q;i++){
  	  while(nowL<query[i].L) store.erase (org[nowL++]);
  	  while(nowL>query[i].L) store.insert(org[--nowL]);
  	  while(nowR<=query[i].R) if(nowL<=nowR) store.insert(org[++nowR]);
  	  while(nowR>query[i].R) store.erase (org[nowR--]);
      ans[ query[i].o ]=*store.find_by_order(query[i].v);
  	}
  	for(int i=0;i<Q;i++)
  	  printf("%d\n",ans[i]);
  }
}