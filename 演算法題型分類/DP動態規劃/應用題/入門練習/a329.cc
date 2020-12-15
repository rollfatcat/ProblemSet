/* 給定Ｎ個城市(編號１-Ｎ)和每座城市可以聯通其他城市的編號，輸出從１號城市出發抵達Ｎ號城市的方法數？
 * 解題關鍵：這些城市能到達的城市編號都大於本身城市編號(抵達某一城市的路徑可以存在複數條)
 * 解題關鍵：DynamicProgramming-BottomUp
 * state definition: dpv[x] 抵達城市 x 時的方法數
 * state transition: dpv[x]＝Σ dpv[y] ，加總所有和 x 直接聯通的城市 y。 
 * 處理更新時由編號小到大的城市。
 */
#include<bits/stdc++.h>
using namespace std;
const int MaxN=1e5;
const int MaxM=1e4;
const int MaxSumM=5e6;
const int MOD=1234567;

int dpv[MaxN+1]={0,1};
int main(){
  int N, M, v;
  scanf("%d\n",&N);
  for(int u=1; u<=N; u++){
    scanf("%d",&M);
    while(M-->0){
      scanf("%d",&v);
      dpv[v]=(dpv[v]+dpv[u])%MOD;
    }
  }
  printf("%d\n",dpv[N]);
}