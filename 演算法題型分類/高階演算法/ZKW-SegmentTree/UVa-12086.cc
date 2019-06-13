// 單點修改和區間和查詢 => zkw(0.07s)
#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+1;
int zkw[MAXN<<2];
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
inline int lowbit(int x){ return -x&x; }
int main(){
  int N, M, qL, qR;
  for(int caseN=0;scanInt(N) and N;){
    if(caseN) puts("");
    printf("Case %d:\n",++caseN);

    memset(zkw,0,sizeof(zkw));
    M=1<<(__lg(N)+1);
    for(int i=1;i<=N;i++)
      scanInt(zkw[M+i]);
    // ---建樹---
    for(int i=M-1;i;i--)
      zkw[i]=zkw[i<<1]+zkw[i<<1|1];
    // ---讀取操作---
    char cmd;
    for(cmd=getchar(),getchar();cmd!='E';cmd=getchar(),getchar()){
      scanInt(qL),
      scanInt(qR);
      if(cmd=='M'){ // 區間和查詢
        int sum=0;
        for(qL+=M-1,qR+=M+1;qL^qR^1;qL>>=1,qR>>=1){
          if(~qL&1) sum+=zkw[qL^1];
          if( qR&1) sum+=zkw[qR^1];
        }
        printf("%d\n",sum);
      }else{ // cmd=='S'，單點更新
        zkw[M+qL]=qR;
        for(int i=M+qL;i>1;i>>=1)
          zkw[i>>1]=zkw[i]+zkw[i^1];
      }
    }
    getchar(),
    getchar();
  }
}
/*
3
100
100
100
M 1 1
M 1 3
S 2 200
M 1 2
S 3 0
M 2 3
END
10
1
2
3
4
5
6
7
8
9
10
M 1 10
END
0
*/