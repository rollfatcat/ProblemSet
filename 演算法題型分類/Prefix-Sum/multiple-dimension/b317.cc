/* 給定Ｎ個魔法陣的半徑Ｒ和高度Ｈ，輸出至少覆蓋Ｋ個魔法陣的體積(2R*2R*H)？
 * 解題關鍵：動態規劃 - 狀態轉移 = 二維前綴和
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxR=1e2;
int dp[101][101]={};
int main(){
  int N, K, R, H;
  
  scanf("%d %d",&N,&K);
  while(N-->0){
  	scanf("%d %d",&R,&H);
    dp[R][H]+=1;
  }
  //
  for(H=1; H<=100; H++)
    dp[0][H]+=dp[0][H-1];
  for(R=1; R<=100; R++)
    dp[R][0]+=dp[R-1][0];
  for(R=1; R<=100; R++)
    for(H=1; H<=100; H++)
      dp[R][H]+= dp[R-1][H]+dp[R][H-1]-dp[R-1][H-1];
  int ans=1<<30;
  for(R=0; R<=100; R++){
    for(H=0; H<=100 and dp[R][H]<K; H++);
    if(H<=100)
      ans=min(ans,(R*R*H)<<2);
  }
  printf("%d",ans);
}