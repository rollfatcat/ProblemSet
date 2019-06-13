// 狀態壓縮＋Nim
/* 從最終盤面，慢慢推回到原始盤面，原本輸的盤面，推回去會變成贏的盤面，
 * 然而先手有利，只限定在百分之百獲勝，也就是說有一個會輸，就是先手不利，因此用一個 or 去做運算
 */
#include<bits/stdc++.h>
using namespace std;

bool DP[1<<13]={}; // 0 is win, 1 is unsure
int main(){
  int Link[13][7]={ {2,3,-1},
                    {2,5,-1},
                    {0,1,3,5,6,-1},
                    {0,2,4,6,7,-1},
                    {3,7,-1},
                    {1,2,6,8,9,-1},
                    {2,3,5,7,9,10,-1},
                    {3,4,6,10,11,-1},
                    {5,9,-1},
                    {5,6,8,10,12,-1},
                    {6,7,9,11,12,-1},
                    {7,10,-1},
                    {9,10,-1}};
  // 預跑，從最終盤面回推：只需考慮拿走一顆棋或兩顆(相連的)棋子
  for(int nowS=1;nowS<(1<<13);nowS++){
    // 放置一顆棋後的盤面(當該棋子至少需不存在目前的盤面時才能放往外推導狀態)
    for(int i=0;i<13;i++){
      int chessS=(1<<i);
      if( ( nowS&chessS )==0 )
        DP[ nowS|chessS ] |= !DP[nowS];
    }
    // 放置兩顆相連的棋子(當該棋子至少需不存在目前的盤面時才能往外推導狀態)
    for(int i=0;i<13;i++)
      for(int j=0;Link[i][j]>=0;j++){
        int chessS=(1<<i)|(1<<Link[i][j]);
        if( ( nowS&chessS )==0 )
          DP[ nowS|chessS ] |= !DP[nowS];
      }
  }
  //
  for(int caseN;scanf("%d",&caseN)!=EOF;puts(""))
    for(int nowS;caseN--;)
      scanf("%d",&nowS),
      printf("%d ",DP[nowS]);
}