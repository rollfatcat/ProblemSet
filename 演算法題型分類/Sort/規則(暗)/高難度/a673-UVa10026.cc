// 題目要求『最小化罰金』=>單日罰金越高的和工作天數越多的排序越前面
// 兩者比重一樣重要所以兩倆比較時取相乘後值高的往前排
// 概念類似於 APCS 20171028-P4的排序方式
#include<bits/stdc++.h>
using namespace std;

struct DATA{
  int idx, day, val;
  bool operator<(const DATA &rhs)const{
    int t1=day*rhs.val, t2=rhs.day*val;
    return (t1==t2)?(idx<rhs.idx):(t1<t2);
  }
}data[1001];
int main(){
  int caseT, N;
  scanf("%d",&caseT);
  for(int caseN=0;caseN<caseT;){
    if(caseN++) puts("");
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
      data[i].idx=i,
      scanf("%d %d",&data[i].day,&data[i].val);
    sort(data+1,data+N+1);
    for(int i=1;i<=N;i++)
      printf("%d ",data[i].idx);
    puts("");
  }
}
/*
2
4
3 4
1 1000
2 2
5 5
5
3 4
1 1000
8 8
2 2
5 6
*/