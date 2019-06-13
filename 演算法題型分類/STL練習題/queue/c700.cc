// 使用兩個Stack實作Queue
#include<bits/stdc++.h>
using namespace std;

int main(){
  char ss[10];
  unsigned int X, S1=0, S2=0;

  while(scanf("%s",ss)!=EOF){
    if(ss[1]=='u') //Push X
      scanf("%u",&X), S1++,
      putchar('1');
    else{ //Pop
      if(S2)
        S2--, putchar('4');
      else{
        while(S1)
          putchar('5'), S1--, S2++;
        if(S2)
          S2--, putchar('4');
      }
    }
  }
  puts("");
}