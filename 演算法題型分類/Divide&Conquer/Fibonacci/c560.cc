/* 題目要求每次可以跨一階或是三階 → F(n)=F(n-1)+F(n-3) → Ｎ不大，Linear Bottom-Up
 * 但是必須到達指定的休息站 → 根據指定位置，分區段找出方法數後累乘
 */
#include<bits/stdc++.h>
using namespace std;

const long MOD=1000000007;
const int MAXN=100001;
int DP[MAXN]={1,1,1};
int main(){
  for(int i=3;i<MAXN;i++)
    DP[i]=(DP[i-1]+DP[i-3])%MOD;
  int N, M;
  scanf("%d %d",&N,&M);
  int now, pre=0;
  long way=1;
  for(int i=0;i<M;i++){
    scanf("%d",&now);
    way=way*DP[now-pre]%MOD;
    pre=now;
  }
  way=way*DP[N-pre]%MOD;
  printf("%ld\n",way);
}