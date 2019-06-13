// 題目要求：將十進位轉為『費波那契數列』進位法
// 完成後可以嘗試 d666-UVa763 : 先將兩把輸入轉成十進位加總後再轉回費波那契進位
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e8;
int main(){
  int FIB_num;
  int FIB[40]={1,2}; // FIB[38]=102334155
  for(FIB_num=1;FIB[FIB_num]<=MAXN;FIB_num++)
    FIB[FIB_num+1]=FIB[FIB_num]+FIB[FIB_num-1];
  int caseN;
  scanf("%d",&caseN);
  for(int number;caseN--;){
    scanf("%d",&number);
    int pos=upper_bound(FIB,FIB+FIB_num,number)-FIB-1;
    printf("%d = ",number);
    for(int i=pos;i>=0;i--)
      if(number>=FIB[i]){
        putchar('1'),
        number-=FIB[i];
      }else
        putchar('0');
    puts(" (fib)");
  }
}