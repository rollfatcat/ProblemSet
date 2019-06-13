#include<iostream>
#include<cstring>
using namespace std;

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){

  int ans[4], gue, n;
  int cnt[2][10];

  while(scanInt(ans[0])){
    scanInt(ans[1]),
    scanInt(ans[2]),
    scanInt(ans[3]),
    scanInt(n);
    while(n--){
      int A=0, B=0;
      memset(cnt,0,sizeof(cnt));
      for(int i=0;i<4;i++){
        scanInt(gue);
        if(gue==ans[i]) A++;
        else  cnt[0][gue]++, cnt[1][ans[i]]++;
      }
      for(int i=0;i<=9;i++)
        B+=min(cnt[0][i],cnt[1][i]);
      printf("%dA%dB\n",A,B);
    }
  }
}