#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b; // 0 ≤ n, a, b ≤ 1e6
    while(scanf("%d %d %d",&n,&a,&b)==3){
        if(n<=a){ puts("1"); continue; }
        if(b>=a){ puts("-1");continue; }
        printf("%d\n",(n-a)/(a-b)+1+((n-a)%(a-b)>0)); // 無法整除時需要多花一天
    }
}
/* 
 5 3 1 
 5 3 2 
 */