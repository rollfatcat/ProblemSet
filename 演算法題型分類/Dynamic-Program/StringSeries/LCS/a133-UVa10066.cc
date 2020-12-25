#include<bits/stdc++.h>
using namespace std;

const int MaxN=100+1;
int dpv[MaxN][MaxN]={};
int org[2][MaxN];

int main(){
	int caseI=1, A, B;
  while(scanf("%d %d\n",&A,&B)!=EOF and A){
    for(int i=1;i<=A;i++) 
    	scanf("%d",&org[0][i]);
    for(int i=1;i<=B;i++) 
    	scanf("%d",&org[1][i]);
    for(int i=1;i<=A;i++)
      for(int j=1;j<=B;j++)
        dpv[i][j]=(org[0][i]==org[1][j])? dpv[i-1][j-1]+1:max(dpv[i-1][j],dpv[i][j-1]);
    printf("Twin Towers #%d\nNumber of Tiles : %d\n",caseI++,dpv[A][B]);
  }
}