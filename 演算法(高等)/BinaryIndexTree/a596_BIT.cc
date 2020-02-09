// 先完成TLE的版本，推導出DP的遞迴，這邊把數據紀錄改為BIT方式
// DP+BIT版本 TLE(大約只能執行50筆) → 0.1s
// 題解：http://mypaper.pchome.com.tw/zerojudge/post/1323804669
#include<bits/stdc++.h>
using namespace std;

const int maxN=1502;
const int mod=12345;
const int maxH=30002;
int N, num[maxN];
int DP[maxN][2];
int BIT[2][maxH];
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
inline int lowbit(int x){ return x&-x; }
void Update(int idx,int d,int Tree[]){ // ---標準BIT區間更新---
  while(idx<maxH)
    Tree[idx]=(Tree[idx]+d)%mod, idx+=lowbit(idx);
}
int Query(int idx,int Tree[]){ // ---標準BIT區間查詢---
  int sum=0;
  while(idx)
    sum+=Tree[idx], idx-=lowbit(idx);
  return sum%mod;
}
int main(){
  while(scanInt(N)){
    // ---讀取輸入---
    for(int i=0;i<N;i++)
      scanInt(num[i]), num[i]++, //高度+1是因為BIT用到的記憶體空間從 1 開始計算
      DP[i][0]=DP[i][1]=0;
    // 把數據的儲存結構改為BIT -- BIT[x]:代表從0到(x-1)之間個數的總和(用Update查詢時)
    // DP的成本：1500*1499/2(1124250) → 1500*㏒30000(22500)
    memset(BIT[0],0,sizeof(BIT[0]));
    for(int i=0;i<N;i++){
      DP[i][0]=Query(num[i]-1,BIT[0]); //目前全部有 i 個數字，區間查詢比自己小的全部總數
      DP[i][1]=i-Query(num[i],BIT[0]); //目前全部有 i 個數字，區間查詢比自己大的全部總數(全部扣除小於等於自己的部分)
      Update(num[i],1,BIT[0]);
    }
    // ---計算時注意減法時取餘數的會出現負數的情況---
    memset(BIT,0,sizeof(BIT));
    int ans=0;
    for(int i=0;i<N;i++){
      ans=(mod+ans-DP[i][0]-DP[i][1])%mod;
      // ---換成BIT的方式---
      /* BIT[x][0]：到目前上升的方法數總和
       * BIT[x][1]：到目前下降的方法數總和
       */
      DP[i][0]=( DP[i][0]+Query(num[i]-1,BIT[1]) )%mod;
      DP[i][1]=( mod+DP[i][1]+Query(30001,BIT[0])-Query(num[i],BIT[0]) )%mod;
      Update(num[i],DP[i][0],BIT[0]);
      Update(num[i],DP[i][1],BIT[1]);
      ans=(ans+DP[i][0]+DP[i][1])%mod;
    }
    printf("%d\n",ans);
  }
}