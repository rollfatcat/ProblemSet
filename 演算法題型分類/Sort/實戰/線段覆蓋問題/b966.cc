#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000
struct LINE{
  int st, ed;
  bool operator<(const LINE &rhs)const{ return (st==rhs.st)?(ed<rhs.ed):(st<rhs.st); }
} lines[MAXN];

int main(){
  int N;
  while(scanf("%d",&N)!=EOF){
    for(int i=0;i<N;i++)
      scanf("%d",&lines[i].st),
      scanf("%d",&lines[i].ed);
    sort(lines,lines+N);
    /* 初始化的起終點是第0個線段的左右端點
     * (1) 若現在的右端點(nowed)和現在線段的起點有重疊時，
     *     保留現在的右端點和現在線段的終點取最大值
     * (2) 若沒有重疊，則計算之前的線段長度，並更新現在左右端點的值(nowst/nowed)
     */
    int totL=0,
        nowst=lines[0].st,
        nowed=lines[0].ed;
    for(int i=1;i<N;i++){
      if(lines[i].st<=nowed)
        nowed=max(nowed,lines[i].ed);
      else
        totL+=nowed-nowst,
        nowst=lines[i].st,
        nowed=lines[i].ed;
    }
    totL+=nowed-nowst;
    printf("%d\n",totL);
  }
}