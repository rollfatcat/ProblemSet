// 練習迴圈
// 數學解：加總每個位數＝除以9的餘數
#include<bits/stdc++.h>
using namespace std;

int SumDigit(int x,int sum=0){
  if(x<10) return x;
  for(; x; sum+=x%10,x/=10);
  return SumDigit(sum);
}
char ss[9]={'9','1','2','3','4','5','6','7','8'};
int main(){
  int N;
  while(scanf("%d",&N) and N)
    putchar(ss[N%9]),
    putchar('\n');
}