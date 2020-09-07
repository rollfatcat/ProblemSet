/* 初階前綴和練習題 */
#include<bits/stdc++.h>
using namespace std;

int MAXN=2e5;
int main(){
    int N, x;
    long sum=0;
    scanf("%d\n%ld",&N,&sum);
    printf("%ld",sum);

    for(int i=1;i<N;i++)
        scanf("%d",&x), sum+=x,
        printf(" %ld",sum);
    puts("");
}