#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int n;

  printf("PERFECTION OUTPUT\n");
  while(scanf("%d",&n) and n){
    printf("%5d  ",n);
    int sum=(n==1)?0:1;
    for(int i=2;i<sqrt(n);i++)
      if(n%i==0)
        sum+=(i+n/i);

    if(sum>n) printf("ABUNDANT\n");
    else if(sum==n) printf("PERFECT\n");
    else printf("DEFICIENT\n");
  }
  printf("END OF OUTPUT\n");
}