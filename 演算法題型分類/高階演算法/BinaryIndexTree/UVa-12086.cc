// 單點修改和區間和查詢 => BIT(0.05s)
#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+1;
int org[MAXN]={}; // 保留原始數據方便做單點修改
int BIT[MAXN]={};
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
inline int lowbit(int x){ return -x&x; }
int main(){
  int N, M, qL, qR;
  for(int caseN=0;scanInt(N) and N;){
    if(caseN) puts("");
    printf("Case %d:\n",++caseN);

    for(int i=1;i<=N;i++)
      scanInt(org[i]), BIT[i]=org[i];
    // ---建樹---
    for(int uppos,i=1;i<=N;i++)
      if( (uppos=i+lowbit(i))<=N )
        BIT[uppos]+=BIT[i];
    // ---讀取操作---
    char cmd;
    for(cmd=getchar(),getchar();cmd!='E';cmd=getchar(),getchar()){
      scanInt(qL),
      scanInt(qR);
      if(cmd=='M'){ // 區間和查詢
        int presum=0, suffsum=0;
        for(qL--;qL;qL-=lowbit(qL))
          presum+=BIT[qL];
        for(;qR;qR-=lowbit(qR))
          suffsum+=BIT[qR];
        printf("%d\n",suffsum-presum);
      }else{ // cmd=='S'，單點更新
        int new_num=qR;
        qR=qR-org[qL];
        org[qL]=new_num;
        for(int i=qL;i<=N;i+=lowbit(i))
          BIT[i]+=qR;
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