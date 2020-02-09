// 二維樹狀數組(裸題)
// 單點修改＋區間總和查詢，實作類似 ZJ-d796 的方式
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1024;
int BIT[MAXN+1][MAXN+1];
int N, act, lx, ly, rx, ry;

inline int lowbit(int x){ return x&-x; }
inline int getSum(int x,int y,int out=0){
  for(int i=x;i;i-=lowbit(i))
    for(int j=y;j;j-=lowbit(j))
      out+=BIT[i][j];
  return out;
}
int main(){
  scanf("%d",&N);
  while(scanf("%d",&act)!=EOF){
    scanf("%d %d %d",&lx,&ly,&rx);
    if(act==1){ //單點更新
      for(int i=lx+1;i<=N;i+=lowbit(i))
        for(int j=ly+1;j<=N;j+=lowbit(j))
          BIT[i][j]+=rx;
    }else{
      scanf("%d",&ry),
      printf("%d\n",getSum(rx+1,ry+1)+getSum(lx,ly)-getSum(rx+1,ly)-getSum(lx,ry+1));
    }
  }
}
/*
4
1 1 2 3
2 0 0 2 2
1 1 1 2
1 1 2 -1
2 1 1 2 3
*/