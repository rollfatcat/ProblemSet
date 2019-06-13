// 根據定義計算O(n^2)，可通過80%(20%TLE)
// 差異分數= |{ (i, j) |(si > sj and ri < rj) or (si < sj and ri > rj), 1 ≤ i < j ≤ k}|.
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100002;
int data[2][MAXN];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  int N, maxS;
  scanInt(N),
  scanInt(maxS);

  for(int i=0;i<N;i++)
    scanInt(data[0][i]);
  for(int i=0;i<N;i++)
    scanInt(data[1][i]);
  // |{ (i, j) |(si > sj and ri < rj) or (si < sj and ri > rj), 1 ≤ i < j ≤ k}|.
  long res=0;
  for(int i=0;i<N;i++)
    for(int j=0;j<i;j++)
      if( (data[0][i]>data[0][j] and data[1][i]<data[1][j]) or
          (data[0][i]<data[0][j] and data[1][i]>data[1][j]) )
        res++;
  printf("%ld\n",res);
}