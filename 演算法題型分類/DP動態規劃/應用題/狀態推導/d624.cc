// 標準DP解
/* DP[最多連續n個暗燈][總長度m個燈][目前已經持續k個暗燈]
 * 狀態轉移：每次都有兩種選擇，後續接一個燈(暗或亮)
 * 選擇亮燈：DP[n][i][0]=DP[n][i-1][0]+DP[n][i-1][1]+...+DP[n][i-1][bound]
 * 選擇暗燈：DP[n][i][j]=DP[n][i-1][j-1]
 */
#include<iostream>
using namespace std;

unsigned long DP[16][92][16]={}; // 題目保證不需要大數計算，所有資料都會在(2^64)-1以內
bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  // 初始化計算
  for(int bound=1; bound<=15;bound++){
    DP[bound][1][0]=DP[bound][1][1]=1;
    for(int i=2;i<=90;i++){
      for(int j=0;j<bound;j++)
        DP[bound][i][j+1]=DP[bound][i-1][j],
        DP[bound][i][0]+=DP[bound][i-1][j];
      DP[bound][i][0]+=DP[bound][i-1][bound];
    }
    for(int j=0;j<=bound;j++)
      DP[bound][91][0]+=DP[bound][90][j];
  }
  for(int bound,N; scanInt(bound) and scanInt(N);)
    printf("%lu\n",DP[bound][N+1][0]);
}
