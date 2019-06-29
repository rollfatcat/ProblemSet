// 查並問題
// 假設兩個號碼屬於不同群就合併(將數量少的指向數量多的並比較數量最多的群)
// 假設兩個號碼屬於同一群，Do Nothing
#include<bits/stdc++.h>
using namespace std;

int p[1000001];
int n[1000001];
int GetP(int x){ return(p[x]==x)? x: p[x]=GetP(p[x]); }
int main(){
  int N, M, a, b;

  while(scanf("%d%d",&N,&M)==2){
    for(int i=0;i<N;i++)
      p[i]=i, n[i]=1;
    int maxv=1;
    while(M--){
      scanf("%d%d",&a,&b);
      int pa=GetP(a);
      int pb=GetP(b);
      if(pa==pb) continue;
      if( n[pa]>=n[pb] )
        p[pb]=pa, n[pa]+=n[pb], maxv=max(maxv,n[pa]);
      else
        p[pa]=pb, n[pb]+=n[pa], maxv=max(maxv,n[pb]);
    }
    printf("%d\n",maxv);
  }
}
/*
6 4
0 1
2 3
1 3
5 4
1000000 0
1000000 1
0 999999
*/