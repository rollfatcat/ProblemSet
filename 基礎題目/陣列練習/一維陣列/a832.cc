// 陣列練習：以Ｎ為一組往左shift一格

#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001

short number[MAXN];
int main(){
  int N, base, tmp_number;
  scanf("%d",&N);
  for(int i=1;i<=N;i++)
    number[i-1]=i;
  for(int member=2; member<=N; member++){
    for(int cluster=0; cluster<N/member; cluster++){
      base=cluster*member;
      tmp_number=number[base];
      for(int idx=1;idx<member;idx++)
        number[base+idx-1]=number[base+idx];
      number[base+member-1]=tmp_number;
    }
    if(N%member){
      base=N/member*member;
      tmp_number=number[base];
      for(int idx=base+1;idx<N;idx++)
        number[idx-1]=number[idx];
      number[N-1]=tmp_number;
    }
  }
  for(int i=0;i<N;i++)
    printf("%d ",number[i]);
  puts("");
}
/*
1 2 3 4 5
2 1 4 3 5
1 4 2 5 3
4 2 5 1 3
2 5 1 3 4
*/