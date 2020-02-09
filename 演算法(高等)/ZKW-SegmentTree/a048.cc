// zkw式線段樹版本，這題不會比線段樹快是因為不需先建樹
#include<bits/stdc++.h>
using namespace std;

const int MAXN=200000; //__lg(MAXN)=17
bool zkw_tr[MAXN<<2];
void scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); }
int main(){
  int N, Q, qL, qR;
  scanInt(N),
  scanInt(Q);
  for(int act,ans,M=1<<(__lg(N)+1); Q--;){
    scanInt(act),
    scanInt(qL);
    if(act==1){ //單點修改
      for(qL+=M; qL; qL>>=1)
        zkw_tr[qL]^=true;
    }else{ //區間查詢
      scanInt(qR);
      // 只對區間內的值做 XOR ，類似Summation但不需要考慮 lazy_update
      for(ans=false,qL+=M-1,qR+=M+1; qL^qR^1; qL>>=1,qR>>=1){
        if(~qL&1)ans^=zkw_tr[qL^1];
        if(qR&1) ans^=zkw_tr[qR^1];
      }
      printf("%d\n",ans);
    }
  }
}