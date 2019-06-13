// 原作法需求是實作大數除法，但觀察測資範圍：10^30可以發現落在__int128以內
// 換句話說，只需要支援 __int128讀取數字和輸出數字即可。

#include<bits/stdc++.h>
using namespace std;

inline void scanNum(__int128 &x){
  char c;
  while((c=getchar())<'0' or c>'9');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
}
inline void prinNum(__int128 &x){
  int L=0;
  char ss[40];
  for(; x; x/=10)
    ss[L++]=x%10+'0';
  for(L--; L>=0;L--)
    putchar(ss[L]);
}
int main(){
  int caseT;
  scanf("%d",&caseT);
  while(caseT--){
    __int128 A, B, G;
    scanNum(A);
    scanNum(B);
    G=__gcd(A,B);
    A/=G, B/=G;
    prinNum(A), printf(" / ");
    prinNum(B), puts("");
  }
}