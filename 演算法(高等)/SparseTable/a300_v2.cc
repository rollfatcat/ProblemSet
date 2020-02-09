// 題解：http://yp155136codingarea.blogspot.com/2016/07/zj-a300-noip2011-day12.html
// 建極值(最小值)樹+區間查詢( SparseTable：69ms/19.9MB )
/* 觀察可以發現一個單調性：假設固定一個開始的客棧a，假設(a,b)存在一間咖啡廳可以負荷低消，
 * 客棧c 在客棧b 右邊，則(a,c)也可以選擇這間咖啡廳符合低消要求
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5;
vector<int> group[MAXN];
int ST[19][MAXN]; // => __lg(MAXN)=17

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int N, K, P, color, value;

  scanInt(N),
  scanInt(K),
  scanInt(P);
  for(int i=0;i<N;i++)
    scanInt(color),
    scanInt(ST[0][i]),
    group[color].push_back(i);
  // ---建樹---
  for(int h=0; (1<<h)<N; h++)
    for(int st=0;st+(1<<h)<N;st++)
      ST[h+1][st]=min(ST[h][st],ST[h][st+(1<<h)]);

  int ans=0;
  for(int i=0;i<K;i++)
    if(group[i].size()>1){
      for(int j=0,len=group[i].size()-1; j<len; j++){
        int nL=j, nR=len, h_ST;
        while(nR-nL>1){
          int nM=(nL+nR)>>1;
          h_ST=__lg(group[i][nM]-group[i][j]+1);
          // ---區間查詢---
          if( min(ST[h_ST][group[i][j]],ST[h_ST][group[i][nM]-(1<<h_ST)+1])>P ) nL=nM;
          else nR=nM;
        }
        h_ST=__lg(group[i][nR]-group[i][j]+1);
        if(min( ST[h_ST][group[i][j]],ST[h_ST][group[i][nR]-(1<<h_ST)+1] )>P) break;
        else ans+=len-nR+1;
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
===
3
*/