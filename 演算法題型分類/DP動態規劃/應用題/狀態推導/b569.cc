// 這題與DP無關，但是題目需要透過觀察
/* 第一次看以為是水題，只要計算現在狀態和初始狀態之間經過了t秒，再推出t+1秒即可
 * 但其實輸入範圍：每一行長度不超過10000000，時間 t 是無法被有效計算出來的
 * 觀察【進位】的情況：只有當現在狀態和初始狀態的字元(同個位置)不一樣且這個位置前面也都得不同時
 * 把這個位置的字元設定回【初始狀態】直到相同時再把這個位置的字元設定成不一樣即可
 */
#include<bits/stdc++.h>
using namespace std;

char orgS[10000002], preS[10000002];
int main(){
  scanf("%s %s",orgS,preS);
  int i;
  for(i=0; preS[i]!='\0' and orgS[i]!=preS[i]; i++)
    preS[i]=orgS[i];
  if(i<strlen(preS))
    preS[i]=('1'-preS[i])+'0';
  puts(preS);
}