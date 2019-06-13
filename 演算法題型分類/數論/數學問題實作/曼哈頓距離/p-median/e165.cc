// 1e3個點在一維座標分群(最多10群)，目標最小化群內的曼哈頓距離總和
/* 初步想法：以間隔前K-1個距離作為分群的標準(20%)
 * 正解：p-Median Problem(演算筆記：http://www.csie.ntnu.edu.tw/~u91029/LocationAllocationProblem.html#2)
 * 動態規劃推導：
 * f(k, n) =
 *  { min( f(k-1, k-1) + d(k  , n) ,
 *  {      f(k-1, k  ) + d(k+1, n) ,
 *  {      ...                     ,
 *  {      f(k-1, n-2) + d(k-1, n) ,
 *  {      f(k-1, n-1) + d(k  , n) )  if k < n  && n >= 0
 *  {
 *  { 0                               if k >= n && n >= 0
 *  { +inf                            otherwise
 *  k：已設立了p個聯絡站。
 *  n：已涵蓋了第1個到第n個地點。
 *  f(p, n)：設立p個聯絡站，涵蓋第1個到第n個地點時，其聯絡距離的總和。
 *  d(i, j)：第i個地點到第j個地點所構成的區域，其聯絡距離的總和最小值。
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define MAXK 11

const long INF=(long)1<<60;
long pos[MAXN];
long sum[MAXN];
long dis[MAXN][MAXN];
long dpn[MAXK][MAXN];

int main(){
  int caseT, N, K;

  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++)
      scanf("%ld",&pos[i]);
    sort(pos+1,pos+N+1);
    // 根據最左邊的端點視為原點，推算其他點的相對距離並累計前綴和
    for(int i=2;i<=N;i++)
      pos[i]-=pos[1],
      sum[i]=sum[i-1]+pos[i];
    //記得算完後將最左邊的點座標標記為原點
    pos[1]=0;

    // 枚舉端點，計算(L,R)區間內的曼哈頓距離(利用前綴和加快計算，避免用for迴圈算) => 26ms vs 0.4s
    for(int L=1;L<=N;L++)
      for(int M,R=L;R<=N;R++)
        M=L+R>>1,
        dis[L][R]=pos[M]*(M-L)-sum[M-1]+sum[L-1]+sum[R]-sum[M]-pos[M]*(R-M);

    // 動態規劃
    // 邊界設定
    for(int n=1;n<=N;n++)
      dpn[1][n]=dis[1][n];
    for(int k=2; k<=K; k++)
      for(int n=k; n<=N; n++){
        dpn[k][n]=INF;
        for(int i=k; i<=n; i++)
          dpn[k][n]=min(dpn[k][n],dpn[k-1][i-1]+dis[i][n]);
      }
    printf("%ld\n",dpn[K][N]);
  }
}
/*
1
5 3
-1 0 2 7 9
*/