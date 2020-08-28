/* 輸出第１５００個 UglyNumber？
 * UglyNumber的定義：該數字的質因數只包含２、３、５
 * 解題關鍵：狀態展開
 * 從１開始展開，分支展開＝該數字乘以２、３、５形成，每次取分支當中數字最小的展開。
 * 因為數列是共通的，利用３個變數各自代表某次狀態展開後２、３、５的值從中取最小值作為下次加入數列的值
 * 因為２、３、５的間距和乘法的關係只需要判斷一次(不需要利用迴圈逼近)
 *
 * 強化版：f250
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1500;
int num[MaxN+1]={0,1};

int main(){
  int p2=1, p3=1, p5=1;
  for(int idx=2; idx<=MaxN; idx++){
    p2+= 2*num[p2]<=num[idx-1];
    p3+= 3*num[p3]<=num[idx-1];
    p5+= 5*num[p5]<=num[idx-1];
    num[idx]=min( min(2*num[p2],3*num[p3]),5*num[p5] );
  }
  printf("The 1500'th ugly number is %d.\n",num[MaxN]);
}
//859963392