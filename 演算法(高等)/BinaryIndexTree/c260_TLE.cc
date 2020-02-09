// 可以通過20%的側資，其餘都是TLE
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100001;
long sumN[MAXN]={};
int main(){
  int N, x, Lbound, Ubound;
  scanf("%d",&N),
  scanf("%d",&Lbound),
  scanf("%d",&Ubound);
    long cnt=0;
    for(int i=1;i<=N;i++){
      scanf("%d",&x);
      sumN[i]=sumN[i-1]+x;
      if(x>=Lbound and x<=Ubound)
        cnt++;
    }
    for(int L=2;L<=N;L++){
      long Lcont=(long)Lbound*L, Ucont=(long)Ubound*L;
      for(int ed=L;ed<=N;ed++){
        long cont=sumN[ed]-sumN[ed-L];
        if(cont>=Lcont and cont<=Ucont)
          cnt++;
      }
    }
    printf("%ld\n",cnt);
}