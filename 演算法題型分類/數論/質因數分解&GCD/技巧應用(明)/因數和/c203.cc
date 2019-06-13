#include<bits/stdc++.h>
using namespace std;

int prime[11]={2,3,5,7,11,13,17,19,23,29,31};
int main(){
  int caseT, N;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d",&N);
    int sum=1, num=N;
    for(int p,i=0;i<=10 and num>1;i++){
      for(p=0;num%prime[i]==0;p++,num/=prime[i]);
      if(p){
        sum*=(pow(prime[i],p+1)-1)/(prime[i]-1);
      }
    }
    if(num>1){ sum*=num*num/(num-1); }

    if((N<<1)==sum) puts("perfect");
    else if((N<<1)>sum) puts("deficient");
    else puts("abundant");
  }
}