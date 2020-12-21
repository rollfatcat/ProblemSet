// 動態規劃：每個莊園只有兩個時間點可以取走，這兩個時間點取最小的，但從整體取最大的
#include<bits/stdc++.h>
using namespace std;

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){

  int caseT, N, x, t, forward, back;
  scanInt(caseT);
  while(caseT--){
    scanInt(N);
    t=0;
    for(int i=0;i<N;i++)
      scanInt(x),
      forward=max(x,i)+N-1-i+(N-1), // 順向時取走
      back=max(x,N-1+(N-1)-i)+i,    // 反向時取走
      t=max(t,min(forward,back));
    // 不知道找到的答案怎麼推出來的：t=max(t,x+i)
    printf("%d\n",t);
  }
}