#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
int num[MaxN];
int main(){
    int N, x;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&num[i]);
    for(int i=0;i<N;i++)
        scanf("%d",&x), num[i]=min(num[i],x);
    long sum=0;
    for(int i=0;i<N;i++)
      	scanf("%d",&x), sum+=min(num[i],x);
    printf("%ld\n",sum);   
}
/*
 3
 1 1 1
 2 2 2
 3 3 3
 
 2
 1 3
 4 2
 5 6
 */