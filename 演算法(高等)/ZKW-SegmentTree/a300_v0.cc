// 題解：http://yp155136codingarea.blogspot.com/2016/07/zj-a300-noip2011-day12.html
// 建極值(最小值)樹+區間查詢(zkw：0.2s)
/* 觀察可以發現一個單調性：假設固定一個開始的客棧a，假設(a,b)存在一間咖啡廳可以負荷低消，那(a,c)且(c>b)也可以透過這間咖啡廳可以負荷低消
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5;
const int INF=1<<30;
vector<int> group[MAXN];
int val[MAXN];
int GID[MAXN];
int zkwtr[3*MAXN];

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int Query_part(int qL,int qR){
  int minV=INF;
  for(qL-=1,qR+=1; qL^qR^1; qL>>=1,qR>>=1){
    if(~qL&1) minV=min(minV,zkwtr[qL^1]);
    if( qR&1) minV=min(minV,zkwtr[qR^1]);
  }
  return minV;
}
int main(){
  int N, M, K, P;

  scanInt(N),
  scanInt(K),
  scanInt(P);
  M=1<<(__lg(N)+1);
  for(int i=M;i<(M<<1);i++)
    zkwtr[i]=INF;
  for(int i=0;i<N;i++)
    scanInt(GID[i]),
    scanInt(val[i]),
    zkwtr[i+M]=val[i],
    group[GID[i]].push_back(i+M);
  // ---建樹---
  for(int i=M-1; i; i--)
    zkwtr[i]=min(zkwtr[i<<1],zkwtr[i<<1|1]);

  long ans=0;
  for(int i=0;i<K;i++){
    if(group[i].size()>1)
      for(int j=0,len=group[i].size(); j<len-1; j++){
        int nL=j, nR=len-1;
        while(nR-nL>1){
          int nM=(nL+nR)>>1;
          // ---區間查詢---
          if(Query_part(group[i][j],group[i][nM])>P) nL=nM;
          else nR=nM;
        }
        if(Query_part(group[i][j],group[i][nR])>P) break;
        else ans+=len-nR;
      }
  }
  printf("%ld\n",ans);
}
/*
5 2 3
0 5
1 3
0 2
1 4
1 5
*/