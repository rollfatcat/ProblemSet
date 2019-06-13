// 大數加法的基本題型(getchar()讀取字元，單bit相加和進位)
#include<bits/stdc++.h>
using namespace std;

const int maxL=1e6+2;
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int N, L;
  char num[2][maxL];
  for(scanInt(N); N--;){
    getchar(),scanInt(L);
    num[0][L]=num[1][L]='\n';
    for(int i=L-1;i>=0;i--)
      num[0][i]=getchar()-'0', getchar(),
      num[1][i]=getchar()-'0', getchar();
    short carry=0, digit;
    for(int i=0;i<L;i++)
      num[0][i]=num[0][i]+num[1][i]+carry,
      carry=num[0][i]/10,
      num[0][i]%=10;
    if(carry) putchar(carry+'0');
    for(int i=L-1;i>=0;i--)
      putchar(num[0][i]+'0');
    puts("");
  }
}