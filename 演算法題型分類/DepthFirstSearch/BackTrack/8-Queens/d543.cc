/* 給定Ｎ代表Ｎ×Ｎ的棋盤放上Ｎ個皇后，彼此間不會互相攻擊的方法數？ 
 * 解題關鍵：ReCursion＋BitMask(狀態壓縮)
 * Ｎ最大＝15，需要避免用每次遞迴時 迴圈判斷目前位置的狀態是不是１
 * O(1)找到下一個１的位置＝BitMask
 * without bitmask | 9.4s
 * with    bitmask | 2.2s
 */
#include<bits/stdc++.h>
using namespace std;

int N;
int cnt[16]={};
void PutQueens(int row, int col, int negative, int positive){
  if(row==N){ cnt[N]++;  return; }
  /* Negative：Col＋Row 的範圍[   0, 2(N-1)] 
   * Positive：Col－Row 的範圍[ 1-N, N-1   ] 
   * 可以放置皇后的狀態＝３個狀態(col/negative/positive)做 AND 的位元運算 
   */
  int Nmask = negative>>row;        
  int Pmask = positive>>(N-1-row);
  int canPutQueen = col & Nmask & Pmask;
  /* O(1)找到下一個１的位置，避免用迴圈判斷目前位置的狀態是不是１
   * 下層遞迴的狀態＝目前找到的位置和"原來的狀態"做 XOR，negative 和 positive 的位置要"還原"＝反向 shift 
   */
  for(int yPut; canPutQueen; canPutQueen^=yPut){
    yPut=canPutQueen & (-canPutQueen);
    PutQueens(row+1, col^yPut, negative^(yPut<<row), positive^(yPut<<N-1-row) );
  }
}
int main(){
  for(N=1;N<16;N++)
    PutQueens(0, (1<<N)-1, (1<<(2*N-1))-1, (1<<(2*N-1))-1);
  while(scanf("%d\n",&N)!=EOF and N>0)
    printf("%d\n",cnt[N]);
}