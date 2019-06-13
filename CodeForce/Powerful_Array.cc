// 莫隊算法(WA on test 6)
#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define MAXC 1000005

int Bsz;
int cnt[MAXC];
long long nowv;
long long org[MAXN]={};
long long ans[MAXN]={};

struct QUERY{
  int L,R,ID,B;
  QUERY(int L=0,int R=0,int ID=0,int B=0):L(L),R(R),ID(ID),B(B){}
  bool operator<(const QUERY &rhs)const{ return (B<rhs.B) or (B==rhs.B and R<rhs.R); }
} query[MAXN];

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int N, Q, L, R;
  cin>>N>>Q;
  Bsz=ceil((double)sqrt(N));
  for(int i=0;i<N;i++)
    cin>>org[i];
  for(int i=0;i<Q;i++)
    cin>>L>>R,
    query[i]=QUERY(L-1,R-1,i,(L-1)/Bsz);
  sort(query,query+Q);

  nowv=0;
  int nowL=query[0].L;
  int nowR=query[0].R;
  for(long i=nowL;i<=nowR;i++)
    nowv+=(cnt[org[i]]<<1|1)*org[i],
    cnt[org[i]]++;
  ans[query[0].ID]=nowv;

  for(int i=1;i<Q;i++){
    while(nowL<query[i].L)
      cnt[org[nowL]]--,
      nowv-=(cnt[org[nowL]]<<1|1)*org[nowL],
      nowL++;
    while(nowL>query[i].L)
      nowL--,
      nowv+=(cnt[org[nowL]]<<1|1)*org[nowL],
      cnt[org[nowL]]++;
    while(nowR<query[i].R)
      nowR++,
      nowv+=(cnt[org[nowR]]<<1|1)*org[nowR],
      cnt[org[nowR]]++;
    while(nowR>query[i].R)
      cnt[org[nowR]]--,
      nowv-=(cnt[org[nowR]]<<1|1)*org[nowR],
      nowR--;
    ans[ query[i].ID ]=nowv;
  }
  for(int i=0;i<Q;i++)
    cout<<ans[i]<<'\n';
}
/*
3 2
1 2 1
1 2
1 3

8 3
1 1 2 2 1 3 1 1
2 7
1 6
2 7
*/