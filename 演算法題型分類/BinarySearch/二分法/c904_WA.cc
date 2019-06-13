#include<bits/stdc++.h>
using namespace std;

struct ITEM{
  int w, v;
  double d;
  bool operator<(const ITEM &rhs)const{ return(d==rhs.d)?(w<rhs.w):(d>rhs.d); }
}item[1000];
int main(){
  int N, Q, K;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++)
    scanf("%d",&item[i].w),
    scanf("%d",&item[i].v),
    item[i].d=(double)item[i].v/item[i].w;
  sort(item,item+N);
  while(Q--){
    scanf("%d",&K);
    int sumv=0, sumw=0;
    for(int i=0;i<K;i++)
      sumw+=item[i].w,
      sumv+=item[i].v;
    printf("%.2lf\n",(double)sumv/sumw);
  }
}
/*
3 2
2 2
5 3
2 1
====
0.75  = (1+2)/(2+2)
0.714 = (3+2)/(5+2)
*/