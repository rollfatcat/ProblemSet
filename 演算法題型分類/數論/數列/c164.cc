// 連續平方和公式：n*(n+1)*(2*n+1)/6
#include<bits/stdc++.h>
using namespace std;

int main(){
  int day, n, r;
  scanf("%d",&day);
  n=sqrt(day<<1);
  r=day-n*(n+1)/2;
  if(r<0) r+=n--; //<- 調整r和n
  printf("%d\n",n*(n+1)*(2*n+1)/6+r*(n+1));
}
// 5 -> 11