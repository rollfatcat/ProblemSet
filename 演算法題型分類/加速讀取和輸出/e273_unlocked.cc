// 利用 getchar_unlocked() / putchar_unlocked()
#include<bits/stdc++.h>
using namespace std;

// getchar_unlocked()
inline bool scanInt(int &x){char c;for(x=0;(c=getchar_unlocked())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}

int len;
// 利用putchar_unlocked()實現加速輸出
inline void printInt(int x,int base=10){
  while(base<=x) base*=10;
  while(base>1)  base/=10,putchar_unlocked(x/base+'0'),x%=base;
  putchar_unlocked(' ');
}

int main(){
  int n, x;
  while(scanInt(n)){
    len=0;
    for(int i=1;i<n;i++)
      scanInt(x),
      printInt(x*(n-i));
    scanInt(x);
    // 當只有一項時作微分應該要印出0，多於一項時則不需要輸出這個0
    if(n==1){ puts("0"); continue; }
    putchar_unlocked('\n');
  }
}