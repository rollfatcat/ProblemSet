/* 加速讀取(只能用getchar_unlocked)
 * 位元運算函式
 */
#include<bits/stdc++.h>
using namespace std;

inline bool scanInt(int &x){char c;for(x=0;(c=getchar_unlocked())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  int x;
  while(scanInt(x))
    puts( (x==1<<__lg(x))?"Yes":"No" );
}