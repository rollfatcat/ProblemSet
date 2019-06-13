// 二元一次方程式解題，且題目要求是整數解
#include<bits/stdc++.h>
using namespace std;

inline bool scanLong(long &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  for(long S1,S2,T,K; scanLong(S1); ){ // 題目保證：S1<S2
    scanLong(S2),
    scanLong(T),
    scanLong(K);
    int GCD=__gcd(S1,S2);
    if(T%GCD){ puts("impossible"); continue; }

    S2-=S1,
    T-=S1*K;
    if(T<=0 or T%S2){ puts("impossible"); continue; }
    int N2=T/S2, N1=K-N2;
    if(N1<=0){ puts("impossible"); continue; }
    printf("%d %d\n",N1,N2);
  }
}