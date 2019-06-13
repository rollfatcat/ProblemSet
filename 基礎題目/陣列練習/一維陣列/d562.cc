// 用getchar()和putchar()輸入優化( 0.5s => 85ms )
// 將陣列『來回』輸出

#include<bits/stdc++.h>
using namespace std;

inline bool scanShort(short &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
inline void prinShort(short x){
  if(x>=10) prinShort(x/10);
  putchar((x%10)+'0');
}
int main(){

  for(short Num[102],N; scanShort(N);){
    for(short i=0;i<N;i++)
      scanShort(Num[i]);
    for(short front=0,back=N-1; front<=back;){
      for(short i=front;i<=back;i++)
        prinShort(Num[i]), putchar(' ');
      puts("");
      front++;
      if(front>back)  break;
      for(short i=back;i>=front;i--)
        prinShort(Num[i]), putchar(' ');
      puts("");
      back--;
    }
  }
}