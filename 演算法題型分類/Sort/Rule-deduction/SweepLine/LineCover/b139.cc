
#include<bits/stdc++.h>
using namespace std;

const int MAXN=10001;
bool hasTree[MAXN]={};
int main(){
  int maxL, N;
  int nL, nR;

  scanf("%d %d",&maxL,&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&nL,&nR);
    for(int j=nL;j<=nR;j++)
      hasTree[j]=1;
  }
  int cnt=0;
  for(int i=0;i<=maxL;i++)
    if(hasTree[i]==0)
      cnt++;
  printf("%d\n",cnt);
}