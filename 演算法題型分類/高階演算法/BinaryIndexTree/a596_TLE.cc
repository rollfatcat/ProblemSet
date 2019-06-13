// 初步的DP版本，但是直接吃TLE
/* 題目給了一個有趣的限制 : 0<=每疊高度<=30000
 * 因為有了這個限制可以利用 BIT 加速實現『查詢到目前為止有幾個數值比我小或是方法數的總和』
 * 概念類似 d788 的一邊插入資料一邊做排名查詢的方式(離線查詢)
 */
#include<bits/stdc++.h>
using namespace std;

const int maxN=1502;
const int mod=12345;
int N, num[maxN];
int DP[maxN][2];
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  while(scanInt(N)){
    // ---讀取輸入---
    for(int i=0;i<N;i++)
      scanInt(num[i]),  DP[i][0]=DP[i][1]=0;
    // ---判斷是升還是降的個數---
    // DP[x][0]:從頭到現在位置x之間，兩個數字間的關係是升的個數
    // DP[x][1]:從頭到現在位置x之間，兩個數字間的關係是降的個數
    for(int i=1;i<N;i++)
      for(int j=0;j<i;j++){
        if(num[i]>num[j]) DP[i][0]++;
        if(num[i]<num[j]) DP[i][1]++;
      }
    // --- ---
    int ans=0;
    for(int i=1;i<N;i++){
      ans-=(DP[i][0]+DP[i][1]);
      for(int j=0;j<i;j++){
        if(num[i]>num[j]) DP[i][0]=(DP[i][0]+DP[j][1])%mod;
        if(num[i]<num[j]) DP[i][1]=(DP[i][1]+DP[j][0])%mod;
      }
      ans=(ans+DP[i][0]+DP[i][1])%mod;
    }
    printf("%d\n",ans);
  }
}