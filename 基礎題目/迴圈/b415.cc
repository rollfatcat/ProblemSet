// 練習使用 getchar() 和 putchar() 處理輸入和輸出( =>非必須 )
// 談到 __int128 和 大數處理
// 談到 long long int 和 int 的關係

#include<cstdio>
using namespace std;

inline bool scanLong(long &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); return c!=EOF; }
inline void printInt(long &x){
  char ss[20];
  if(x==0){ putchar('0'); return; }
  int i=0;
  for(int num=x; num; i++,num/=10) ss[i]=num%10+'0';
  while(i--)  putchar(ss[i]);
}
int main(){
  for(long x0,n,m; scanLong(x0) and scanLong(n) and scanLong(m); ){
    for(printInt(x0),m--; m--;)
      x0=(x0*x0)%n,
      putchar(' '),
      printInt(x0);
    puts("");
  }
}