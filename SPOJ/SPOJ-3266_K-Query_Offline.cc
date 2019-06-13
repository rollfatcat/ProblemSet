// 找出區間內比Ｋ大的數字 => 離線處理＋樹狀樹組(0.2s/19MB)
// 對比：K-Query_Online(在線查詢版本)(0.33s/22MB)

#include<bits/stdc++.h>
using namespace std;
#define MAXQ 200005
#define MAXN 30005
#define lowbit(x) (x&-x)

int N;
int org[MAXN];
short ans[MAXQ];
short BIT[MAXN]={};
struct QUERY{
  short L,R; int o, v;
  QUERY(int L=0,int R=0,int v=0,int o=0):L(L),R(R),v(v),o(o){}
  bool operator<(const QUERY &rhs)const{ return (v>rhs.v) or (v==rhs.v and o>rhs.o); }
} query[MAXQ+MAXN];

inline void UpdateBIT(int x){
  for(int i=x; i<=N; i+=lowbit(i))
    BIT[i]++;
}
inline int QueryBIT(int x,int ret=0){
  for(;x;x-=lowbit(x))
    ret+=BIT[x];
  return ret;
}
int main(){
  int Q, L, R, K;
  int Ntot=0, Qtot=0;

  scanf("%d",&N);
  for(int i=1;i<=N;i++)
    scanf("%d",&org[i]),
    query[Qtot++]=QUERY(i,i,org[i]);
  scanf("%d",&Q);
  for(int i=1;i<=Q;i++)
    scanf("%d%d%d",&L,&R,&K),
    query[Qtot++]=QUERY(L,R,K,i);
  // 由大到小排序後依序更新 => 標準離線作法
  sort(query,query+Qtot);

  for(int i=0;i<Qtot;i++)
    if(query[i].o) // 查詢點
      ans[ query[i].o ]=QueryBIT(query[i].R)-QueryBIT(query[i].L-1);
    else // 單點更新
      UpdateBIT(query[i].L),
      Ntot++;

  for(int i=1;i<=Q;i++)
    printf("%d\n",ans[i]);
}
/*
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2
*/