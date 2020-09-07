// 題目的目的是詢問範圍內質數的個數(前綴和)
#include<bits/stdc++.h>
using namespace std;

const int MAXN=10000001;
int Prime[MAXN];

int main(){
  fill(Prime,Prime+MAXN,1);
  int bound=sqrt(MAXN);
  // seive
  Prime[0]=Prime[1]=0;
  for(int i=2;(i<<1)<MAXN;i++)
    Prime[i<<1]=0;
  for(int i=3;i<bound;i+=2)
    if(Prime[i])
      for(int j=3;i*j<MAXN;j+=2)
        Prime[i*j]=0;
  for(int i=1;i<MAXN;i++)
    Prime[i]+=Prime[i-1];
  // Main Function
  int T, nL, nR;
  scanf("%d",&T);
  for(int caseN=0;caseN<T;caseN++){
    scanf("%d",&nL),
    scanf("%d",&nR);
    if(nL>nR) nL^=nR^=nL^=nR;
    printf("%d\n",Prime[nR]-Prime[nL-1]);
  }
}