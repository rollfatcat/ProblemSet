// 1<=N<=1000，每個數字都介於1和N^2之間而且沒有重複

#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000
#define lowbit(x) (x&-x)

int BIT[MAXN][MAXN];
int DP[MAXN][MAXN];
int N;
struct NODE{ short x, y; }v[MAXN*MAXN];

inline void update(int x,int y,int val){
  for(int i=x;i<=N;i+=lowbit(i))
    for(int j=y;j<=N;j+=lowbit(j))
      BIT[i][j]=max(BIT[i][j],val);
}
inline int query(int x,int y,int out=0){
  for(int i=x;i;i-=lowbit(i))
    for(int j=y;j;j-=lowbit(j))
      out=max(out,BIT[i][j]);
  return out;
}
int main(){
  scanf("%d",&N);
  for(int i=1;i<=N;i++)
    for(int x,j=1;j<=N;j++)
      scanf("%d",&x),
      v[x]=(NODE){i,j};
  for(int nowv=1;nowv<=N*N;nowv++)
    DP[ v[nowv].x ][ v[nowv].y ]=query(v[nowv].x,v[nowv].y)+1,
    update(v[nowv].x,v[nowv].y,DP[v[nowv].x][v[nowv].y]);
  printf("%d\n",query(N,N));
}
/*
3
9 4 1
6 5 7
2 3 8
4
1 15 4 5
2 10 9 16
14 7 8 3
13 6 11 12
*/