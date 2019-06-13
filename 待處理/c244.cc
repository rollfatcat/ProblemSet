#include<bits/stdc++.h>
using namespace std;

inline void scanLong(unsigned long &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){

  unsigned long caseT, W, w1, v1, w2, v2;
  scanLong(caseT);
  for(int caseN=1;caseN<=caseT;caseN++){
    scanLong(W);
    scanLong(w1);
    scanLong(v1);
    scanLong(w2);
    scanLong(v2);
    if(v1*w2<v2*w1)
      swap(w1,w2),
      swap(v1,v2);
    unsigned long LCM=w1*w2/__gcd(w1,w2),
                  base=W/LCM*w2;
    W%=LCM;
    unsigned long maxv=W/w1*v1+(W%w1)/w2*v2,
                  tmpv=(W/w1-1)*v1+(W%w1+w1)/w2*v2;
    for(int i=W/w1-2;i>=0;i--)
      maxv=max(maxv,tmpv),
      tmpv=i*v1+(W-w1*i)/w2*v2;
    printf("Case #%d: %lu\n",caseN,maxv+base*v1);
  }
}
/*
10 3 30 2 19
215853842 444 11680552 317 7893115
==
5678582755146(答案)

5678582755146 = 11680552*1533*317
2290024674 = 11680552*486153 + 7893115*6
*/