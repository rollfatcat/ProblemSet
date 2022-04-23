/* 對初學者來說難度算高，練習完費波那契數列後的題目(搭配c039-UVa00100一起看)
 * 練習動態規劃的函數和推算輸入值的範圍(學習偵錯)
 */
#include<bits/stdc++.h>
using namespace std;

int recF[90001]={};
int recH[90001]={};

inline int func_Z(int n){ return(n<=2)?(n*n-1):2; }
inline int func_H(int n){
  if(n<2) return -1;
  return (recH[n]==0)?recH[n]=2+func_H(n-1)-func_H(n-2) : recH[n];
}
int func_F(int n){
  // 只有當 n>=0 時才會記錄到陣列中
  if(n>=0 and recF[n]!=0) return recF[n];

  int num=0;
  if(n>func_H(n)) num=func_F(n-1)-func_H(n);
  else if(n<func_H(n)) num=func_F(func_Z(n))-func_Z(n);
  else num=1;

  if(n>=0)  recF[n]=num;
  return num;
}

int main(){
  for(int N;scanf("%d",&N)!=EOF;)
    printf("%d\n",func_F(N));
}