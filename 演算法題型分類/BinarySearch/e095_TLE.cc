// 儲存方式類似 UVa12192，但可能是因為枚舉一個維度導致 66%(TLE)
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1600;
int diag[MAXN<<1][MAXN];
int didx[MAXN<<1]={};

int main(){

  int R, C, slash;
  scanf("%d",&R),
  scanf("%d",&C);
  for(int i=1;i<=R;i++)
    for(int j=1;j<=C;j++)
      scanf("%d",&diag[i-j+C][ didx[i-j+C]++ ]);
  int Q, target, tag, idx;
  scanf("%d",&Q);
  while(Q--){
    scanf("%d",&target);
    bool getit=0;
    for(idx=1;idx<R+C;idx++){
      tag=lower_bound(diag[idx],diag[idx]+didx[idx],target)-diag[idx],
      getit=target==diag[idx][tag];
      if(getit) break;
    }
    if(getit==0) puts("no");
    else{
      int minus=idx-C;
      if(minus<0) printf("yes [%d, %d]\n",tag+1,tag+1-minus);
      else        printf("yes [%d, %d]\n",minus+tag+1,tag+1);
    }
  }
}

/*
2 4
 1  2  3   4
10 12 20 100
*/