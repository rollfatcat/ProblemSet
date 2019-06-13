// 順向求LIS，逆向求LDS。Ｎ小於等於100，可以用N^2方式求解
#include<bits/stdc++.h>
using namespace std;

int LDS[100];
int LIS[100];
int num[100];
int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d",&num[i]);
  for(int i=0;i<N;i++)
    for(int j=0;j<i;j++)
      if(num[j]<num[i])
        LIS[i]=max(LIS[i],LIS[j]+1);
  for(int i=N-1;i>=0;i--)
    for(int j=N-1;j>i;j--)
      if(num[j]<num[i])
        LDS[i]=max(LDS[i],LDS[j]+1);
  int maxL=0;
  for(int i=0;i<N;i++)
    maxL=max(maxL,LIS[i]+LDS[i]+1);
  printf("%d\n",N-maxL);
}
/*
8
186 186 150 200 160 130 197 220
*/