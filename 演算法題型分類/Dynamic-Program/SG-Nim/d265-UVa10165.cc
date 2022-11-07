// Nim 的經典題，解法屬於數論
// 說明：http://episte.math.ntu.edu.tw/articles/mm/mm_03_2_02/index.html
/* 將每列的石頭做二進位化，對每個位數相加，只要每個位數的和都是偶數就是安全局面
 * 利用 XOR 判斷每個位數都是偶數
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, x;
  while(scanf("%d",&N) and N){
    int nowS=0;
    while(N--)
      scanf("%d",&x),
      nowS^=x;
    puts((nowS)?"Yes":"No");
  }
}