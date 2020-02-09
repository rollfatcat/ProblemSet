// 題解：https://codeofdouble.blogspot.com/2018/12/tioj1819.html
/* Set解法：端點的格式是左閉右開[qL,qR)，
 * 線段連續的判斷方式是後者的左端點和前者的右端點『重復』
 * 端點的個數一半『剛好』是線段著色區間
 */
#include<bits/stdc++.h>
using namespace std;

inline void scanInt(int &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
}
int main(){
  int Q, N, qL, qR;

  scanInt(Q), scanInt(N);
  set<int> ST;
  int ans=0;
  for(int i=0;i<Q;i++){
    scanInt(qL), scanInt(qR);
    if(qL>qR) qL^=qR^=qL^=qR;
    qR++;
    if(ST.count(qL)) ST.erase(qL); else ST.insert(qL);
    if(ST.count(qR)) ST.erase(qR); else ST.insert(qR);
    ans=max(ans,(int)(ST.size())>>1);
  }
  printf("%d\n",ans);
}
/*
5 10
2 8
3 4
5 7
6 9
1 4
*/