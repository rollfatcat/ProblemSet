
#include<iostream>
using namespace std;

int main(){
  int N, M;
  while(scanf("%d%d",&N,&M)==2)
    printf("%d\n",N/M+(bool)(N%M));
}