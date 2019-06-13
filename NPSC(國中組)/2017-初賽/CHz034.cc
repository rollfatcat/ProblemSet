// 只有8是兩個圓，4是只有一個圓時最小的數字(0除外)
// 特殊例外：當輸入的長度是1時才能以0開頭，其餘長度時開頭不可為0

#include<iostream>
using namespace std;

int main(){
  int L;
  while(scanf("%d",&L)!=EOF){
    if(L==1){ puts("0"); continue; }
    if(L&1) putchar('4');
    for(L>>=1;L;L--) putchar('8');
    putchar('\n');
  }
}