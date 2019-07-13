#include<bits/stdc++.h>
using namespace std;

inline bool scanInt(unsigned int &x){
  char c;
  for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  return c!=EOF;
}
inline bool prinInt(unsigned int x){
  int len=0;
  char ss[40];
  for(len=0;x>0;x/=10)
    ss[len++]=x%10+'0';
  while(len--)
    putchar(ss[len]);
  putchar('\n');
}
int main(){
  unsigned int A, B;
  while(scanInt(A) and scanInt(B))
    prinInt(A+B);
  prinInt(A+B); // 最後一筆會跳開迴圈，但仍要計算結果
}