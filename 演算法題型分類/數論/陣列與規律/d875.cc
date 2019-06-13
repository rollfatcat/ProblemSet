// 觀察規律
#include<bits/stdc++.h>
using namespace std;

int main(){
  int L, N, M;
  while(scanf("%d",&L)!=EOF){
    N=sqrt(L),
    M=L-N*N;
    // 前端部分根據情況處理：抓出哪個數字重複
    if(M>=N){
      M-=N;
      for(int i=1;i<=M;i++)
        printf(" %d",i);
      if(M) printf(" %d",M);
      for(int i=M+1;i<=N;i++)
        printf(" %d",i);
    }else{
      for(int i=1;i<=M;i++)
        printf(" %d",i);
      if(M) printf(" %d",M);
      for(int i=M+1;i<N;i++)
        printf(" %d",i);
    }
    // 輸出尾端部分
    for(int i=N;i;i--)
      printf(" %d",i);
    puts("");
  }
}

/*
 1 = 1
 2 = 1 1
 3 = 1 1 1
 4 = 1 2 1
 5 = 1 1 2 1
 6 = 1 2 2 1
 7 = 1 1 2 2 1
 8 = 1 2 2 2 1
 9 = 1 2 3 2 1
10 = 1 1 2 3 2 1
11 = 1 2 2 3 2 1
12 = 1 2 3 3 2 1
13 = 1 1 2 3 3 2 1
14 = 1 2 2 3 3 2 1
15 = 1 2 3 3 3 2 1
16 = 1 2 3 4 3 2 1
*/