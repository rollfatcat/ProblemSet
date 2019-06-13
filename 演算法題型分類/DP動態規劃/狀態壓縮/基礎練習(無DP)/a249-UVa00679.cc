// 題解：http://glennchen1.blogspot.com/2009/02/q679-dropping-balls.html
/* binary的規律觀察：
   假設 depth=4, times可能 1~8 但會減1 就是 0~7
    times   binary system  position
                    位數
      0      1000 + 000     8+0
      1      1000 + 100     8+4
      2      1000 + 010     8+2
      3      1000 + 110     8+6
      4      1000 + 001     8+1
      5      1000 + 101     8+5
      6      1000 + 011     8+3
      7      1000 + 111     8+7
 */
#include<bits/stdc++.h>
using namespace std;

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
inline int lower_bit(int x){ return x&-x; }
int main(){
  int N, depth, times;
  for(scanInt(N); N--;){
    scanInt(depth), depth--;
    scanInt(times), times--;
    int base=1<<depth;
    // times的數量超過base時會循環，取mod----------
    for(times%=base;times;times-=lower_bit(times))
      base+=1<<(depth-__builtin_ffs(times));
    printf("%d\n",base);
  }
}