// 邏輯推論題，優化輸入輸出後100ms=>8ms
#include<iostream>
using namespace std;

bool scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); return c!=EOF; }
void prinInt(int x){
  int i;
  char ss[20];
  for(i=0; x; i++,x/=10)
    ss[i]=x%10+'0';
  while(i--) putchar(ss[i]);
  puts("");
}
int main(){
  for(int N,M; scanInt(N) and scanInt(M);)
    prinInt((N==M)?M:(M+1));
}