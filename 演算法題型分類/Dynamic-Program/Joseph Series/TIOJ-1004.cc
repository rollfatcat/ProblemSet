#include<bits/stdc++.h>
using namespace std;

int num[51]={};
int main(){
  for(int n=1;n<=50;num[n++]++)
    for(int t=1;t<=n;t++)
      num[n]=(num[n]+2)%t;
  for(int n;scanf("%d",&n)!=EOF;)
    printf("%d\n",num[n]);
}