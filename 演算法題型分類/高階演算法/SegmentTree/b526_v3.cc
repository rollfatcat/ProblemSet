// 題目做法類似TIOJ-1819，只是要輸出端點之間的個數(差距)
/* Set解法(0.1s，但較為直覺)：端點的格式是左閉右開[qL,qR)，
 * 線段連續的判斷方式是後者的左端點和前者的右端點『重複』
 */
#include<bits/stdc++.h>
using namespace std;

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int Q, N, qL, qR;

  scanInt(N), scanInt(Q);
  set<int> ST;
  for(int i=0;i<Q;i++){
    scanInt(qL), scanInt(qR);
    if(qL>qR) qL^=qR^=qL^=qR;
    qR++;
    if(ST.count(qL)) ST.erase(qL); else ST.insert(qL);
    if(ST.count(qR)) ST.erase(qR); else ST.insert(qR);
  }
  int preS=1, t=0;
  int sum=N-*(--ST.end())+1;
  for(auto c:ST){
    if(~t&1)
      sum+=c-preS;
    preS=c, t^=1;
  }
  printf("%d\n",sum);
}
/*
10 5
2 8
3 4
5 7
6 9
1 4
===
4
*/