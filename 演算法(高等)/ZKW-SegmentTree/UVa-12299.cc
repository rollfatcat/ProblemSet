// 題目保證：Each operation is formatted as a string having no more than 30 characters
// 可以將 shift 每個點的操作視為單點更新(數量不多)
#include<bits/stdc++.h>
using namespace std;

const int INF=1<<30;
const int MAXN=1e5+1;
const int MAXS=(1<<(__lg(MAXN)+1)|1)<<1;
int N, Q, M;
int zkw[MAXS];

inline void scanInt(int &x){ char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); }
int main(){
  scanInt(N),
  scanInt(Q);
  M=1<<(__lg(N)+1);
  for(int i=1;i<=N;i++)
    scanInt(zkw[M+i]);
  // ---補齊其他子葉，避免找最小值出錯---
  zkw[0]=INF;
  for(int i=N+M+1;i<(M<<1);i++)
    zkw[i]=INF;
  // ---建樹---
  for(int i=M-1;i;i--)
    zkw[i]=min(zkw[i<<1],zkw[i<<1|1]);
  // ---處理操作，麻煩在讀取字串判斷shift的數字---
  for(int qL,qR,x; Q--;){
    int num[20], len=0;
    char cmd=getchar();
    for(char c=getchar(); c!=')';){
      while((c=getchar())<'0' or c>'9');
      for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
      num[len++]=x;
    }
    getchar();
    if(cmd=='q'){
      int minv=INF;
      for(qL=num[0]+M-1,qR=num[1]+M+1; qL^qR^1; qL>>=1,qR>>=1){
        if(~qL&1) minv=min(minv,zkw[qL^1]);
        if( qR&1) minv=min(minv,zkw[qR^1]);
      }
      printf("%d\n",minv);
    }else{
      int rec=zkw[num[0]+M];
      // --- 單點更新---
      for(int idx=1;idx<len;idx++){
        zkw[ num[idx-1]+M ]=zkw[ num[idx]+M ];
        for(int i=(num[idx-1]+M)>>1;i;i>>=1)
          zkw[i]=min(zkw[i<<1],zkw[i<<1|1]);
      }
      zkw[ num[len-1]+M ]=rec;
      for(int i=(num[len-1]+M)>>1;i;i>>=1)
        zkw[i]=min(zkw[i<<1],zkw[i<<1|1]);
    }
  }
}
/*
7 5
6 2 4 8 5 1 4
query(3,7)
shift(2,4,5,7)
query(1,4)
shift(1,2)
query(2,2)
*/