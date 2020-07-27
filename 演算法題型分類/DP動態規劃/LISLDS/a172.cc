/*
 */
#include<bits/stdc++.h>
using namespace std;
const int MaxN=5e2;
int num[MaxN];
int vec[MaxN];

int main(){
	int N, vecL;
  while(scanf("%d\n",&N)!=EOF){
	  for(int i=0;i<N;i++)
	  	scanf("%d",&num[i]);
	  vec[0]=num[N-1], vecL=1;
	  for(int i=N-2;i>=0;i--)
	  	( num[i]>=vec[vecL-1] )? vec[vecL++]=num[i]: *upper_bound(vec,vec+vecL,num[i])=num[i];
	  printf("%d\n",vecL);
	}
}