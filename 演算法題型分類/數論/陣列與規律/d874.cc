// 觀察規律，完成後接著挑戰 d875
#include<bits/stdc++.h>
using namespace std;

int L[20005]={0,1,2,3,3,4,4};
int main(){
  // init
  int w=3, Nnow=4;
  for(int cnt=6;cnt<=20000;w++){
    Nnow++;
    for(int i=1;i<=w;i++)
      L[++cnt]=Nnow;
    if(cnt>20000) break;
    Nnow++;
    for(int i=1;i<=w;i++)
      L[++cnt]=Nnow;
  }
  //
  int N;
  while(scanf("%d",&N)!=EOF)
    printf("%d\n",L[N]);
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