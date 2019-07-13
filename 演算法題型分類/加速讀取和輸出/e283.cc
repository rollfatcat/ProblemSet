#include<bits/stdc++.h>
using namespace std;

inline bool scanInt(unsigned int &x){
  char c;
  for(x=0;(c=getchar_unlocked())>='0' and  c<='9';x=(x<<3)+(x<<1)+c-'0');
  return c!=EOF;
}
char buff[1<<4];
int main(){
  /* A  -> 0 1 0 1 = 5
     B  -> 0 1 1 1 = 7
     C  -> 0 0 1 0 = 2
     D  -> 1 1 0 1 = 13
     E  -> 1 0 0 0 = 8
     F  -> 1 1 0 0 = 12 */
  string memo="  C  A BE   FD";

  unsigned int N;
  while(scanInt(N)){
    for(int i=0;i<N;i++){
      fgets(buff,sizeof(buff),stdin);
      int pos=((buff[0]-'0')<<3)|((buff[2]-'0')<<2)|((buff[4]-'0')<<1)|(buff[6]-'0');
      putchar_unlocked(memo[pos]);
    }
    putchar_unlocked('\n');
  }
}