// 題解：https://github.com/morris821028/UVa/blob/master/volume121/12192%20-%20Grapevine.cpp
/* N為該矩形範圍的高，M為長，並輸入該範圍內每個數字，Q代表要測試幾次，每次給定L,U，
 * 在範圍內求最大正方形的邊長，該正方形內的數字都要符合L ≤ H[i][j] ≤ U，也就是介於L和U之間
 * 0 ≤ H[i][j] ≤ 10^5, H[i−1][j] ≤ H[i][j] and H[i][j−1] ≤ H[i][j](非嚴格遞增)
 * 解題關鍵：因為呈現非嚴格遞增，二分法找對角線即可
 * 儲存存地圖數值時將儲存的位置轉45度
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=501;
int R, C;
int didx[MAXN<<1]; // 每條方程式的個數長度
int diag[MAXN<<1][MAXN];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){

  while(scanInt(R) and scanInt(C) and R){
    memset(didx,0,sizeof(didx));
    int slash;         // 當斜率的常數: slash=x-y，範圍調整(-C,R)=>(0,C+R)
    // 本來是存在ＲxＣ的長方形，改為轉45度的存法
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        slash=i-j+C,
        scanInt(diag[slash][didx[slash]++]);

    int Q, L, U;
    scanInt(Q);
    while(Q--){
      scanInt(L),
      scanInt(U);
      int maxL=0, nL, nR;
      for(int i=0;i<R+C and did[x]>maxL;i++)
        nL=lower_bound(diag[i],diag[i]+didx[i],L)-diag[i],
        nR=upper_bound(diag[i],diag[i]+didx[i],U)-diag[i],
        maxL=max(maxL,nR-nL);
      printf("%d\n",maxL);
    }
    puts("-");
  }
}